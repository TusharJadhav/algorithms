#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "binary_search_tree.h"
#include <algorithm>
#include <vector>
#include <string>

using namespace testing;
using namespace algorithms;

TEST(BinarySearhTreeTests, TestInorder) {
  std::vector<int> elements{20, 30, 10, 50, 25, 5};

  BinarySearchTree<int> bst;
  for(auto element : elements){
    bst.Insert(element);
  }

  std::vector<int> sorted_elements{elements};
  std::sort(sorted_elements.begin(), sorted_elements.end());
  
  auto inorder_list = bst.GetElementsInOrder();
  ASSERT_EQ(inorder_list.size(), sorted_elements.size());

  size_t index = 0;

  for(auto element : sorted_elements){
    EXPECT_EQ(element, inorder_list[index++]);
  }
}

TEST(BinarySearhTreeTests, TestInsert) {
  std::vector<int> elements{20, 30, 10, 50, 25, 5};

  BinarySearchTree<int> bst;
  for(auto element : elements){
    bst.Insert(element);
  }

  bst.Insert(200);

  auto inorder_list = bst.GetElementsInOrder();
  auto found = std::find(inorder_list.cbegin(), inorder_list.cend(), 200);
  ASSERT_NE(found, inorder_list.cend());
}

TEST(BinarySearhTreeTests, TestContains) {
  std::vector<int> elements{20, 30, 10, 50, 25, 5};

  BinarySearchTree<int> bst;
  for(auto element : elements){
    bst.Insert(element);
  }

  ASSERT_EQ(bst.Contains(50), true);
  ASSERT_EQ(bst.Contains(175), false);
}

TEST(BinarySearhTreeTests, TestEmpty) {
  BinarySearchTree<std::string> bst;

  ASSERT_EQ(bst.IsEmpty(), true);
  bst.Insert("Algorithms");
  ASSERT_EQ(bst.IsEmpty(), false);
  bst.Insert("Rocks");
  ASSERT_EQ(bst.IsEmpty(), false);
}

TEST(BinarySearhTreeTests, TestSize) {
  BinarySearchTree<std::string> bst;

  ASSERT_EQ(bst.Size(), 0);

  std::vector<std::string> elements{"Algorithms", "Are", "Great", "Once", "You", "Get", "Hang", "Of", "It"};
  for(auto element : elements){
    bst.Insert(element);
  }

  ASSERT_EQ(bst.Size(), elements.size());
}

TEST(BinarySearhTreeTests, TestMin) {
  std::vector<int> elements{20, 30, 10, 50, 25, 5};

  BinarySearchTree<int> bst;

  ASSERT_THROW(bst.Min(), std::underflow_error);

  for(auto element : elements){
    bst.Insert(element);
  }

  ASSERT_EQ(bst.Min(), *(std::min_element(elements.cbegin(), elements.cend())));
}

TEST(BinarySearhTreeTests, TestMax) {
  std::vector<int> elements{20, 30, 10, 50, 25, 5};

  BinarySearchTree<int> bst;

  ASSERT_THROW(bst.Max(), std::underflow_error);
  
  for(auto element : elements){
    bst.Insert(element);
  }

  ASSERT_EQ(bst.Max(), *(std::max_element(elements.cbegin(), elements.cend())));
}
