#ifndef INCLUDE_ALGORITHMS_SHUFFLE_H_
#define INCLUDE_ALGORITHMS_SHUFFLE_H_
#include <stddef.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>

/*
This class shuffles an input vector using Donald Knuths shuffling algorithm in linear time 
*/

namespace algorithms {
  template <typename _tp>
  class Shuffle {
    public:
      typedef _tp value_type;

      static void ShuffleElements(std::vector<value_type>& elements) {
        srand(static_cast<unsigned int>(time(NULL)));

        for(size_t index = 0; index < elements.size(); ++index) {
          auto random_index = (rand() % elements.size());
          std::swap(elements[random_index], elements[index]);
        }
      }
  };
}

#endif //INCLUDE_ALGORITHMS_SHUFFLE_H_
