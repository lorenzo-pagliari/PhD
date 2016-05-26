/*
 * ProtocolManager.cpp
 *
 *  Created on: 19/mag/2015
 *      Author: Lorenzo
 */

#include <ProtocolManager.h>

//================CONSTRUCTOR & DESTROYER=================
ProtocolManager::ProtocolManager() {
    dynamicFanout = new DynamicFanout();
    advertiseLimit = new AdvertiseLimit();
}

ProtocolManager::~ProtocolManager() {
    delete dynamicFanout;
    delete advertiseLimit;
}



//=======================UPDATE METHODS========================
void ProtocolManager::updateParameters(cSimpleModule *node,BatteryManager *battery){
    updateAdvertiseLimit(node,battery);
    updateDynamicFanout(node,battery);
}


void ProtocolManager::updateDynamicFanout(cSimpleModule *node,BatteryManager *battery){
    dynamicFanout->updateValue(node,battery);
}


void ProtocolManager::updateAdvertiseLimit(cSimpleModule *node,BatteryManager *battery){
    advertiseLimit->updateValue(node,battery);
}
