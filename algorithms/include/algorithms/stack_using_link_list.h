#ifndef INCLUDE_ALGORITHMS_STACK_USING_LINK_LIST_H_
#define INCLUDE_ALGORITHMS_STACK_USING_LINK_LIST_H_
#include "stack_interface.h"
#include <memory>
#include "link_list.h"

/*
This algorithm "Quick Union With Path Compression" solves the dynamic connectivity problem.
Starting from an empty data structure, any sequence of M union-find ops on N objects makes ≤ c ( N + M lg* N ) array accesses.
In reality log * function can be considered to be at the most 5.
Thus in theory, this algorithm is not quite linear but in practice it is.
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
      data_.Pop_Front();
      --size_;
    }

    value_type& Top() {
      data_.Front();
    }

    const value_type& Top() const {
      data_.Front();
    }

    size_t Size() const {
        return size_;
    }

    bool Empty() const {
        return size_ == 0;
    }

  private:
    LinkList<value_type> data_;
    size_t size_{0};
  };
}

#endif //INCLUDE_ALGORITHMS_STACK_USING_LINK_LIST_H_
