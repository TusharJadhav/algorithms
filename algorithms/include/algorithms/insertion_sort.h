#ifndef INCLUDE_ALGORITHMS_INSERTION_SORT_H_
#define INCLUDE_ALGORITHMS_INSERTION_SORT_H_
#include <stddef.h>
#include <vector>
#include <functional>
#include "sort_interface.h"

/*
This class implements sorting of elements using insertion sort algorithm
The time complexity to sort is quadratic, precisely N2/2 which means it is twice
as fast as selection sort which is N2/4.

However the data movement is not minimal unlike selection sort.
insertion sort does N2/2 exchanges in worst case.

Note: If the input is already sorted insertion sort does the job in linear time,
with just N-1 compares and 0 exchanges.
*/

namespace algorithms {
  template <typename _tp>
  class InsertionSort : public SortInterface<_tp> {
    public:
      typedef _tp value_type;

      static void Sort(std::vector<value_type>& elements, std::function<bool(const value_type&, const value_type&)> comparer = std::less<value_type>()) {
        for(size_t i = 0; i < elements.size(); ++i) {
          for(size_t j = i; j > 0; --j) {
            if(comparer(elements[j], elements[j-1]))
              std::swap(elements[j], elements[j-1]);
            else
              break;
          }
        }
      }
  };
}

#endif //INCLUDE_ALGORITHMS_INSERTION_SORT_H_
