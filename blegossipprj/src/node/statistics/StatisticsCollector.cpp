/*
 * StatisticsCollector.cpp
 *
 *  Created on: 21/giu/2016
 *      Author: Lorenzo
 */


#include "StatisticsCollector.h"

Define_Module(StatisticsCollector);

StatisticsCollector::StatisticsCollector() {
//    arrivalPercentage = new cLongHistogram();
//    arrivalTime = new cDoubleHistogram();

    listener = new StatisticsListener(&arrivalPercentage,&arrivalTime);
    getSimulation()->getSystemModule()->subscribe("arrival",listener);
    getSimulation()->getSystemModule()->subscribe("arrivalTime", listener);
}

//=================== DESTROYER =============================
StatisticsCollector::~StatisticsCollector() {

    if(isSubscribed("arrival",listener)){
        unsubscribe("arrival", listener);
    }

    if(isSubscribed("arrivalTime",listener)){
        unsubscribe("arrivalTime", listener);
    }
}

//**************************************************************
//**************************************************************
//**************************************************************

/*====================INITIALIZATION METHOD ==============================*/

void StatisticsCollector::initialize() {
//    getSimulation()->getSystemModule()->subscribe("arrival",listener);
//    getSimulation()->getSystemModule()->subscribe("arrivalTime", listener);

}

//**************************************************************
//**************************************************************
//**************************************************************

/*=======================RECEIVE METHODS ==========================*/

void StatisticsCollector::handleMessage(cMessage *msg)
{
}


void StatisticsCollector::finish(){
    this->arrivalPercentage.recordAs("arrivalPercentage");
    this->arrivalTime.recordAs("arrivalTime");

    if(isSubscribed("arrival",listener)){
            unsubscribe("arrival", listener);
        }

    if(isSubscribed("arrivalTime",listener)){
        unsubscribe("arrivalTime", listener);
    }
}
