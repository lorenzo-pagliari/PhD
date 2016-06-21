/*
 * ProtocolManager.h
 *
 *  Created on: 19/mag/2015
 *      Author: Lorenzo
 */

#ifndef PROTOCOLMANAGER_H_
#define PROTOCOLMANAGER_H_

#include <omnetpp.h>
#include <DynamicFanout.h>
#include <AdvertiseLimit.h>

using namespace omnetpp;

class ProtocolManager {

private:
    DynamicFanout *dynamicFanout;
    AdvertiseLimit *advertiseLimit;

public:
    //constructor & destroyer
    ProtocolManager();
    virtual ~ProtocolManager();

    //getters
    int getDynamicFanout() const {return dynamicFanout->getValue();}
    int getAdvertiseLimit() const {return advertiseLimit->getValue();}

    //update methods
    void updateParameters(omnetpp::cSimpleModule *,BatteryManager *);
    void updateDynamicFanout(omnetpp::cSimpleModule *,BatteryManager *);
    void updateAdvertiseLimit(omnetpp::cSimpleModule *,BatteryManager *);
};

#endif /* PROTOCOLMANAGER_H_ */
