#ifndef INCLUDE_ALGORITHMS_STACK_INTERFACE_H_
#define INCLUDE_ALGORITHMS_STACK_INTERFACE_H_
#include <stddef.h>

/*
This pure abstract class represent an interface for traditional stack.
All stack implementations must implement this interface.
*/

namespace algorithms {
  template <typename _tp>
  class StackInterface {
    public:
      typedef _tp value_type;
      virtual ~StackInterface() = default;

      virtual void Push(const value_type& val) = 0;
      virtual void Pop() = 0;
      virtual value_type& Top() = 0;
      virtual const value_type& Top() const = 0;
      virtual size_t Size() const = 0;
      virtual bool Empty() const = 0;
  };
}

#endif //INCLUDE_ALGORITHMS_STACK_INTERFACE_H_

