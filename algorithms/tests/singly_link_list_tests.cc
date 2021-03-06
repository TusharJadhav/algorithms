#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "singly_link_list.h"
#include <string>

using namespace testing;
using namespace algorithms;

TEST(SinglyLinkListTests, TestInitiallEmpty) {
  SinglyLinkList<int> list;
  EXPECT_TRUE(list.Empty()) << "Initially the link list is supposed to be empty";
}

TEST(SinglyLinkListTests, TestAddingAndRemovingElements) {
  SinglyLinkList<int> list;
  list.Push_Front(10);
  list.Push_Front(20);
  list.Push_Front(30);

  ASSERT_EQ(list.Front(), 30);
  list.Pop_Front();
  
  ASSERT_EQ(list.Front(), 20);
  list.Pop_Front();

  list.Push_Front(40);
  ASSERT_EQ(list.Front(), 40);
  list.Pop_Front();
  
  ASSERT_EQ(list.Front(), 10);
  list.Pop_Front();
}

TEST(SinglyLinkListTests, TestNonEmpty) {
  SinglyLinkList<std::string> list;
  list.Push_Front("Hi");

  ASSERT_EQ(list.Empty(), false) << "List list is empty after pushing one element";
}

TEST(SinglyLinkListTests, TestEmpty) {
  SinglyLinkList<std::string> list;
  list.Push_Front("Hello");
  list.Push_Front("World");

  list.Pop_Front();
  list.Pop_Front();
  
  ASSERT_EQ(list.Empty(), true) << "List is not empty after removing all elements";
}

TEST(SinglyLinkListTests, TestPoppingFromEmptyList) {
  SinglyLinkList<int> list;
  ASSERT_THROW(list.Pop_Front(), std::underflow_error) << "Popping from an empty list did not throw an exception";
}

TEST(SinglyLinkListTests, TestAccessingFrontElementFromEmptyList) {
  SinglyLinkList<double> list;
  ASSERT_THROW(list.Front(), std::underflow_error) << "Accessing front element from an empty list did not throw an exception"; 
}

