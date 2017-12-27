#ifndef INCLUDE_ALGORITHMS_MIN_PRIORITY_QUEUE_H_
#define INCLUDE_ALGORITHMS_MIN_PRIORITY_QUEUE_H_
#include <stddef.h>
#include <vector>
#include <functional>
#include <algorithm>
#include "priority_queue.h"

/*
This class implements Minimum Priority Queue implementation where insertion and deletion operations
are performed in logarithmic time
*/

namespace algorithms {
  template <typename _tp>
  class MinPriorityQueue : PriorityQueue<_tp> { 
    public:
      typedef _tp value_type;

     MinPriorityQueue(std::function<bool(const value_type&, const value_type&)> comparer = std::less<value_type>()) :
          PriorityQueue<value_type>(comparer)
     {}


     MinPriorityQueue(const std::vector<value_type>& elements, std::function<bool(const value_type&, const value_type&)> comparer = std::less<value_type>()) :
          PriorityQueue<value_type>(comparer)
     {
       for(const auto& element : elements){
        PriorityQueue<value_type>::Insert(element);
       }
     }

     void Insert(const value_type& value) {
       PriorityQueue<value_type>::Insert(std::move(value));
     }

     value_type GetMin() {
       if(IsEmpty())
         throw "Trying to get minimum element from an empty priority queue";

       return PriorityQueue<value_type>::GetPriorityElement();
     }

     void DeleteMin() {
       if(IsEmpty())
         throw "Trying to delete an element from an empty priority queue";

       PriorityQueue<value_type>::Delete();
     }

     bool IsEmpty() {
       return PriorityQueue<value_type>::IsEmpty();
     }
  };
}

#endif //INCLUDE_ALGORITHMS_MIN_PRIORITY_QUEUE_H_
