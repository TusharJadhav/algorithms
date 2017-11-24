#ifndef INCLUDE_ALGORITHMS_QUEUE_USING_RESIZING_ARRAY_H_
#define INCLUDE_ALGORITHMS_QUEUE_USING_RESIZING_ARRAY_H_
#include "queue_interface.h"
#include <memory>
#include <stdexcept>

/*
This class is an implementation of Queue data structure using resizing array internally
*/

namespace algorithms {
  template<typename _tp>
  class QueueUsingResizingArray : public QueueInterface<_tp> {
  public:
    typedef _tp value_type;

    // QueueInterface methods
    void Enque(const value_type& val) {
      if(size_ == capacity_)
        Resize(capacity_ * 2);
    
      data_[end_] = val;
      
      if(start_ == -1)
        start_ = 0;
      
      Increment(&end_);
      ++size_;
    }

    void Deque() {
      if(Empty())
        throw std::underflow_error("Trying to deque an element from an empty queue");

      // Todo : Use allocators so that the object can be destroyed without deallocating the memory
      --size_;
      
      if(size_ == 0) {
        start_ = -1;
        end_ = 0;
      }
      else
        Increment(&start_);
      
      if(size_ <= capacity_ / 4)
        Resize(capacity_ / 4);
    }

    value_type& Front() {
      if(Empty())
        throw std::underflow_error("Trying to access front element from an empty stack");

      return data_[start_];
    }

    const value_type& Front() const {
      if(Empty())
        throw std::underflow_error("Trying to access front element from an empty stack");

      return data_[start_];
    }

    value_type& Back() {
      if(Empty())
        throw std::underflow_error("Trying to access back element from an empty stack");

      return data_[GetPreviousIndex(end_)];
    }

    const value_type& Back() const {
      if(Empty())
        throw std::underflow_error("Trying to access back element from an empty stack");

      return data_[GetPreviousIndex(end_)];
    }

    size_t Size() const {
      return static_cast<size_t>(size_);
    }

    bool Empty() const {
      return size_ == 0;
    }

  private:
    void Resize(size_t size) {
      if(size <= 2)
        return;

      auto new_data = std::make_unique<value_type[]>(size);
      
      for(long long index = start_, writer_index = 0; writer_index < size_; Increment(&index), ++writer_index) {
        new_data[writer_index] = data_[index];
      }

      data_.reset(nullptr);
      data_ = std::move(new_data);
      capacity_ = size;
      start_ = 0;
      end_ = size_;
    }

    void Increment(long long* index) {
      if(!index)
        return;

      if(*index == capacity_ - 1)
        (*index) = 0;
      else
        (*index) += 1;
    }

    long long GetPreviousIndex(long long index) const {
      if(index == 0)
        return capacity_ - 1;

      return index - 1;
    }

  private:
    const long long initial_size_{2};
    std::unique_ptr<value_type[]> data_{std::make_unique<value_type[]>(initial_size_)};
    long long capacity_{initial_size_};
    long long size_{0};
    long long start_{-1};
    long long end_{0};
  };
}

#endif //INCLUDE_ALGORITHMS_QUEUE_USING_RESIZING_ARRAY_H_
