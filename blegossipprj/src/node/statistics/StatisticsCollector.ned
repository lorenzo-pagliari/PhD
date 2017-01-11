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

package node.statistics;

simple StatisticsCollector
{
    parameters:
//        @signal[arrival](type="bool");
//        @signal[arrivalTime](type="long");
//        @statistic[arrivalPerc](title="arrival perc"; source=count(arrival); record=histogram; interpolationmode=none);
//        @statistic[arrivalTime](title="arrival time"; source=arrivalTime; record=histogram; interpolationmode=none);

        @display("i=block/cogwheel;is=s");
}
