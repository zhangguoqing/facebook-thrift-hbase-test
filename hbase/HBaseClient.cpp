#include "HBaseClient.h"
#include <iostream>
#include <folly/io/async/EventBaseManager.h>
#include <thrift/lib/cpp2/async/ReconnectingRequestChannel.h>
#include <thrift/lib/cpp/async/TAsyncSocket.h>
#include <thrift/lib/cpp2/async/HeaderClientChannel.h>


using namespace apache::hadoop::hbase::thrift2;

HBaseClient::HBaseClient(const std::string ipAddr, const int32_t port) {
    std::cout << "Connect to the HBase thrift server "
              << ipAddr << ":" << port << " ..." << std::endl;

    auto evb = folly::EventBaseManager::get()->getEventBase();
    auto channel = apache::thrift::ReconnectingRequestChannel::newChannel(
        *evb, [ipAddr, port] (folly::EventBase& eb) mutable {
            static thread_local int connectionCount = 0;
            VLOG(2) << "Connecting to " << ipAddr << ":" << port
                    << " for " << ++connectionCount << " times";
            std::shared_ptr<apache::thrift::async::TAsyncSocket> socket;
            eb.runImmediatelyOrRunInEventBaseThreadAndWait(
                [&socket, &eb, ipAddr, port]() {
                    socket = apache::thrift::async::TAsyncSocket::newSocket(
                        &eb, ipAddr, port, 1000);
            });
            auto headerClientChannel =  apache::thrift::HeaderClientChannel::newChannel(socket);
            headerClientChannel->setProtocolId(apache::thrift::protocol::T_BINARY_PROTOCOL);
            headerClientChannel->setClientType(THRIFT_UNFRAMED_DEPRECATED);
            return headerClientChannel;
    });

    client_.reset(new cpp2::THBaseServiceAsyncClient(std::move(channel)), [evb](auto* p) {
        evb->runImmediatelyOrRunInEventBaseThreadAndWait([p] {
            delete p;
        });
    });
}

int HBaseClient::get(const std::string tableName, const std::string rowKey) {
    std::cout << "HBaseClient=========TEST=========TEST=========TEST=========TEST" << std::endl;
    cpp2::TResult tResult;
    cpp2::TGet tGet;
    tGet.set_row(rowKey);
    try {
        if (client_->sync_exists(tableName, tGet)) {
            std::cout << "The target table is exist..." << std::endl;
        }
        client_->sync_get(tResult, tableName, tGet);
        std::vector<cpp2::TColumnValue> list = tResult.columnValues;
        std::vector<cpp2::TColumnValue>::const_iterator iter;
        for (iter = list.begin(); iter != list.end(); iter++) {
            std::cout << (*iter).family.c_str() << ", " << (*iter).qualifier.c_str()
                      << ", " << (*iter).value.c_str() << std::endl;
        }
    } catch (const cpp2::TIOError &ex) {
        std::cout << "TIOError: " << ex.message << std::endl;
        return 1;
    }
    std::cout << "HBaseClient=========TEST=========TEST=========TEST=========TEST" << std::endl;
    return 0;
}

HBaseClient::~HBaseClient() {
}

