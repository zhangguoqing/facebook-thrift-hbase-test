# facebook thrift v2018.08.20.00:
# https://github.com/facebook/fbthrift/tree/v2018.08.20.00
#
# hbase-1.4.9(thrift2/hbase.thrift):
# https://github.com/apache/hbase/blob/master/hbase-thrift/src/main/resources/org/apache/hadoop/hbase/thrift2/hbase.thrift

add_custom_command(
    OUTPUT
        gen-cpp2/THBaseService.cpp
        gen-cpp2/THBaseServiceAsyncClient.cpp
        gen-cpp2/THBaseService_processmap_binary.cpp
        gen-cpp2/THBaseService_processmap_compact.cpp
        gen-cpp2/hbase_constants.cpp
        gen-cpp2/hbase_data.cpp
        gen-cpp2/hbase_types.cpp
    COMMAND "${CMAKE_HOME_DIRECTORY}/facebook-thrift-install/bin/thrift1" "--strict" "--allow-neg-enum-vals" "--templates" "${CMAKE_HOME_DIRECTORY}/facebook-thrift-install/include/thrift/templates" "--gen" "mstch_cpp2:include_prefix=\"interface\",process_in_event_base,stack_arguments" "-o" "." "./hbase.thrift"
    DEPENDS hbase.thrift
)

add_library(
    hbase_thrift_obj OBJECT
    gen-cpp2/THBaseService.cpp
    gen-cpp2/THBaseServiceAsyncClient.cpp
    gen-cpp2/THBaseService_processmap_binary.cpp
    gen-cpp2/THBaseService_processmap_compact.cpp
    gen-cpp2/hbase_constants.cpp
    gen-cpp2/hbase_data.cpp
    gen-cpp2/hbase_types.cpp
)

add_library(
    hbase_client_obj OBJECT
    HBaseClient.cpp
)

add_subdirectory(test)
