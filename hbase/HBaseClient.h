#ifndef HBASECLIENT_H_
#define HBASECLIENT_H_

#include "gen-cpp2/hbase_types.h"
#include "gen-cpp2/THBaseServiceAsyncClient.h"
#include <folly/executors/IOThreadPoolExecutor.h>


using namespace apache::hadoop::hbase::thrift2;  // NOLINT

class HBaseClient final {
public:
    HBaseClient(const std::string ipAddr, const int32_t port = 9090);
    ~HBaseClient();

    /*
     * Just an example: FYI.THBaseService.h
     * You can implement other HBase APIs according to your needs.
     *
     * sync_exists, sync_existsAll, sync_get, sync_getMultiple, sync_put,
     * sync_checkAndPut, sync_putMultiple, sync_deleteSingle, sync_deleteMultiple,
     * sync_checkAndDelete, sync_increment, sync_append, sync_openScanner,
     * sync_getScannerRows, sync_closeScanner, sync_mutateRow, sync_getScannerResults,
     * sync_getRegionLocation, sync_getAllRegionLocations, sync_checkAndMutate
    */
    int get(const std::string tableName, const std::string rowKey);

private:
    std::shared_ptr<cpp2::THBaseServiceAsyncClient> client_;
};

#endif  // HBASECLIENT_H_

