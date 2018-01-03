#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "insertion_sort.h"
#include <vector>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace testing;
using namespace algorithms;

TEST(InsertionSortTests, TestArrayOfIntegers) {
  std::vector<int> elements{ 5,3,7,8,0,4,2 };
  auto elements_copy{ elements };

  std::unordered_multiset<int> dict;
  for (auto element : elements) {
    dict.insert(element);
  }

  InsertionSort<int>::Sort(elements);

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

TEST(InsertionSortTests, TestRandomArrayOfIntegers) {
  srand(static_cast<unsigned int>(time(NULL)));
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

  InsertionSort<int>::Sort(elements);

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

TEST(InsertionSortTests, TestArrayOfStrings) {
  std::vector<std::string> elements{ "Hi", "this", "algorithm", "should", "work", "string", "random" };
  auto elements_copy{ elements };

  std::unordered_multiset<std::string> dict;
  for (auto element : elements) {
    dict.insert(element);
  }

  InsertionSort<std::string>::Sort(elements);

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

TEST(InsertionSortTests, TestArrayOfDoubles) {
  std::vector<double> elements{ 0.2, 1.6, 1.5, 0.1, 0.001, 0.301 };
  auto elements_copy{ elements };

  std::unordered_multiset<double> dict;
  for (auto element : elements) {
    dict.insert(element);
  }

  InsertionSort<double>::Sort(elements);

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

TEST(InsertionSortTests, TestArrayOfIntegersInDecendingOrder) {
  std::vector<int> elements{ 5,3,7,8,0,4,2 };
  auto elements_copy{ elements };

  std::unordered_multiset<int> dict;
  for (auto element : elements) {
    dict.insert(element);
  }

  InsertionSort<int>::Sort(elements, [](int a, int b) {return a > b; });

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
