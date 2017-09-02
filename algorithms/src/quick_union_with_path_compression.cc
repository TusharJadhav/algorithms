#include "quick_union_with_path_compression.h"

#include <stdexcept>

namespace algorithms {
  QuickUnionWithPathCompression::QuickUnionWithPathCompression(size_t no_of_elements)
  {
    id_.resize(no_of_elements);
    size_.resize(no_of_elements);
    size_t cnt = 0;
        
    for(auto& elem : id_) {
      elem = cnt++;
    }

    for(auto& elem : size_) {
      elem = 1;
    }
  }

  void QuickUnionWithPathCompression::Union(size_t elementA, size_t elementB) {
    if( !IsIdInBounds(elementA) || !IsIdInBounds(elementB) )
      throw std::invalid_argument("Parameters passed are out of bounds");

	  auto rootElementA = GetRoot(elementA);
	  auto rootElementB = GetRoot(elementB);

	  if(size_[rootElementA] < size_[rootElementB]){
		  id_[rootElementA] = rootElementB;
		  size_[rootElementB] += size_[rootElementA];
	  }
	  else {
		  id_[rootElementB] = rootElementA;
		  size_[rootElementA] += size_[rootElementB];
	  }
  }

  bool QuickUnionWithPathCompression::Connected(size_t elementA, size_t elementB) {
    if( !IsIdInBounds(elementA) || !IsIdInBounds(elementB) )
      throw std::invalid_argument("Parameters passed are out of bounds");
        
    return GetRoot(elementA) == GetRoot(elementB);
  }

  size_t QuickUnionWithPathCompression::GetRoot(size_t element) {
	while(id_[element] != element) {
		id_[element] = id_[id_[element]];
		element = id_[element];
	}

	return element;
  }
}
