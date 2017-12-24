#ifndef INCLUDE_ALGORITHMS_PRIORITY_QUEUE_H_
#define INCLUDE_ALGORITHMS_PRIORITY_QUEUE_H_
#include <stddef.h>
#include <vector>
#include <functional>
#include <algorithm>

/*
This class implements Priority Queue implementation where insertion and deletion operations
are performed in logarithmic time
*/

namespace algorithms {
  template <typename _tp>
  class PriorityQueue {
    public:
      typedef _tp value_type;

     PriorityQueue(std::function<bool(const value_type&, const value_type&)> comparer) :
          comparer_{ comparer },
          elements_(1)
     {}

     void Insert(const value_type& value) {
       elements_.push_back(value);
       Swim(elements_.size() - 1);
     }

     value_type GetPriorityElement() {
       return elements_[1];
     }

     void Delete() {
       std::swap(elements_[1], elements_[elements_.size() - 1]);
       elements_.pop_back();
       Sink(1);
     }

     bool IsEmpty() {
       return elements_.size() == 1;
     }

    private:
      void Swim(size_t index) {
        while(index > 1) {
          size_t parent = index / 2;
          if(!comparer_(elements_[index], elements_[parent]))
            break;

          std::swap(elements_[index], elements_[parent]);
          index = parent;
        }
      }

      void Sink(size_t index) {
        while(index * 2 <= elements_.size() - 1) {
          size_t eligible_child = index * 2;

          if(eligible_child < elements_.size() - 1 && comparer_(elements_[eligible_child + 1], elements_[eligible_child]))
            ++eligible_child;

          if(!comparer_(elements_[eligible_child], elements_[index]))
            break;

          std::swap(elements_[index], elements_[eligible_child]);
          index = eligible_child;
        }
      }

    private:
     std::vector<value_type> elements_;
     std::function<bool(const value_type&, const value_type&)> comparer_;
  };
}

#endif //INCLUDE_ALGORITHMS_PRIORITY_QUEUE_H_
