/*
 * AdvertisingLimit.h
 *
 *  Created on: 16/giu/2016
 *      Author: Lorenzo
 */

#ifndef SRC_PROTOCOL_ADVERTISELIMIT_H_
#define SRC_PROTOCOL_ADVERTISELIMIT_H_

#include <Bound.h>

class AdvertiseLimit: public Bound {
public:
    AdvertiseLimit();
    virtual ~AdvertiseLimit();

    void updateValue(omnetpp::cSimpleModule *,BatteryManager *);

private:
    void checkValue();
    bool isPositive();
};

#endif /* SRC_PROTOCOL_ADVERTISELIMIT_H_ */
