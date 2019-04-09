cmake_minimum_required(VERSION 3.0.0)

project("HBase C++ Client(Facebook Thrift)" C CXX)
enable_testing()
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "_build")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "_build")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "_build")

set(FACEBOOK_THRIFT_HBASE_TEST_HOME ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-DFACEBOOK_THRIFT_HBASE_TEST_HOME=${FACEBOOK_THRIFT_HBASE_TEST_HOME})

add_compile_options(-Wall)
add_compile_options(-Werror)
add_compile_options(-Wunused-parameter)
add_compile_options(-Wshadow)

include_directories(SYSTEM ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/hbase)
include_directories(SYSTEM ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/hbase/gen-cpp2)
include_directories(SYSTEM ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-thrift-install/include)
include_directories(SYSTEM ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-folly-install/include)
include_directories(SYSTEM ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-wangle-install/include)
include_directories(SYSTEM ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-zstd-install/include)
include_directories(SYSTEM ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/double-conversion-install/include)
include_directories(SYSTEM ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/gflags-install/include)

# facebook thrift version is 2018.08.20.00: https://github.com/facebook/fbthrift/tree/v2018.08.20.00
link_directories(
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-thrift-install/lib
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-folly-install/lib
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-wangle-install/lib
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-zstd-install/lib
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/double-conversion-install/lib
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/gflags-install/lib
)
# some facebook libraries: fbthrift, folly, zstd
set(FACEBOOK_LIBRARIES
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-thrift-install/lib/libthriftcpp2.a
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-thrift-install/lib/libthrift.a
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-thrift-install/lib/libthriftprotocol.a
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-thrift-install/lib/libasync.a
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-thrift-install/lib/libprotocol.a
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-thrift-install/lib/libtransport.a
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-thrift-install/lib/libconcurrency.a
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-thrift-install/lib/libsecurity.a
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-thrift-install/lib/libthriftfrozen2.a
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-thrift-install/lib/libthrift-core.a
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-folly-install/lib/libfolly.a
    ${FACEBOOK_THRIFT_HBASE_TEST_HOME}/facebook-zstd-install/lib/libzstd.a
)

add_subdirectory(hbase)

add_custom_target(
    distclean
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND "rm" "-rf" "${FACEBOOK_THRIFT_HBASE_TEST_HOME}/hbase/gen-cpp2"
    COMMAND "find" "." "-name" "Testing" "|" "xargs" "rm" "-rf"
    COMMAND "find" "." "-name" "CMakeFiles" "|" "xargs" "rm" "-rf"
    COMMAND "find" "." "-name" "CMakeCache.txt" "|" "xargs" "rm" "-f"
    COMMAND "find" "." "-name" "cmake_install.cmake" "|" "xargs" "rm" "-f"
    COMMAND "find" "." "-name" "CTestTestfile.cmake" "|" "xargs" "rm" "-f"
    COMMAND "find" "." "-name" "Makefile" "|" "xargs" "rm" "-f"
)

