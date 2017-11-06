#ifndef INCLUDE_ALGORITHMS_STACK_INTERFACE_H_
#define INCLUDE_ALGORITHMS_STACK_INTERFACE_H_
#include <stddef.h>

/*
This algorithm "Quick Union With Path Compression" solves the dynamic connectivity problem.
Starting from an empty data structure, any sequence of M union-find ops on N objects makes ≤ c ( N + M lg* N ) array accesses.
In reality log * function can be considered to be at the most 5.
Thus in theory, this algorithm is not quite linear but in practice it is.
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

