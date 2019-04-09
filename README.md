# facebook-thrift-hbase-test

## Install some other libs

`rm -rf /path/facebook-thrift-hbase-test/*-install/*`

`yum install gcc gcc-c++ cmake automake boost-devel libtool lz4-devel lzma-devel snappy snappy-devel zlib-devel glog-devel gflags-devel scons double-conversion-devel openssl-devel libevent-devel libdwarf-dev libelf-dev libunwind8-dev bz2 bz2-devel`

 - double-conversion: https://github.com/google/double-conversion
 - facebook-wangle: https://github.com/facebook/wangle
 - facebook-zstd: https://github.com/facebook/zstd
 - gflags: https://github.com/gflags/gflags


## Build the facebook folly

> FYI. https://github.com/facebook/folly/tree/v2018.08.20.00#build-notes


## Build the facebook thrift (fbthrift)

> FYI. https://github.com/facebook/fbthrift#building


## Run

`cd /path/facebook-thrift-hbase-test/`

`cmake3 .`

`make`

`./hbase/test/_build/hbase_client_test`

> [==========] Running 1 test from 1 test case.
> [----------] Global test environment set-up.
> [----------] 1 test from HbaseClientTest
> [ RUN      ] HbaseClientTest.SimpleTest
> Connect to the HBase thrift server 127.0.0.1:9096 ...
> HBaseClient=========TEST=========TEST=========TEST=========TEST
> The target table is exist...
> account, idcard, 42012319861234561230
> account, name, zhangsan
> account, password, 123456
> address, city, shengzhen
> address, province, guangdong
> info, age, 29
> info, sex, A
> userid, id, 001
> HBaseClient=========TEST=========TEST=========TEST=========TEST
> [       OK ] HbaseClientTest.SimpleTest (52 ms)
> [----------] 1 test from HbaseClientTest (52 ms total)
> 
> [----------] Global test environment tear-down
> [==========] 1 test from 1 test case ran. (53 ms total)
> [  PASSED  ] 1 test.

