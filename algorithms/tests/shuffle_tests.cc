#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "shuffle.h"
#include <vector>
#include <unordered_set>
#include <ctime>
#include <cstdlib>

using namespace testing;
using namespace algorithms;

TEST(StackUsingLinkListTests, TestShufflingOfIntegers) {
  std::vector<int> elements{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  std::vector<int> orignal_elements{elements};
  std::unordered_multiset<int> dict(elements.cbegin(), elements.cend());

  Shuffle<int>::ShuffleElements(elements);

  bool elements_changed{false};
  for(auto element : elements) {
    auto found = dict.find(element);
    if(found == dict.end()){
      elements_changed = true;
      break;
    }
    else{
      dict.erase(found);
    }
  }

  if(elements_changed)
    FAIL() << "The shuffling algorithm has changed the contents of the elements instead of shuffling them";

  if(dict.size() != 0){
    FAIL() << "The shuffling algorithm has added extra elements to the input instead of just shuffling them";
    elements_changed = true;
  }

  bool index_unchanged{true};
  for(size_t index = 0; index < elements.size() && !elements_changed; ++index) {
    if(elements[index] != orignal_elements[index]) {
      index_unchanged = false;
      break;
    }
  }

  if(index_unchanged)
    FAIL() << "After shuffling the elements, all the elements position is unchanged";
}

TEST(StackUsingLinkListTests, TestShufflingOfRandomIntegers) {
  srand(time(NULL));
  size_t no_of_elements = (rand() % 500) + 1;
  std::vector<int> elements(no_of_elements);

  for(size_t index = 0; index < no_of_elements; ++index) {
    elements[index] = (rand() % 20000);
  }

  std::vector<int> orignal_elements{elements};
  std::unordered_multiset<int> dict(elements.cbegin(), elements.cend());

  Shuffle<int>::ShuffleElements(elements);

  bool elements_changed{false};
  for(auto element : elements) {
    auto found = dict.find(element);
    if(found == dict.end()){
      elements_changed = true;
      break;
    }
    else{
      dict.erase(found);
    }
  }

  if(elements_changed)
    FAIL() << "The shuffling algorithm has changed the contents of the elements instead of shuffling them";

  if(dict.size() != 0){
    FAIL() << "The shuffling algorithm has added extra elements to the input instead of just shuffling them";
    elements_changed = true;
  }

  bool index_unchanged{true};
  for(size_t index = 0; index < elements.size() && !elements_changed; ++index) {
    if(elements[index] != orignal_elements[index]) {
      index_unchanged = false;
      break;
    }
  }

  if(index_unchanged)
    FAIL() << "After shuffling the elements, all the elements position is unchanged";
}
