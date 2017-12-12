#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "stack_using_resizing_array.h"
#include <string>

using namespace testing;
using namespace algorithms;

TEST(StackUsingResizingArrayTests, TestInitiallEmpty) {
    StackUsingResizingArray<int> my_stack;
    EXPECT_TRUE(my_stack.Empty()) << "Initially the stack is supposed to be empty";
}

TEST(StackUsingResizingArrayTests, TestInitialSizeZero) {
    StackUsingResizingArray<int> my_stack;
    EXPECT_EQ(my_stack.Size(), 0) << "Initially the stack size should be zero since there are no elements pushed onto it";
}

TEST(StackUsingResizingArrayTests, TestPushPopAndTopOperations) {
    StackUsingResizingArray<int> my_stack;
    my_stack.Push(10);
    my_stack.Push(20);
    my_stack.Push(30);

    ASSERT_EQ(my_stack.Top(), 30) << "Top element is not correct";

    my_stack.Pop();

    ASSERT_EQ(my_stack.Top(), 20) << "Top element is not correct";

    my_stack.Push(40);

    ASSERT_EQ(my_stack.Top(), 40) << "Top element is not correct";

    my_stack.Pop();
    my_stack.Pop();
   
    ASSERT_EQ(my_stack.Top(), 10) << "Top element is not correct";
}

TEST(StackUsingResizingArrayTests, TestNonEmpty) {
    StackUsingResizingArray<int> my_stack;
    my_stack.Push(10);
    my_stack.Push(20);
    my_stack.Push(30);

    EXPECT_FALSE(my_stack.Empty()) << "Stack is empty after pushing few elements";
}

TEST(StackUsingResizingArrayTests, TestEmpty) {
  StackUsingResizingArray<std::string> my_stack;
  my_stack.Push("Hi");
  my_stack.Push("Hello");

  my_stack.Pop();
  my_stack.Pop();

  EXPECT_TRUE(my_stack.Empty()) << "Stack is not empty after popping all elements";
}

TEST(StackUsingResizingArrayTests, TestSizeAfterPushPopOperations) {
  StackUsingResizingArray<int> my_stack;
  
  my_stack.Push(100);
  my_stack.Push(200);
  my_stack.Push(300);
  my_stack.Push(400);

  ASSERT_EQ(my_stack.Size(), 4) << "Stack size is incorrect";

  my_stack.Pop();

  ASSERT_EQ(my_stack.Size(), 3) << "Stack size is incorrect";

  my_stack.Pop();
  my_stack.Pop();

  ASSERT_EQ(my_stack.Size(), 1) << "Stack size is incorrect";

  my_stack.Pop();

  ASSERT_EQ(my_stack.Size(), 0) << "Stack size is incorrect";
}

TEST(StackUsingResizingArrayTests, TestPoppingFromEmptyStack) {
  StackUsingResizingArray<int> my_stack;
  ASSERT_THROW(my_stack.Pop(), std::underflow_error) << "Popping from an stack  did not throw an exception";
}

TEST(StackUsingResizingArrayTests, TestAccessingFrontElementFromEmptyList) {
  StackUsingResizingArray<double> my_stack;
  ASSERT_THROW(my_stack.Top(), std::underflow_error) << "Accessing top element from an empty stack did not throw an exception"; 
}
