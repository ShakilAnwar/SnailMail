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

package snailmail.simulations;

import snailmail.Village;
import snailmail.House;
import snailmail.PostOffice;
import snailmail.DistributionCenter;

network SnailMailNetwork
{
    parameters:
//      Number of villages.
        int numVillages = 5; // not default, fixed.
    submodules:
        village[numVillages]: Village;
        distribution_server: DistributionCenter; 
    connections:
        village[0].village_gate <--> distribution_server.distribution_gate[0];
        distribution_server.distribution_gate[1] <-->  village[1].village_gate;
        village[2].village_gate <--> distribution_server.distribution_gate[2];
        distribution_server.distribution_gate[3] <-->  village[3].village_gate;
        village[4].village_gate <--> distribution_server.distribution_gate[4];
}
