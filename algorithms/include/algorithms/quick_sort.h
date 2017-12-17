#ifndef INCLUDE_ALGORITHMS_QUICK_SORT_H_
#define INCLUDE_ALGORITHMS_QUICK_SORT_H_
#include <stddef.h>
#include <vector>
#include <functional>
#include <limits>
#include "sort_interface.h"
#include "shuffle.h"

/*
This class implements sorting of elements using quick sort algorithm
The time complexity to sort is N log N, which is optimal.
Specifically merge sort uses N log N compares and 6 N log N array accesses
to sort an array of size N.

quick sort algorithm is not stable since it does large distance swaps and 
shuffles the elements randomly to begin with.
*/

namespace algorithms {
  template <typename _tp>
  class QuickSort : public SortInterface<_tp> {
    public:
      typedef _tp value_type;

      static void Sort(std::vector<value_type>& elements, std::function<bool(const value_type&, const value_type&)> comparer = std::less<value_type>()) {
        if(elements.size() == 1)
          return;

        Shuffle<value_type>::ShuffleElements(elements);
        Sort(elements, 0, elements.size() - 1, comparer);
      }

    private:
      static void Sort(std::vector<value_type>& elements, size_t lo, size_t hi, std::function<bool(const value_type&, const value_type&)> comparer) {
        if(hi <= lo)
          return;
        
        size_t j = Partition(elements, lo, hi, comparer);
        Sort(elements, lo, j == 0 ? j : j - 1, comparer);
        Sort(elements, j == std::numeric_limits<size_t>::max() ? j : j + 1, hi, comparer);
      }

      static size_t Partition(std::vector<value_type>& elements, size_t lo, size_t hi, std::function<bool(const value_type&, const value_type&)> comparer) {
        size_t i = lo, j = hi + 1;

        while(true){
          while(comparer(elements[++i], elements[lo]))
            if(i == hi) break;

          while(comparer(elements[lo], elements[--j]))
            if(j == lo) break;

          if(i >= j) break;

          std::swap(elements[i], elements[j]);
        }

        std::swap(elements[lo], elements[j]);
        return j;
      }
  };
}

#endif //INCLUDE_ALGORITHMS_QUICK_SORT_H_
