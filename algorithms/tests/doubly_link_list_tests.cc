#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "doubly_link_list.h"
#include <string>

using namespace testing;
using namespace algorithms;

TEST(DoublyLinkListTests, TestInitiallEmpty) {
  DoublyLinkList<int> list;
  EXPECT_TRUE(list.Empty()) << "Initially the link list is supposed to be empty";
}

TEST(DoublyLinkListTests, TestAddingAndRemovingElementsFromFront) {
  DoublyLinkList<int> list;
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

TEST(DoublyLinkListTests, TestAddingAndRemovingElementsFromBack) {
  DoublyLinkList<int> list;
  list.Push_Back(100);
  list.Push_Back(200);
  list.Push_Back(300);

  ASSERT_EQ(list.Back(), 300);
  list.Pop_Back();

  ASSERT_EQ(list.Back(), 200);
  list.Pop_Back();

  list.Push_Back(400);
  ASSERT_EQ(list.Back(), 400);
  list.Pop_Back();

  ASSERT_EQ(list.Back(), 100);
  list.Pop_Back();
}

TEST(DoublyLinkListTests, TestAddingAndRemovingElementsFromFrontAndBack) {
  DoublyLinkList<int> list;

  list.Push_Front(10);
  
  ASSERT_EQ(list.Back(), 10);
  list.Pop_Back();
  
  ASSERT_EQ(list.Empty(), true) << "List list is not empty after pushing from front and popping from back";
  ASSERT_THROW(list.Front(), std::underflow_error) << "Accessing front element from an empty list did not throw an exception"; 

  list.Push_Back(20);

  ASSERT_EQ(list.Front(), 20);
  list.Pop_Front();

  ASSERT_EQ(list.Empty(), true) << "List list is not empty after pushing from back and popping from front";
  ASSERT_THROW(list.Back(), std::underflow_error) << "Accessing back element from an empty list did not throw an exception"; 

  list.Push_Front(100);
  list.Push_Front(200);
  list.Push_Front(300);

  ASSERT_EQ(list.Front(), 300);
  list.Pop_Front();

  ASSERT_EQ(list.Front(), 200);
  list.Pop_Front();

  ASSERT_EQ(list.Front(), 100);
  list.Pop_Front();

  list.Push_Back(500);
  list.Push_Back(600);
  list.Push_Back(700);

  ASSERT_EQ(list.Back(), 700);
  list.Pop_Back();
  
  ASSERT_EQ(list.Back(), 600);
  list.Pop_Back();
  
  ASSERT_EQ(list.Back(), 500);
  list.Pop_Back();
}

TEST(DoublyLinkListTests, TestAddingRemoveAlternatingFromFrontAndBack) {
  DoublyLinkList<int> list;

  list.Push_Back(10);
  list.Push_Front(20);
  list.Push_Back(30);
  list.Push_Front(40);
  list.Push_Back(50);
  list.Push_Front(60);

  ASSERT_EQ(list.Front(), 60);
  list.Pop_Front();
  
  ASSERT_EQ(list.Front(), 40);
  list.Pop_Front();
  
  ASSERT_EQ(list.Front(), 20);
  list.Pop_Front();

  ASSERT_EQ(list.Front(), 10);
  list.Pop_Front();

  ASSERT_EQ(list.Front(), 30);
  list.Pop_Front();

  ASSERT_EQ(list.Front(), 50);
  list.Pop_Front();
}

TEST(DoublyLinkListTests, TestNonEmptyAfterPushingFromFront) {
  DoublyLinkList<std::string> list;
  list.Push_Front("Hi");

  ASSERT_EQ(list.Empty(), false) << "List list is empty after pushing one element from front of the list";
}

TEST(DoublyLinkListTests, TestNonEmptyAfterPushingFromBack) {
  DoublyLinkList<std::string> list;
  list.Push_Back("Hi");

  ASSERT_EQ(list.Empty(), false) << "List list is empty after pushing one element from back of the list";
}

TEST(DoublyLinkListTests, TestEmptyAfterPoppingFromFront) {
  DoublyLinkList<std::string> list;
  list.Push_Front("Hello");
  list.Push_Front("World");
  
  list.Push_Back("Nice");
  list.Push_Back("World");

  list.Pop_Front();
  list.Pop_Front();
  list.Pop_Front();
  list.Pop_Front();


  ASSERT_EQ(list.Empty(), true) << "List is not empty after removing all elements from front of the list";
}

TEST(DoublyLinkListTests, TestEmptyAfterPoppingFromBack) {
  DoublyLinkList<std::string> list;
  list.Push_Front("Hello");
  list.Push_Front("World");
  
  list.Push_Back("Nice");
  list.Push_Back("World");

  list.Pop_Back();
  list.Pop_Back();
  list.Pop_Back();
  list.Pop_Back();

  ASSERT_EQ(list.Empty(), true) << "List is not empty after removing all elements from back of the list";
}


TEST(DoublyLinkListTests, TestPoppingFrontElementFromEmptyList) {
  DoublyLinkList<int> list;
  ASSERT_THROW(list.Pop_Front(), std::underflow_error) << "Popping from front of an empty list did not throw an exception";
}

TEST(DoublyLinkListTests, TestPoppingBackElementFromEmptyList) {
  DoublyLinkList<int> list;
  ASSERT_THROW(list.Pop_Back(), std::underflow_error) << "Popping from back of an empty list did not throw an exception";
}

TEST(DoublyLinkListTests, TestAccessingFrontElementFromEmptyList) {
  DoublyLinkList<double> list;
  ASSERT_THROW(list.Front(), std::underflow_error) << "Accessing front element from an empty list did not throw an exception"; 
}

TEST(DoublyLinkListTests, TestAccessingBackElementFromEmptyList) {
  DoublyLinkList<double> list;
  ASSERT_THROW(list.Back(), std::underflow_error) << "Accessing back element from an empty list did not throw an exception"; 
}

