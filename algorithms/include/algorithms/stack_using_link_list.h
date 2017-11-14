#ifndef INCLUDE_ALGORITHMS_STACK_USING_LINK_LIST_H_
#define INCLUDE_ALGORITHMS_STACK_USING_LINK_LIST_H_
#include "stack_interface.h"
#include <memory>
#include <stdexcept>
#include "singly_link_list.h"

/*
This class is an implementation of Stack data structure using link list internally
*/

namespace algorithms {
  template<typename _tp>
  class StackUsingLinkList : public StackInterface<_tp> {
  public:
    typedef _tp value_type;

    // StackInterface methods
    void Push(const value_type& val) {
      data_.Push_Front(val);
      ++size_;
    }

    void Pop() {
      if(Empty())
        throw std::underflow_error("Trying to pop an element from an empty stack");

      data_.Pop_Front();
      --size_;
    }

    value_type& Top() {
      if(Empty())
        throw std::underflow_error("Trying to access top element from an empty stack");
      
      return data_.Front();
    }

    const value_type& Top() const {
      if(Empty())
        throw std::underflow_error("Trying to access top element from an empty stack");

      return data_.Front();
    }

    size_t Size() const {
        return size_;
    }

    bool Empty() const {
        return size_ == 0;
    }

  private:
    SinglyLinkList<value_type> data_;
    size_t size_{0};
  };
}

#endif //INCLUDE_ALGORITHMS_STACK_USING_LINK_LIST_H_
