#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "queue_using_resizing_array.h"
#include <string>

using namespace testing;
using namespace algorithms;

TEST(QueueUsingResizingArrayTests, TestInitiallEmpty) {
    QueueUsingResizingArray<int> my_queue;
    EXPECT_TRUE(my_queue.Empty()) << "Initially the queue is supposed to be empty";
}

TEST(QueueUsingResizingArrayTests, TestInitialSizeZero) {
    QueueUsingResizingArray<int> my_queue;
    EXPECT_EQ(my_queue.Size(), 0) << "Initially the queue size should be zero since there are no elements enqueued into it";
}

TEST(QueueUsingResizingArrayTests, TestPushEnqueAndDequeOperations) {
    QueueUsingResizingArray<int> my_queue;
    my_queue.Enque(10);
    my_queue.Enque(20);
    my_queue.Enque(30);

    ASSERT_EQ(my_queue.Front(), 10) << "Front element is not correct";

    my_queue.Deque(); // 10

    ASSERT_EQ(my_queue.Front(), 20) << "Front element is not correct";

    my_queue.Enque(40);

    my_queue.Deque(); // 20

    ASSERT_EQ(my_queue.Front(), 30) << "Front element is not correct";
    ASSERT_EQ(my_queue.Back(), 40) << "Back element is not correct";

    my_queue.Deque(); // 30
   
    ASSERT_EQ(my_queue.Front(), 40) << "Front element is not correct";

    my_queue.Deque(); // 40

    my_queue.Enque(100);
    my_queue.Enque(200);
    my_queue.Enque(300);
    my_queue.Enque(400);
    my_queue.Enque(500);
    my_queue.Enque(600);
    my_queue.Enque(700);

    ASSERT_EQ(my_queue.Front(), 100) << "Front element is not correct";
    ASSERT_EQ(my_queue.Back(), 700) << "Back element is not correct";

    my_queue.Deque(); // 100
    my_queue.Deque(); // 200
    my_queue.Deque(); // 300
    my_queue.Deque(); // 400
    my_queue.Deque(); // 500
    my_queue.Deque(); // 600

    ASSERT_EQ(my_queue.Front(), 700) << "Front element is not correct";
    ASSERT_EQ(my_queue.Back(), 700) << "Back element is not correct";
}

TEST(QueueUsingResizingArrayTests, TestFrontBackElementAccess) {
    QueueUsingResizingArray<int> my_queue;
    
    my_queue.Enque(100);
    my_queue.Enque(200);
    my_queue.Enque(300);
    my_queue.Enque(400);

    ASSERT_EQ(my_queue.Front(), 100) << "Front element is not correct";
    ASSERT_EQ(my_queue.Back(), 400) << "Back element is not correct";

    my_queue.Deque();

    ASSERT_EQ(my_queue.Front(), 200) << "Front element is not correct";
    ASSERT_EQ(my_queue.Back(), 400) << "Back element is not correct";

    my_queue.Deque();

    ASSERT_EQ(my_queue.Front(), 300) << "Front element is not correct";
    ASSERT_EQ(my_queue.Back(), 400) << "Back element is not correct";
}

TEST(QueueUsingResizingArrayTests, TestNonEmpty) {
    QueueUsingResizingArray<int> my_queue;
    my_queue.Enque(10);
    my_queue.Enque(20);
    my_queue.Enque(30);

    EXPECT_FALSE(my_queue.Empty()) << "Queue is empty after enqueuing few elements";
}

TEST(QueueUsingResizingArrayTests, TestEmpty) {
  QueueUsingResizingArray<std::string> my_queue;
  my_queue.Enque("Hi");
  my_queue.Enque("Hello");

  my_queue.Deque();
  my_queue.Deque();

  EXPECT_TRUE(my_queue.Empty()) << "Queue is not empty after dequeuing all elements";
}

TEST(QueueUsingResizingArrayTests, TestSizeAfterEnqueDequeOperations) {
  QueueUsingResizingArray<int> my_queue;
  
  my_queue.Enque(100);
  my_queue.Enque(200);
  my_queue.Enque(300);
  my_queue.Enque(400);

  ASSERT_EQ(my_queue.Size(), 4) << "Queue size is incorrect";

  my_queue.Deque();

  ASSERT_EQ(my_queue.Size(), 3) << "Queue size is incorrect";

  my_queue.Deque();
  my_queue.Deque();

  ASSERT_EQ(my_queue.Size(), 1) << "Queue size is incorrect";

  my_queue.Deque();

  ASSERT_EQ(my_queue.Size(), 0) << "Queue size is incorrect";
}

TEST(QueueUsingResizingArrayTests, TestDequeuingFromEmptyQueue) {
  QueueUsingResizingArray<int> my_queue;
  ASSERT_THROW(my_queue.Deque(), std::underflow_error) << "Popping from an empty queue did not throw an exception";
}

TEST(QueueUsingResizingArrayTests, TestAccessingFrontElementFromEmptyQueue) {
  QueueUsingResizingArray<double> my_queue;
  ASSERT_THROW(my_queue.Front(), std::underflow_error) << "Accessing front element from an empty queue did not throw an exception"; 
}
