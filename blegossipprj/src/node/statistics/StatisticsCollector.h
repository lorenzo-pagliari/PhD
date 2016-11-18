/*
 * StatisticsCollector.h
 *
 *  Created on: 21/giu/2016
 *      Author: Lorenzo
 */

#ifndef SRC_NODE_STATISTICS_STATISTICSCOLLECTOR_H_
#define SRC_NODE_STATISTICS_STATISTICSCOLLECTOR_H_

#include <omnetpp.h>
#include "StatisticsListener.h"

using namespace omnetpp;

class StatisticsCollector: public cSimpleModule{

private:
    StatisticsListener *listener;
//    cLongHistogram arrivalPercentage;
    cHistogram arrivalPercentage;
    cHistogram arrivalTime;


public:
    //Constructor
    StatisticsCollector();
    //Destroyer
    virtual ~StatisticsCollector();


    //Trasmission & Receive methods
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *);
    virtual void finish();
};




#endif /* SRC_NODE_STATISTICS_STATISTICSCOLLECTOR_H_ */

