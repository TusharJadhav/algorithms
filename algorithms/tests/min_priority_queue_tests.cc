#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "min_priority_queue.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace testing;
using namespace algorithms;

TEST(MinPriorityQueueTests, TestEmpty) {
  MinPriorityQueue<int> min_pq;
  ASSERT_TRUE(min_pq.IsEmpty()) << "Minimum Priority Queue initially not empty";
  min_pq.Insert(10);
  ASSERT_FALSE(min_pq.IsEmpty()) << "Minimum Priority Queue is empty after inserting an element";
}

TEST(MinPriorityQueueTests, TestGetMinimumElement) {
  MinPriorityQueue<int> min_pq;
  min_pq.Insert(50);
  ASSERT_EQ(min_pq.GetMin(), 50) << "Minimum element incorrect";

  min_pq.Insert(100);
  min_pq.Insert(30);
  min_pq.Insert(500);
  min_pq.Insert(50);
  min_pq.Insert(350);

  ASSERT_EQ(min_pq.GetMin(), 30) << "Minimum element incorrect";

  min_pq.Insert(10);

  ASSERT_EQ(min_pq.GetMin(), 10) << "Minimum element incorrect";
}

TEST(MinPriorityQueueTests, TestDeleteElement) {
  MinPriorityQueue<int> min_pq;
  min_pq.Insert(50);
  ASSERT_EQ(min_pq.GetMin(), 50) << "Minimum element incorrect";

  min_pq.Insert(100);
  min_pq.Insert(30);
  min_pq.Insert(500);
  min_pq.Insert(50);
  min_pq.Insert(350);

  min_pq.DeleteMin();
  ASSERT_EQ(min_pq.GetMin(), 50) << "Minimum element incorrect";
}

TEST(MinPriorityQueueTests, TestConstructionWithElements) {
  std::vector<int> elements{400, 300, 800, 150, 600, 200, 1000};

  MinPriorityQueue<int> min_pq(elements);
  
  ASSERT_FALSE(min_pq.IsEmpty()) << "Minimum Priority Queue is empty after constructing with vector of elements";

  ASSERT_EQ(min_pq.GetMin(), 150) << "Minimum element incorrect";
}

TEST(MinPriorityQueueTests, TestWithCustomClassAndComparator) {
  class Person {
    public:
      Person() {}

      Person(const std::string& name, int age) :
        name_{name},
        age_{age}
      {}

      Person(const Person& other) {
        name_ = other.name_;
        age_ = other.age_;
      }

      std::string name_;
      int age_;
  };

  std::vector<Person> elements{{"Dave", 21}, {"Robert", 25}, {"Christina", 10}, {"Timothy", 32}};

  auto comparator = [](const Person& left, const Person& right) -> bool {
    return left.age_ <= right.age_;
  };

  MinPriorityQueue<Person> min_pq(elements, comparator);

  ASSERT_FALSE(min_pq.IsEmpty()) << "Minimum Priority Queue is empty after constructing with vector of elements";

  ASSERT_EQ(min_pq.GetMin().age_, 10) << "Minimum element incorrect";
}

TEST(MinPriorityQueueTests, TestWithRandomGeneratedElements) {
  srand(time(NULL));
  size_t size = (rand() % 5000) + 1;
  std::vector<int> elements(size);
  for (size_t index = 0; index < size; ++index) {
    elements[index] = (rand() % 5000) + 1;
  }

  std::vector<int> elements_sorted{elements};
  std::sort(elements_sorted.begin(), elements_sorted.end());

  MinPriorityQueue<int> min_pq(elements);
  size_t index = 0;

  while(!min_pq.IsEmpty() && index < elements_sorted.size()){
    ASSERT_EQ(min_pq.GetMin(), elements_sorted[index++]) << "Minimum element incorrect";
    min_pq.DeleteMin();
  }

  ASSERT_EQ(index, elements_sorted.size());
}

