// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef air_MultirotorRpcLibServer_hpp
#define air_MultirotorRpcLibServer_hpp

#include "common/Common.hpp"
#include <functional>
#include "vehicles/multirotor/api/MultirotorApiBase.h"
#include "api/RpcLibServerBase.hpp"


namespace msr { namespace airlib {

class MultirotorRpcLibServer : public RpcLibServerBase {
public:
    MultirotorRpcLibServer(WorldSimApiBase* simmode_api, string server_address, uint16_t port = 41451);
    virtual ~MultirotorRpcLibServer();

private:
    MultirotorApiBase* getDroneApi() const;
};

}} //namespace
#endif
