#ifndef INCLUDE_ALGORITHMS_HEAP_SORT_H_
#define INCLUDE_ALGORITHMS_HEAP_SORT_H_
#include <stddef.h>
#include <vector>
#include <functional>
#include <iostream>
#include "sort_interface.h"

/*
This class implements sorting of elements using heap sort algorithm.
Time complexity to sort a vector of N elements is N log N.
*/

namespace algorithms {
  template <typename _tp>
  class HeapSort : public SortInterface<_tp> {
    public:
      typedef _tp value_type;

      static void Sort(std::vector<value_type>& elements, std::function<bool(const value_type&, const value_type&)> comparer = std::less<value_type>()) {
        size_t N = elements.size();
        for(size_t k = N / 2; k >= 1; --k) {
          Sink(elements, k, N, comparer);
        }

        while(N > 1) {
          Exch(elements, 1, N);
          Sink(elements, 1, --N, comparer);
        }
    }

    private:
      static void Sink(std::vector<value_type>& elements, size_t k, size_t N, std::function<bool(const value_type&, const
      value_type&)> comparer) {
        if(k >= N)
          return;
          
        size_t child_index = 2 * k;

        while(child_index <= N){
          if(child_index < N && Compare(elements, child_index, child_index + 1, comparer))
            ++child_index;

          if(!Compare(elements, k, child_index, comparer))
            break;

          Exch(elements, child_index, k);

          k = child_index;
          child_index = 2 * k;
        }
      }

      static void Exch(std::vector<value_type>& elements, size_t index1, size_t index2) {
        std::swap(elements[index1 - 1], elements[index2 - 1]);
      }

      static bool Compare(const std::vector<value_type>& elements, size_t index1, size_t index2,
      std::function<bool(const value_type&, const value_type&)> compare) {
        return compare(elements[index1 - 1], elements[index2 - 1]);
      }
  };
}

#endif //INCLUDE_ALGORITHMS_HEAP_SORT_H_
