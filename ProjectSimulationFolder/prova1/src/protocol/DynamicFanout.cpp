/*
 * DynamicFanout.cpp
 *
 *  Created on: 19/mag/2015
 *      Author: Lorenzo
 */

#include <DynamicFanout.h>
#include <math.h>

DynamicFanout::DynamicFanout() {

}

DynamicFanout::~DynamicFanout() {

}

//====================BOUND METHOD===================
void DynamicFanout::updateValue(cSimpleModule *node,BatteryManager *battery){

    int numNeighborDevices = node->gateSize("gate");
    double batFactor;
    double result;

    /*
     * This formula is:
     *
     *      x = battery % (10-100)
     *
     *      y= RAD.Q(0.2*x -1.9)/10
     */
    batFactor = sqrt(0.2*((double)battery->getBatteryLevel())-1.9)/10;

    /*
     * The total formula is
     *
     *              x = number of devices linked
     *
     *      new fanout = 1 - 0.0000004x^4 + RADQ(0.2*battery -1.9)/10 * x
     */
    result = 1 + batFactor * numNeighborDevices - 0.0000004 * pow(numNeighborDevices,4);

    /*
     * Bisogna calcolare il massimo della curva di 4° grado
     *
     * ax^4 + x = 0
     *
     * il valore di x risultante al massimo sarà il valore da utilizzare
     * nel confronto:
     *          numNeighborDevice < Xmax
     */

    //asintotic check
    //asintot utilized in 20*batteryFactor + 1

    /*
     * Asintoto da implementare
     *  y = 50% max [+1]
     */
    if((numNeighborDevices > 30) && (20*batFactor+1 > result)){
        value = ceil(20*batFactor+1);
    }else{
        value = ceil(result);
    }

    checkValue();
}

void DynamicFanout::checkValue(){
    if(!isPositive())
        value=1;
}

bool DynamicFanout::isPositive(){
    if(value > 0)
        return true;
    else
        return false;
}
