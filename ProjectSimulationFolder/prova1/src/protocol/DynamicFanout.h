/*
 * DynamicFanout.h
 *
 *  Created on: 19/mag/2015
 *      Author: Lorenzo
 */

#ifndef DYNAMICFANOUT_H_
#define DYNAMICFANOUT_H_

#include <Bound.h>

class DynamicFanout: public Bound {
public:
    DynamicFanout();
    virtual ~DynamicFanout();

    void updateValue(omnetpp::cSimpleModule *,BatteryManager *);

private:
    void checkValue();
    bool isPositive();
};

#endif /* DYNAMICFANOUT_H_ */
