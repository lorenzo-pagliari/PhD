/*
 * AdvertiseLimit.cpp
 *
 *  Created on: 19/mag/2015
 *      Author: Lorenzo
 */

#include <AdvertiseLimit.h>

AdvertiseLimit::AdvertiseLimit() {

}

AdvertiseLimit::~AdvertiseLimit() {
}

//====================BOUND METHOD===================
void AdvertiseLimit::updateValue(omnetpp::cSimpleModule *node, BatteryManager *battery){

    int numNeighborDevices = node->gateSize("gate");
    double batFactor;
    double result;


    /*
     *  VERSION 0.1
     * This formula is:
     *
     *      x = battery % (10 - 100)
     *
     *      y= x/100
     *
     *
     * The total formula n°0.1 is
     *
     *              x = number of devices linked
     *
     *      new adv limit = %battery*(-0.92^(x-20) +5)
     */
    //batFactor = (double)battery->getBatteryLevel()/(double)100;
    //result = batFactor * (-pow(0.92,numNeighborDevices-20) + 5);

    /*
     * VERSION 0.2
     * The total formula n°1 is
     *
     *              x = number of devices linked
     *
     *      new adv limit = %battery*(ln(2x)+1)
     */
     //result = batFactor * (log(2*numNeighborDevices) + 1);

    /*
     * VERSION 1
     * The total formula n°1 is
     *
     *              x = number of devices linked
     *
     *      new adv limit = x^0.5 + 1
     */
    //result = sqrt(numNeighborDevices) + 1;

    /*
     * VERSION 2
     * The total formula n°2 is
     *
     *              x = number of devices linked
     *
     *      new adv limit = ln(2x)+1
     */
    result = log(2*numNeighborDevices) + 1;

    /*
     * VERSION 3
     * The total formula n°3 is
     *
     *              x = number of devices linked
     *
     *      new adv limit = AVG(ln(2x)+1 + log(2x)+1)
     */
    //result = (log(2*numNeighborDevices) + log10(2*numNeighborDevices) + 2)/2;

    /*
     * VERSION 4
     * The total formula n°4 is
     *
     *              x = number of devices linked
     *
     *      new adv limit = 2*ln(x)
     */
    //result = 2 * log(numNeighborDevicess) + 1;

    value = ceil(result);

    checkValue();
}

void AdvertiseLimit::checkValue(){
    if(!isPositive())
        value=1;
}

bool AdvertiseLimit::isPositive(){
    if(value > 0)
        return true;
    else
        return false;
}
