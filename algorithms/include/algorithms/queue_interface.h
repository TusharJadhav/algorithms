#ifndef INCLUDE_ALGORITHMS_QUEUE_INTERFACE_H_
#define INCLUDE_ALGORITHMS_QUEUE_INTERFACE_H_
#include <stddef.h>

/*
This pure abstract class represent an interface for traditional queue.
All queue implementations must implement this interface.
*/

namespace algorithms {
  template <typename _tp>
  class QueueInterface {
    public:
      typedef _tp value_type;

      virtual void Enque(const value_type& val) = 0;
      virtual void Deque() = 0;
      virtual value_type& Front() = 0;
      virtual const value_type& Front() const = 0;
      virtual value_type& Back() = 0;
      virtual const value_type& Back() const = 0;
      virtual size_t Size() const = 0;
      virtual bool Empty() const = 0;
  };
}

#endif //INCLUDE_ALGORITHMS_QUEUE_INTERFACE_H_

