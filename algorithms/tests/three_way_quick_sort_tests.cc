#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "three_way_quick_sort.h"
#include <vector>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace testing;
using namespace algorithms;

TEST(ThreeWayQuickSortTests, TestArrayOfIntegersWithAllDuplicates) {
  std::vector<int> elements{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 };
  auto elements_copy{ elements };

  std::unordered_multiset<int> dict;
  for (auto element : elements) {
    dict.insert(element);
  }

  ThreeWayQuickSort<int>::Sort(elements);

  bool failed{ false };

  for (auto element : elements) {
    auto search = dict.find(element);
    if (search == dict.end()) {
      FAIL() << "Sorting algorithm has modified the element being sorted instead of just moving it into the correct location";
      failed = true;
      break;
    }
  }

  if (!failed) {
    for (size_t index = 1; index < elements.size(); ++index) {
      if (elements[index] < elements[index - 1]) {
        FAIL() << "Elements are not sorted correctly \n" << "Original Elements : " << ::testing::PrintToString(elements_copy) << "\nSorted Elements : " << ::testing::PrintToString(elements);
        break;
      }
    }
  }
}

TEST(ThreeWayQuickSortTests, TestArrayOfIntegersWithDuplicates) {
  std::vector<int> elements{ 5,3,7,3,0,3,3 };
  auto elements_copy{ elements };

  std::unordered_multiset<int> dict;
  for (auto element : elements) {
    dict.insert(element);
  }

  ThreeWayQuickSort<int>::Sort(elements);

  bool failed{ false };

  for (auto element : elements) {
    auto search = dict.find(element);
    if (search == dict.end()) {
      FAIL() << "Sorting algorithm has modified the element being sorted instead of just moving it into the correct location";
      failed = true;
      break;
    }
  }

  if (!failed) {
    for (size_t index = 1; index < elements.size(); ++index) {
      if (elements[index] < elements[index - 1]) {
        FAIL() << "Elements are not sorted correctly \n" << "Original Elements : " << ::testing::PrintToString(elements_copy) << "\nSorted Elements : " << ::testing::PrintToString(elements);
        break;
      }
    }
  }
}

TEST(ThreeWayQuickSortTests, TestArrayOfIntegers) {
  std::vector<int> elements{ 5,3,7,8,0,4,2 };
  auto elements_copy{ elements };

  std::unordered_multiset<int> dict;
  for (auto element : elements) {
    dict.insert(element);
  }

  ThreeWayQuickSort<int>::Sort(elements);

  bool failed{ false };

  for (auto element : elements) {
    auto search = dict.find(element);
    if (search == dict.end()) {
      FAIL() << "Sorting algorithm has modified the element being sorted instead of just moving it into the correct location";
      failed = true;
      break;
    }
  }

  if (!failed) {
    for (size_t index = 1; index < elements.size(); ++index) {
      if (elements[index] < elements[index - 1]) {
        FAIL() << "Elements are not sorted correctly \n" << "Original Elements : " << ::testing::PrintToString(elements_copy) << "\nSorted Elements : " << ::testing::PrintToString(elements);
        break;
      }
    }
  }
}

TEST(ThreeWayQuickSortTests, TestRandomArrayOfIntegers) {
  srand(time(NULL));
  size_t size = (rand() % 500) + 1;
  std::vector<int> elements(size);
  for (size_t index = 0; index < size; ++index) {
    elements[index] = (rand() % 5000) + 1;
  }

  auto elements_copy{ elements };

  std::unordered_multiset<int> dict;
  for (auto element : elements) {
    dict.insert(element);
  }

  ThreeWayQuickSort<int>::Sort(elements);

  bool failed{ false };

  for (auto element : elements) {
    auto search = dict.find(element);
    if (search == dict.end()) {
      FAIL() << "Sorting algorithm has modified the element being sorted instead of just moving it into the correct location";
      failed = true;
      break;
    }
  }

  if (!failed) {
    for (size_t index = 1; index < elements.size(); ++index) {
      if (elements[index] < elements[index - 1]) {
        FAIL() << "Elements are not sorted correctly \n" << "Original Elements : " << ::testing::PrintToString(elements_copy) << "\nSorted Elements : " << ::testing::PrintToString(elements);
        break;
      }
    }
  }
}

TEST(ThreeWayQuickSortTests, TestArrayOfStrings) {
  std::vector<std::string> elements{ "Hi", "this", "algorithm", "should", "work", "string", "random" };
  auto elements_copy{ elements };

  std::unordered_multiset<std::string> dict;
  for (auto element : elements) {
    dict.insert(element);
  }

  ThreeWayQuickSort<std::string>::Sort(elements);

  bool failed{ false };

  for (auto element : elements) {
    auto search = dict.find(element);
    if (search == dict.end()) {
      FAIL() << "Sorting algorithm has modified the element being sorted instead of just moving it into the correct location";
      failed = true;
      break;
    }
  }

  if (!failed) {
    for (size_t index = 1; index < elements.size(); ++index) {
      if (elements[index] < elements[index - 1]) {
        FAIL() << "Elements are not sorted correctly \n" << "Original Elements : " << ::testing::PrintToString(elements_copy) << "\nSorted Elements : " << ::testing::PrintToString(elements);
        break;
      }
    }
  }
}

TEST(ThreeWayQuickSortTests, TestArrayOfDoubles) {
  std::vector<double> elements{ 0.2, 1.6, 1.5, 0.1, 0.001, 0.301 };
  auto elements_copy{ elements };

  std::unordered_multiset<double> dict;
  for (auto element : elements) {
    dict.insert(element);
  }

  ThreeWayQuickSort<double>::Sort(elements);

  bool failed{ false };

  for (auto element : elements) {
    auto search = dict.find(element);
    if (search == dict.end()) {
      FAIL() << "Sorting algorithm has modified the element being sorted instead of just moving it into the correct location";
      failed = true;
      break;
    }
  }

  if (!failed) {
    for (size_t index = 1; index < elements.size(); ++index) {
      if (elements[index] < elements[index - 1]) {
        FAIL() << "Elements are not sorted correctly \n" << "Original Elements : " << ::testing::PrintToString(elements_copy) << "\nSorted Elements : " << ::testing::PrintToString(elements);
        break;
      }
    }
  }
}

TEST(ThreeWayQuickSortTests, TestArrayOfIntegersInDecendingOrder) {
  std::vector<int> elements{ 5,3,7,8,0,4,2 };
  auto elements_copy{ elements };

  std::unordered_multiset<int> dict;
  for (auto element : elements) {
    dict.insert(element);
  }

  ThreeWayQuickSort<int>::Sort(elements, [](int a, int b) {return a > b; });

  bool failed{ false };

  for (auto element : elements) {
    auto search = dict.find(element);
    if (search == dict.end()) {
      FAIL() << "Sorting algorithm has modified the element being sorted instead of just moving it into the correct location";
      failed = true;
      break;
    }
  }

  if (!failed) {
    for (size_t index = 1; index < elements.size(); ++index) {
      if (elements[index] > elements[index - 1]) {
        FAIL() << "Elements are not sorted correctly \n" << "Original Elements : " << ::testing::PrintToString(elements_copy) << "\nSorted Elements : " << ::testing::PrintToString(elements);
        break;
      }
    }
  }
}
