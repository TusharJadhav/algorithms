#ifndef INCLUDE_ALGORITHMS_QUICK_UNION_WITH_PATH_COMPRESSION_H_
#define INCLUDE_ALGORITHMS_QUICK_UNION_WITH_PATH_COMPRESSION_H_

#include <vector>
#include <stddef.h>

/*
This algorithm "Quick Union With Path Compression" solves the dynamic connectivity problem.
Starting from an empty data structure, any sequence of M union-find ops on N objects makes ≤ c ( N + M lg* N ) array accesses.
In reality log * function can be considered to be at the most 5.
Thus in theory, this algorithm is not quite linear but in practice it is.
*/

namespace algorithms {
  class QuickUnionWithPathCompression {
    public:
      QuickUnionWithPathCompression(size_t no_of_elements);
      ~QuickUnionWithPathCompression() = default;

      void Union(size_t elementA, size_t elementB);
      bool Connected(size_t elementA, size_t elementB);

    private:
      size_t GetRoot(size_t element);

      inline bool IsIdInBounds(size_t element) {
        return element >= 0 && element < id_.size();
      }

    private:
      std::vector<size_t> id_;
      std::vector<size_t> size_;
  };
}

#endif //INCLUDE_ALGORITHMS_QUICK_UNION_WITH_PATH_COMPRESSION_H_
