#ifndef INCLUDE_ALGORITHMS_SHELL_SORT_H_
#define INCLUDE_ALGORITHMS_SHELL_SORT_H_
#include <stddef.h>
#include <vector>
#include <functional>
#include "sort_interface.h"

/*
This class implements sorting of elements using shell sort algorithm.
This shell sort algorithm uses increment sequence of 3x + 1 as proposed by Donald Knuth
i.e. 1, 4, 13, 40, 121, 364, ...
*/

namespace algorithms {
  template <typename _tp>
  class ShellSort : public SortInterface<_tp> {
    public:
      typedef _tp value_type;

      static void Sort(std::vector<value_type>& elements, std::function<bool(const value_type&, const value_type&)> comparer = std::less<value_type>()) {
        size_t size = elements.size();

        size_t h = 1;
        while(h < size / 3) {
          h = 3 * h + 1;
        }

        while(h >= 1){
          for(size_t i = h; i < size; ++i){
            for(size_t j = i; j >= h && comparer(elements[j], elements[j - h]); j -= h)
              std::swap(elements[j], elements[j  - h]);
          }

          h = h / 3;
        }
      }
  };
}

#endif //INCLUDE_ALGORITHMS_SHELL_SORT_H_
