# first of all, copy source file ReconnectingRequestChannel.cpp to facebook-thrift-install/include/thrift/lib/cpp2/async/
add_executable(
    hbase_client_test
    HBaseClientTest.cpp
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-thrift-install/include/thrift/lib/cpp2/async/ReconnectingRequestChannel.cpp
    $<TARGET_OBJECTS:hbase_client_obj>
    $<TARGET_OBJECTS:hbase_thrift_obj>
)

target_link_libraries(
    hbase_client_test
    ${FACEBOOK_LIBRARIES}
    gtest
    folly
    glog
    gflags
    event
    double-conversion
    wangle
    bz2
    snappy
    zstd
    z
    boost_context
    boost_system
    -lunwind
    dl
    -pthread
    -lssl
    -lcrypto
    -lz
)

add_test(NAME hbase_client_test COMMAND hbase_client_test)

