/*
 * ProtocolManager.h
 *
 *  Created on: 16/giu/2016
 *      Author: Lorenzo
 */

#ifndef SRC_PROTOCOL_PROTOCOLMANAGER_H_
#define SRC_PROTOCOL_PROTOCOLMANAGER_H_

#include "DynamicFanout.h"
#include "AdvertiseLimit.h"

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


#endif /* SRC_PROTOCOL_PROTOCOLMANAGER_H_ */
