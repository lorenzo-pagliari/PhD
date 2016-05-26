/*
 * AdvertiseLimit.h
 *
 *  Created on: 19/mag/2015
 *      Author: Lorenzo
 */

#ifndef ADVERTISELIMIT_H_
#define ADVERTISELIMIT_H_

#include <Bound.h>

class AdvertiseLimit: public Bound {
public:
    AdvertiseLimit();
    virtual ~AdvertiseLimit();

    void updateValue(cSimpleModule *,BatteryManager *);

private:
    void checkValue();
    bool isPositive();
};

#endif /* ADVERTISELIMIT_H_ */
