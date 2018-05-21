// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef msr_airlib_vehicles_MultiRotorParamsFactory_hpp
#define msr_airlib_vehicles_MultiRotorParamsFactory_hpp

#include "vehicles/multirotor/configs/Px4MultiRotor.hpp"
#include "vehicles/multirotor/controllers/MavLinkMultirotorApi.hpp"
#include "vehicles/multirotor/configs/RosFlightQuadX.hpp"
#include "vehicles/multirotor/configs/SimpleFlightQuadX.hpp"


namespace msr { namespace airlib {

class MultiRotorParamsFactory {
public:
    static std::unique_ptr<MultiRotorParams> createConfig(const AirSimSettings::VehicleSetting* vehicle_setting, std::shared_ptr<const SensorFactory> sensor_factory)
    {
        std::unique_ptr<MultiRotorParams> config;

        if (vehicle_setting->vehicle_type == AirSimSettings::kVehicleTypePX4) {
            config.reset(new Px4MultiRotor(* static_cast<const AirSimSettings::PX4VehicleSetting*>(vehicle_setting),
                sensor_factory));
        } else if (vehicle_setting->vehicle_type == AirSimSettings::kVehicleTypeRosFlight) {
            config.reset(new RosFlightQuadX(vehicle_setting, sensor_factory));
        } else if (vehicle_setting->vehicle_type == "" || //default config
            vehicle_setting->vehicle_type == AirSimSettings::kVehicleTypeSimpleFlight) {
            config.reset(new SimpleFlightQuadX(vehicle_setting, sensor_factory));
        } else
            throw std::runtime_error(Utils::stringf(
                "Cannot create vehicle config because vehicle name '%s' is not recognized", 
                vehicle_setting->vehicle_name.c_str()));

        config->initialize();

        return config;
    }
};

}} //namespace
#endif
