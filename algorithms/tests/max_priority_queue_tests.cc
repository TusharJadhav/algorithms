#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "max_priority_queue.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace testing;
using namespace algorithms;

TEST(MaxPriorityQueueTests, TestEmpty) {
  MaxPriorityQueue<int> max_pq;
  ASSERT_TRUE(max_pq.IsEmpty()) << "Maximum Priority Queue initially not empty";
  max_pq.Insert(10);
  ASSERT_FALSE(max_pq.IsEmpty()) << "Maximum Priority Queue is empty after inserting an element";
}

TEST(MaxPriorityQueueTests, TestGetMaximumElement) {
  MaxPriorityQueue<int> max_pq;
  max_pq.Insert(50);
  ASSERT_EQ(max_pq.GetMax(), 50) << "Maximum element incorrect";

  max_pq.Insert(100);
  max_pq.Insert(30);
  max_pq.Insert(500);
  max_pq.Insert(50);
  max_pq.Insert(350);

  ASSERT_EQ(max_pq.GetMax(), 500) << "Maximum element incorrect";

  max_pq.Insert(700);

  ASSERT_EQ(max_pq.GetMax(), 700) << "Maximum element incorrect";
}

TEST(MaxPriorityQueueTests, TestDeleteElement) {
  MaxPriorityQueue<int> max_pq;
  max_pq.Insert(50);
  ASSERT_EQ(max_pq.GetMax(), 50) << "Maximum element incorrect";

  max_pq.Insert(100);
  max_pq.Insert(30);
  max_pq.Insert(500);
  max_pq.Insert(50);
  max_pq.Insert(350);

  max_pq.DeleteMax();
  ASSERT_EQ(max_pq.GetMax(), 350) << "Maximum element incorrect";
}

TEST(MaxPriorityQueueTests, TestConstructionWithElements) {
  std::vector<int> elements{400, 300, 800, 150, 600, 200, 1000};

  MaxPriorityQueue<int> max_pq(elements);
  
  ASSERT_FALSE(max_pq.IsEmpty()) << "Maximum Priority Queue is empty after constructing with vector of elements";

  ASSERT_EQ(max_pq.GetMax(), 1000) << "Maximum element incorrect";
}

TEST(MaxPriorityQueueTests, TestWithCustomClassAndComparator) {
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
    return left.age_ >= right.age_;
  };

  MaxPriorityQueue<Person> max_pq(elements, comparator);

  ASSERT_FALSE(max_pq.IsEmpty()) << "Maximum Priority Queue is empty after constructing with vector of elements";

  ASSERT_EQ(max_pq.GetMax().age_, 32) << "Maximum element incorrect";
}

TEST(MaxPriorityQueueTests, TestWithRandomGeneratedElements) {
  srand(static_cast<unsigned int>(time(NULL)));
  size_t size = (rand() % 5000) + 1;
  std::vector<int> elements(size);
  for (size_t index = 0; index < size; ++index) {
    elements[index] = (rand() % 5000) + 1;
  }

  std::vector<int> elements_sorted{elements};
  std::sort(elements_sorted.begin(), elements_sorted.end());

  MaxPriorityQueue<int> max_pq(elements);
  int index = static_cast<int>(elements_sorted.size() - 1);

  while(!max_pq.IsEmpty() && index >= 0){
    ASSERT_EQ(max_pq.GetMax(), elements_sorted[index--]) << "Maximum element incorrect";
    max_pq.DeleteMax();
  }

  ASSERT_EQ(index, -1);
}

