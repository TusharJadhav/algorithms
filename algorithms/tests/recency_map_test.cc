#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "recency_map.h"

using namespace testing;
using namespace algorithms;

class recency_map_test : public Test
{
};

TEST_F(recency_map_test, TestGet)
{
  algorithms::recency_map map;
  map.set("Hello", 5);
  EXPECT_EQ(map.get("Hello"), 5) << "Not able to get the value which was set";
}

TEST_F(recency_map_test, TestGetAgain)
{
  recency_map map;
  map.set("Hello", 5);
  EXPECT_EQ(map.get("Hello"), 5) << "Not able to get the value which was set";
}


TEST_F(recency_map_test, TestRecent)
{
  recency_map map;
  map.set("One", 1);
  map.set("Two", 2);
  map.set("Three", 3);
  map.set("Four", 4);
  map.set("Five", 5);

  EXPECT_EQ(map.mostRecentKey(), "Five") << "Most recent key not correct";

  map.get("Three");

  EXPECT_EQ(map.mostRecentKey(), "Three") << "Most recent key not correct";
}