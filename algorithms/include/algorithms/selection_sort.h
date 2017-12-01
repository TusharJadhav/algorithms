#ifndef INCLUDE_ALGORITHMS_SELECTION_SORT_H_
#define INCLUDE_ALGORITHMS_SELECTION_SORT_H_
#include <stddef.h>
#include <vector>
#include <functional>
#include "sort_interface.h"

/*
This class implements sorting of elements using selection sort algorithm
The time complexity to sort is quadratic (N2/4) and is insensitive to input, which
mean that the algorithm will take quadratic time even if the input is sorted.

However the data movement is minimal. The algorithm does linear number of swaps
to sort the elements. Each element is moved into its final position once.
*/

namespace algorithms {
  template <typename _tp>
  class SelectionSort : public SortInterface<_tp> {
    public:
      typedef _tp value_type;

      static void Sort(std::vector<value_type>& elements, std::function<bool(const value_type&, const value_type&)> comparer = std::less<value_type>()) {
        for (size_t index = 0; index < elements.size(); ++index) {
          auto min = index;

          for (size_t cnt = index + 1; cnt < elements.size(); ++cnt) {
            if (comparer(elements[cnt], elements[min]))
              min = cnt;
          }

          std::swap(elements[min], elements[index]);
        }
      }
  };
}

#endif //INCLUDE_ALGORITHMS_SELECTION_SORT_H_
