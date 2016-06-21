/*
 * Bound.h
 *
 *  Created on: 16/giu/2016
 *      Author: Lorenzo
 */

#ifndef SRC_PROTOCOL_BOUND_H_
#define SRC_PROTOCOL_BOUND_H_

#include <omnetpp.h>
#include "BatteryManager.h"

using namespace omnetpp;

class Bound {

protected:
    int value;

public:
    Bound();
    virtual ~Bound();

    virtual int getValue() const {return value;}

    virtual void updateValue(cSimpleModule *,BatteryManager *)=0;
};


#endif /* SRC_PROTOCOL_BOUND_H_ */
