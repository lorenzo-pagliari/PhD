//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef SRC_NODE_LISTENERS_STATISTICSLISTENER_H_
#define SRC_NODE_LISTENERS_STATISTICSLISTENER_H_

#include <omnetpp.h>
//#include "StatisticsCollector.h"

using namespace omnetpp;

class StatisticsListener : public cListener
{

private:
//    StatisticsCollector *sc;
    cHistogram *ap;
    cHistogram *at;

public:
    //Constructor
    StatisticsListener();
//    StatisticsListener(StatisticsCollector *);
    StatisticsListener(cHistogram *,cHistogram *);

    //Destructor
    virtual ~StatisticsListener();

    virtual void receiveSignal(cComponent *src, simsignal_t id, bool value, cObject *details);
//    virtual void receiveSignal(cComponent *src, simsignal_t id, long value, cObject *details);
    virtual void receiveSignal(cComponent *src, simsignal_t id, double value, cObject *details);
};

#endif /* SRC_NODE_LISTENERS_STATISTICSLISTENER_H_ */
