#ifndef INCLUDE_ALGORITHMS_THREE_WAY_QUICK_SORT_H_
#define INCLUDE_ALGORITHMS_THREE_WAY_QUICK_SORT_H_
#include <stddef.h>
#include <vector>
#include <functional>
#include <limits>
#include "sort_interface.h"
#include "shuffle.h"

/*
This class implements sorting of elements using 3way quick sort algorithm
The time complexity to sort is N log N, which is optimal.
Regular Hoar's quick sort performs quadratic when there are lot of duplicates present whereas,
this 3way quick sort algorithm guarantees N log N even in the presense of duplicates.

quick sort algorithm is not stable since it does large distance swaps and 
shuffles the elements randomly to begin with.
*/

namespace algorithms {
  template <typename _tp>
  class ThreeWayQuickSort : public SortInterface<_tp> {
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

        size_t lt = lo, gt = hi, i = lo;

        while(i <= gt){
          if(comparer(elements[i], elements[lt])) {
            std::swap(elements[lt], elements[i]);
            if(lt != std::numeric_limits<size_t>::max())
              ++lt;
            if(i != std::numeric_limits<size_t>::max())
              ++i;
          }
          else
          if(comparer(elements[lt], elements[i])) {
            std::swap(elements[i], elements[gt]);
            if(gt != 0)
              --gt;;
          }
          else{
            if(i != std::numeric_limits<size_t>::max())
              ++i;
          }
        }

        Sort(elements, lo, lt == 0 ? lt : lt - 1, comparer);
        Sort(elements, gt == std::numeric_limits<size_t>::max() ? gt : gt + 1, hi, comparer);
      }
  };
}

#endif //INCLUDE_ALGORITHMS_THREE_WAY_QUICK_SORT_H_
