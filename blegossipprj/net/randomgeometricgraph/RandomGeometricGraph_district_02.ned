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


import node.statistics.StatisticsCollector;
import node.models.RandomGeometricNode_02;
import blegossipprj.net.district.District_02;

network RandomGeometricGraph_district_02
{
    parameters:
        int radius = default(15);
        int netSize = default(10);
        int startIndex = intuniform(0,netSize-1);
        int numberOfDistricts = default(1);

    types:
        channel BTChannel extends ned.DatarateChannel
        {
            datarate = 1Mbps;
            delay = 10ms;
        }

    submodules:
        sc: StatisticsCollector;
        dv[numberOfDistricts]: District_02 {
//            @display("p=,,matrix");
			numbNodes = netSize/numberOfDistricts;
			ID = index;
			xCoord = 0 + this.width*index;
			yCoord = 0;
		}
		rgnv[netSize]: RandomGeometricNode_02 {
		    d = intuniform(0, numberOfDistricts-1);
			areaMinWidth = dv[this.d].xCoord;
			areaMaxWidth = dv[this.d].xCoord+dv[this.d].width;
			areaMinHeight = dv[this.d].yCoord;
			areaMaxHeight = dv[this.d].yCoord+dv[this.d].height;
//			@display("r=250");
		}
		
    connections:
		for i=0..netSize-2, for j=i+1..netSize-1 {
            rgnv[i].gate++ <--> BTChannel <--> rgnv[j].gate++ if (radius > sqrt((rgnv[i].xCoord - rgnv[j].xCoord)*(rgnv[i].xCoord - rgnv[j].xCoord) + 
            																	(rgnv[i].yCoord - rgnv[j].yCoord)*(rgnv[i].yCoord - rgnv[j].yCoord)));
        }
        

}
