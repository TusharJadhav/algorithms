#ifndef INCLUDE_ALGORITHMS_STACK_USING_RESIZING_ARRAY_H_
#define INCLUDE_ALGORITHMS_STACK_USING_RESIZING_ARRAY_H_
#include "stack_interface.h"
#include <memory>
#include <utility>
#include <stdexcept>

/*
This class implements stack data structure using resizing array internally
*/

namespace algorithms {
  template<typename _tp>
  class StackUsingResizingArray : public StackInterface<_tp> {
  public:
    typedef _tp value_type;

    // StackInterface methods
    void Push(const value_type& val) {
      if(size_ == capacity_)
        resize(capacity_ * 2);

      data_[size_++] = val;
    }

    void Pop() {
      if(Empty())
        throw std::underflow_error("Trying to pop element from an empty stack");

      --size_;
      // Todo: How do we make sure that the destructor of the element being popped is called? 
      if(size_ == capacity_ / 4)
        resize(capacity_ / 2);
    }

    value_type& Top() {
      if(Empty())
        throw std::underflow_error("Trying to top element from an empty stack");

      return data_[size_ - 1];
    }

    const value_type& Top() const {
      if(Empty())
        throw std::underflow_error("Trying to top element from an empty stack");

      return data_[size_ - 1];
    }

    size_t Size() const {
        return size_;
    }

    bool Empty() const {
        return size_ == 0;
    }

  private:
    void resize(size_t size) {
      auto new_data = std::make_unique<value_type[]>(size);
      
      for(size_t index = 0; index < size_; ++index) {
        new_data[index] = data_[index];
      }

      data_.reset(nullptr);
      data_ = std::move(new_data);
      capacity_ = size;
    }

  private:
    const size_t initial_size_{2};
    std::unique_ptr<value_type[]> data_{std::make_unique<value_type[]>(initial_size_)};
    size_t capacity_{initial_size_};
    size_t size_{0};
  };
}

#endif //INCLUDE_ALGORITHMS_STACK_USING_LINK_LIST_H_ 
