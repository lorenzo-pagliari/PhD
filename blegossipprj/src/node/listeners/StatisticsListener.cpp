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

#include <StatisticsListener.h>

StatisticsListener::StatisticsListener()
{
}

//StatisticsListener::StatisticsListener(StatisticsCollector *statisticsCollector)
//{
//    this->sc = statisticsCollector;
//}

StatisticsListener::~StatisticsListener()
{
}

StatisticsListener::StatisticsListener(cHistogram *ap, cHistogram *at)
{
    this->ap = ap;
    this->at = at;
}

void StatisticsListener::receiveSignal(cComponent *src, simsignal_t id, bool value, cObject *details){
    this->ap->collect(value);
}
//
//void StatisticsListener::receiveSignal(cComponent *src, simsignal_t id, long value, cObject *details){
//    this->ap->collect(value);
//}

void StatisticsListener::receiveSignal(cComponent *src, simsignal_t id, double value, cObject *details){
    this->at->collect(value);
}
