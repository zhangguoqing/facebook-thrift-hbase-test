#include <gtest/gtest.h>
#include "HBaseClient.h"
#include <iostream>
#include <folly/init/Init.h>


TEST(HbaseClientTest, SimpleTest) {
    auto hbaseclient = std::make_unique<HBaseClient>("127.0.0.1", 9096);
    hbaseclient->get("user", "zhangsan");
    std::string val = "val";
    EXPECT_EQ(val, "val");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    folly::init(&argc, &argv, true);
    return RUN_ALL_TESTS();
}
