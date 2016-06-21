/*
 * BatteryManager.h
 *
 *  Created on: 19/mag/2015
 *      Author: Lorenzo
 */

#ifndef BATTERYMANAGER_H_
#define BATTERYMANAGER_H_

class BatteryManager {

private:
    int batteryLevel;

public:
    BatteryManager();
    BatteryManager(int);
    virtual ~BatteryManager();

    int getBatteryLevel() const {return batteryLevel;}
    void setBatteryLevel(int);

    void decreaseBatteryLevelIdle();
    void decreaseBatteryLevelTransmission();

private:
    void checkValue();
    bool isPositive();
};

#endif /* BATTERYMANAGER_H_ */
