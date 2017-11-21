#ifndef INCLUDE_ALGORITHMS_QUEUE_USING_LINK_LIST_H_
#define INCLUDE_ALGORITHMS_QUEUE_USING_LINK_LIST_H_
#include "queue_interface.h"
#include <memory>
#include <stdexcept>
#include "doubly_link_list.h"

/*
This class is an implementation of Queue data structure using link list internally
*/

namespace algorithms {
  template<typename _tp>
  class QueueUsingLinkList : public QueueInterface<_tp> {
  public:
    typedef _tp value_type;

    // QueueInterface methods
    void Enque(const value_type& val) {
      data_.Push_Back(val);
      ++size_;
    }

    void Deque() {
      if(Empty())
        throw std::underflow_error("Trying to deque an element from an empty queue");

      data_.Pop_Front();
      --size_;
    }

    value_type& Front() {
      if(Empty())
        throw std::underflow_error("Trying to access front element from an empty stack");

      return data_.Front();
    }

    const value_type& Front() const {
      if(Empty())
        throw std::underflow_error("Trying to access front element from an empty stack");

      return data_.Front();
    }

    value_type& Back() {
      if(Empty())
        throw std::underflow_error("Trying to access back element from an empty stack");

      return data_.Back();
    }

    const value_type& Back() const {
      if(Empty())
        throw std::underflow_error("Trying to access back element from an empty stack");

      return data_.Back();
    }

    size_t Size() const {
      return size_;
    }

    bool Empty() const {
      return size_ == 0;
    }

  private:
    DoublyLinkList<value_type> data_;
    size_t size_{0};
  };
}

#endif //INCLUDE_ALGORITHMS_STACK_USING_LINK_LIST_H_
