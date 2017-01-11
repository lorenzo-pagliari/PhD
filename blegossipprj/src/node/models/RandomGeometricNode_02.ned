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

package node.models;

import node.INode;
//import coordinate.bidimensional.Coordinate2D;

simple RandomGeometricNode_02 like INode //extends Coordinate2D
{
    parameters:
        int d = default(0);
        int batteryLevel = default(100);
        bool startTx = default(false);
        int areaMinHeight = default(0);
        int areaMaxHeight = default(10);
        int areaMinWidth = default(0);
        int areaMaxWidth = default(10);
        double xCoord = uniform(areaMinWidth, areaMaxWidth);
        double yCoord = uniform(areaMinHeight, areaMaxHeight);
	
		@class(RandomGeometricNode);
		@signal[arrival](type=bool);
        @signal[arrivalTime](type=double);
		
        @display("i=misc/node_vs;is=vs");
    //      display radius non è utile perchè anche lui
    //		si basa sui pixel
//          	@display("r=200");
    gates:
        inout gate[];
}
