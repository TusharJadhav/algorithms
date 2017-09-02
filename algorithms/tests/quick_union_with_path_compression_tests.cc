#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "quick_union_with_path_compression.h"

#include <stdexcept>

using namespace testing;
using namespace algorithms;

TEST(QuickUnionWithPathCompressionTests, TestInitiallDisconnected) {
    QuickUnionWithPathCompression quwpc_obj{4};
    EXPECT_FALSE(quwpc_obj.Connected(0, 3)) << "Initially the elements are supposed to be disconnected";
    EXPECT_FALSE(quwpc_obj.Connected(0, 2)) << "Initially the elements are supposed to be disconnected";
    EXPECT_FALSE(quwpc_obj.Connected(2, 1)) << "Initially the elements are supposed to be disconnected";
}

TEST(QuickUnionWithPathCompressionTests, TestUnionConnected) {
    QuickUnionWithPathCompression quwpc_obj{5};
    EXPECT_FALSE(quwpc_obj.Connected(2, 1)) << "Initially the elements are supposed to be disconnected";
    quwpc_obj.Union(1, 2);
    EXPECT_TRUE(quwpc_obj.Connected(2, 1)) << "The elements are disconnected even after the union operation";
}

TEST(QuickUnionWithPathCompressionTests, TestUnionInvalidArgsOverLimit) {
    QuickUnionWithPathCompression quwpc_obj{100};
    try {
      quwpc_obj.Union(5, 100);
      FAIL() << "Expected std::invalid_argument exception for calling Union with invalid parameters";
    }
    catch(std::invalid_argument& err) {
      EXPECT_STRCASEEQ(err.what(), "Parameters passed are out of bounds");
    }
    catch(...) {
      FAIL() << "Expected std::invalid_argument exception for calling Union with invalid parameters";
    }
}

TEST(QuickUnionWithPathCompressionTests, TestUnionInvalidArgsUnderLimit) {
    QuickUnionWithPathCompression quwpc_obj{100};
    try {
      quwpc_obj.Union(-1, 55);
      FAIL() << "Expected std::invalid_argument exception for calling Union with invalid parameters";
    }
    catch(std::invalid_argument& err) {
      EXPECT_STRCASEEQ(err.what(), "Parameters passed are out of bounds");
    }
    catch(...) {
      FAIL() << "Expected std::invalid_argument exception for calling Union with invalid parameters";
    }
}

TEST(QuickUnionWithPathCompressionTests, TestUnionWithBorderParameters) {
    QuickUnionWithPathCompression quwpc_obj{100};
    try {
      quwpc_obj.Union(0, 99);
    }
    catch(...) {
      FAIL() << "Did not expect an exception for calling Union with valid parameters";
    }
}

TEST(QuickUnionWithPathCompressionTests, TestConnectedInvalidArgsOverLimit) {
    QuickUnionWithPathCompression quwpc_obj{100};
    try {
      quwpc_obj.Connected(101, 0);
      FAIL() << "Expected std::invalid_argument exception for calling Connected with invalid parameters";
    }
    catch(std::invalid_argument& err) {
      EXPECT_STRCASEEQ(err.what(), "Parameters passed are out of bounds");
    }
    catch(...) {
      FAIL() << "Expected std::invalid_argument exception for calling Connected with invalid parameters";
    }
}

TEST(QuickUnionWithPathCompressionTests, TestConnectedInvalidArgsUnderLimit) {
    QuickUnionWithPathCompression quwpc_obj{100};
    try {
      quwpc_obj.Connected(-1, 70);
      FAIL() << "Expected std::invalid_argument exception for calling Connected with invalid parameters";
    }
    catch(std::invalid_argument& err) {
      EXPECT_STRCASEEQ(err.what(), "Parameters passed are out of bounds");
    }
    catch(...) {
      FAIL() << "Expected std::invalid_argument exception for calling Connected with invalid parameters";
    }
}

TEST(QuickUnionWithPathCompressionTests, TestConnectedWithBorderParameters) {
    QuickUnionWithPathCompression quwpc_obj{100};
    try {
      quwpc_obj.Connected(0, 99);
    }
    catch(...) {
      FAIL() << "Did not expect an exception for calling Union with valid parameters";
    }
}

TEST(QuickUnionWithPathCompressionTests, TestConnectedIndirectLink) {
    QuickUnionWithPathCompression quwpc_obj{3};
    try {
      EXPECT_FALSE(quwpc_obj.Connected(0, 1));
      quwpc_obj.Union(0, 2);
      quwpc_obj.Union(1, 2);
      EXPECT_TRUE(quwpc_obj.Connected(0, 1));
    }
    catch(...) {
      FAIL() << "Did not expect an exception for calling Union with valid parameters";
    }
}

TEST(QuickUnionWithPathCompressionTests, TestUnionWhenAlreadyConnected) {
    QuickUnionWithPathCompression quwpc_obj{9};
    try {
      quwpc_obj.Union(0, 5);
      quwpc_obj.Union(5, 0);
      EXPECT_TRUE(quwpc_obj.Connected(0, 5));
    }
    catch(...) {
      FAIL() << "Did not expect an exception for calling Union with valid parameters";
    }
}

