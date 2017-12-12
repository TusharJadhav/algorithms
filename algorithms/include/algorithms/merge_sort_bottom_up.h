#ifndef INCLUDE_ALGORITHMS_MERGE_SORT_BOTTOM_UP_H_
#define INCLUDE_ALGORITHMS_MERGE_SORT_BOTTOM_UP_H_
#include <stddef.h>
#include <vector>
#include <functional>
#include <algorithm>
#include "sort_interface.h"
#include "insertion_sort.h"

/*
This class implements sorting of elements using botttom up merge sort algorithm
The time complexity to sort is N log N, which is optimal, however, 
the algorithm requires an auxillary array equal to the size of elements
to be sorted.
Specifically merge sort uses N log N compares and 6 N log N array accesses
to sort an array of size N.

bottom up merge sort algorithm is not stable since it does large distance swaps.
*/

namespace algorithms {
  template <typename _tp>
  class MergeSortBottomUp : public SortInterface<_tp> {
    public:
      typedef _tp value_type;

      static void Sort(std::vector<value_type>& elements, std::function<bool(const value_type&, const value_type&)> comparer = std::less<value_type>()) {
        size_t size = elements.size();
        std::vector<value_type> aux(size);

        for(size_t sz = 1; sz < size; sz = sz + sz) {
          for(size_t lo = 0; lo < size - sz; lo += sz + sz) {
            Merge(elements, aux, lo, lo + sz - 1, std::min(lo + sz + sz - 1, size - 1), comparer);
          }
        }
      }

    private:
      static void Merge(std::vector<value_type>& elements, std::vector<value_type>& aux, size_t lo, size_t mid, size_t hi, std::function<bool(const value_type&, const value_type&)> comparer = std::less<value_type>()) {
        std::copy(elements.cbegin() + lo, elements.cbegin() + hi + 1, aux.begin() + lo);

        size_t i = lo, j = mid + 1;
        for(size_t k = lo; k <= hi; k++) {
          if(i > mid) elements[k] = aux[j++];
          else if (j > hi) elements[k] = aux[i++];
          else if (comparer(aux[i], aux[j])) elements[k] = aux[i++];
          else elements[k] = aux[j++];
        }
      }
  };
}

#endif //INCLUDE_ALGORITHMS_MERGE_SORT_BOTTOM_UP_H_
