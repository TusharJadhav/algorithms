#ifndef INCLUDE_ALGORITHMS_MERGE_SORT_H_
#define INCLUDE_ALGORITHMS_MERGE_SORT_H_
#include <stddef.h>
#include <vector>
#include <functional>
#include <algorithm>
#include "sort_interface.h"
#include "insertion_sort.h"

/*
This class implements sorting of elements using merge sort algorithm
The time complexity to sort is N log N, which is optimal, however, 
the algorithm requires an auxillary array equal to the size of elements
to be sorted.
Specifically merge sort uses N log N compares and 6 N log N array accesses
to sort an array of size N.

merge sort algorithm is not stable since it does large distance swaps.
*/

namespace algorithms {
  template <typename _tp>
  class MergeSort : public SortInterface<_tp> {
    private:
     static const int CUTOFF = 7;

    public:
      typedef _tp value_type;

      static void Sort(std::vector<value_type>& elements, std::function<bool(const value_type&, const value_type&)> comparer = std::less<value_type>()) {
        std::vector<value_type> aux(elements.size());
        Sort(elements, aux, 0, elements.size() - 1, comparer);
      }

    private:
      static void Sort(std::vector<value_type>& elements, std::vector<value_type>& aux, size_t lo, size_t hi, std::function<bool(const value_type&, const value_type&)> comparer = std::less<value_type>()) {
        if(hi <= lo + CUTOFF - 1){
          InsertionSort<value_type>::Sort(elements, comparer);
          return;
        }
        
        size_t mid = lo + ((hi - lo) / 2);
        Sort(elements, aux, lo, mid, comparer);
        Sort(elements, aux, mid + 1, hi, comparer);
        if(comparer(elements[mid], elements[mid + 1]))
          return;
        Merge(elements, aux, lo, mid, hi, comparer);
      }

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

#endif //INCLUDE_ALGORITHMS_MERGE_SORT_H_
