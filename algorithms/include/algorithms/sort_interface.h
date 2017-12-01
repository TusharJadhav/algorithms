#ifndef INCLUDE_ALGORITHMS_SORT_INTERFACE_H_
#define INCLUDE_ALGORITHMS_SORT_INTERFACE_H_
#include <stddef.h>
#include <vector>
#include <functional>

/*
This pure abstract class represent an interface that all sorting algorithm classes must implement
*/

namespace algorithms {
  template <typename _tp>
  class SortInterface {
    public:
      typedef _tp value_type;

      void Sort(std::vector<value_type>& elements, std::function<bool(const value_type&, const value_type&)> = std::less<value_type>());
  };
}

#endif //INCLUDE_ALGORITHMS_SORT_INTERFACE_H_
