/*
 * DynamicFanout.h
 *
 *  Created on: 16/giu/2016
 *      Author: Lorenzo
 */

#ifndef SRC_PROTOCOL_DYNAMICFANOUT_H_
#define SRC_PROTOCOL_DYNAMICFANOUT_H_


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


#endif /* SRC_PROTOCOL_DYNAMICFANOUT_H_ */
