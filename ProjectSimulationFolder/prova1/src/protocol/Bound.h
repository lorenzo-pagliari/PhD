/*
 * Bound.h
 *
 *  Created on: 19/mag/2015
 *      Author: Lorenzo
 */

#ifndef BOUND_H_
#define BOUND_H_

#include <omnetpp.h>
#include <BatteryManager.h>

class Bound {

protected:
    int value;

public:
    Bound();
    virtual ~Bound();

    virtual int getValue() const {return value;}

    virtual void updateValue(omnetpp::cSimpleModule *,BatteryManager *)=0;
};

#endif /* BOUND_H_ */
