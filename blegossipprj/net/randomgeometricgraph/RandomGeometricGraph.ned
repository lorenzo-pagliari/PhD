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

package blegossipprj.net.randomgeometricgraph;

import node.models.RandomGeometricNode;
import node.statistics.StatisticsCollector;

network RandomGeometricGraph {
    
    parameters:
        int radius = default(3);
        int netSize = default(10);
        int startIndex = intuniform(0,netSize-1);
        
//        @signal[arrival](type="bool");
//        @signal[arrivalTime](type="double");
//        @statistic[arrivalPerc](title="arrival perc"; source="arrival"; record=histogram; interpolationmode=none);
//        @statistic[arrivalTime](title="arrival time"; source="arrivalTime"; record=histogram; interpolationmode=none);

//        @display("bgg=10");
    
    types:
        channel BTChannel extends ned.DatarateChannel{
            datarate = 1Mbps;
         	delay = 10ms;
        }
        
    submodules:
        rgnv[netSize]: RandomGeometricNode;
//        n1: RandomGeometricNode;
//        n2: RandomGeometricNode;
//        n3: RandomGeometricNode;
		sc: StatisticsCollector;
    connections:
        
		for i = 0..netSize-2, for j=i+1..netSize-1 {
		     rgnv[i].gate++ <--> BTChannel <--> rgnv[j].gate++ if (radius > sqrt((rgnv[i].xCoord - rgnv[j].xCoord)*(rgnv[i].xCoord - rgnv[j].xCoord) + 
            																	(rgnv[i].yCoord - rgnv[j].yCoord)*(rgnv[i].yCoord - rgnv[j].yCoord)));
        }
        
}