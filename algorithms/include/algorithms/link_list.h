#ifndef INCLUDE_ALGORITHMS_LINK_LIST_H_
#define INCLUDE_ALGORITHMS_LINK_LIST_H_
#include "DLLDefines.h"
#include <memory>
#include <stdexcept>

/* This algorithm implements a traditional singly link list data structure, with the ability to
push and pop elements from the front of the list. Additonally underflow errors have been dealt
by throwing exception when popping from an empty list or accessing front element from an empty
list
*/

namespace algorithms {
  template<typename _tp>
  class LinkList {
  public:
    typedef _tp value_type;

    MYLIB_EXPORT void Push_Front(const value_type& val) {
      auto node = std::make_unique<Node>(val, std::move(root_));
      root_ =  std::move(node);
    }

    MYLIB_EXPORT void Pop_Front() {
      if(root_ == nullptr)
        throw std::underflow_error("Popping element from an empty link list");

      auto oldRoot = std::move(root_);
      root_ = oldRoot->next_ ? std::move(oldRoot->next_) : nullptr;
      oldRoot.release();
    }

    MYLIB_EXPORT value_type& Front() {
      if(!root_)
        throw std::underflow_error("Trying to access front  element from an empty link list");

      return root_->data_;
    }

    MYLIB_EXPORT const value_type& Front() const {
      if(root_)
        throw std::underflow_error("Trying to access front  element from an empty link list");

      return root_->data_;
    }

    MYLIB_EXPORT bool Empty() const {
      return root_ == nullptr;
    }

  private:
    typedef struct tagNode {
      value_type data_;
      std::unique_ptr<tagNode> next_;

      tagNode(const value_type& data, std::unique_ptr<tagNode> next) :
        data_{data},
        next_{std::move(next)}
      {}
    } Node;

    std::unique_ptr<Node> root_;
  };
}

#endif //INCLUDE_ALGORITHMS_LINK_LIST_H_
