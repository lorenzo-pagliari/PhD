/*
 * ProtocolManager.h
 *
 *  Created on: 19/mag/2015
 *      Author: Lorenzo
 */

#ifndef PROTOCOLMANAGER_H_
#define PROTOCOLMANAGER_H_

#include <DynamicFanout.h>
#include <AdvertiseLimit.h>

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
    void updateParameters(cSimpleModule *,BatteryManager *);
    void updateDynamicFanout(cSimpleModule *,BatteryManager *);
    void updateAdvertiseLimit(cSimpleModule *,BatteryManager *);
};

#endif /* PROTOCOLMANAGER_H_ */
