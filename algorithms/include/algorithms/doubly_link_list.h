#ifndef INCLUDE_ALGORITHMS_LINK_LIST_H_
#define INCLUDE_ALGORITHMS_LINK_LIST_H_
#include <memory>
#include <stdexcept>

/* This algorithm implements a traditional doubly link list data structure, with the ability to
push and pop elements from the front and back of the list. Additonally underflow errors have been dealt with,
by throwing an exception when popping from an empty list or accessing front/back element from an empty list
*/

namespace algorithms {
  template<typename _tp>
  class DoublyLinkList {
  public:
    typedef _tp value_type;

    void Push_Front(const value_type& val) {
      auto node = std::make_shared<Node>(val, nullptr, front_);
      if(front_)
        front_->prev_ = node;
      front_ = node;
      if(back_ == nullptr && front_->next_ == nullptr)
        back_ = front_;
    }

    void Pop_Front() {
      if(front_ == nullptr)
        throw std::underflow_error("Popping element from an empty link list");

      auto oldFront = front_;
      front_ = oldFront->next_;
      
      if(front_)
        front_->prev_ = nullptr;

      Delete_Node(oldFront);

      if(front_ == nullptr)
        back_ = nullptr;
    }

    value_type& Front() {
      if(!front_)
        throw std::underflow_error("Trying to access front element from an empty link list");

      return front_->data_;
    }

    const value_type& Front() const {
      if(!front_)
       throw std::underflow_error("Trying to access front element from an empty link list");

      return front_->data_;
    }

    bool Empty() const {
      return front_ == nullptr;
    }

    void Push_Back(const value_type& val) {
      auto node = std::make_shared<Node>(val, back_, nullptr);
      if(back_)
        back_->next_ = node;
      back_ = node;
      if(front_ == nullptr && back_->prev_ == nullptr)
        front_ = back_;
    }


    void Pop_Back() {
      if(back_ == nullptr)
        throw std::underflow_error("Popping element from an empty link list");

      auto oldBack = back_;
      back_ = oldBack->prev_;
      if(back_)
        back_->next_ = nullptr;

      Delete_Node(oldBack);
      
      if(back_ == nullptr)
        front_ = nullptr;
    }

    value_type& Back() {
      if(!back_)
        throw std::underflow_error("Trying to access back element from an empty link list");

      return back_->data_;
    }

    const value_type& Back() const {
      if(!back_)
        throw std::underflow_error("Trying to access back element from an empty link list");

      return back_->data_;
    }


  private:
    typedef struct tagNode {
      value_type data_;
      std::shared_ptr<tagNode> prev_;
      std::shared_ptr<tagNode> next_;

      tagNode(const value_type& data, std::shared_ptr<tagNode> prev, std::shared_ptr<tagNode> next) :
        data_{data},
        prev_{prev},
        next_{next}
      {}
    } Node;

    std::shared_ptr<Node> front_;
    std::shared_ptr<Node> back_;

  private:
    void Delete_Node(std::shared_ptr<Node>& node) {
      if(node) {
        node->prev_ = nullptr;
        node->next_ = nullptr;
      }
      node = nullptr;
    }
  };
}

#endif //INCLUDE_ALGORITHMS_LINK_LIST_H_
