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

package snailmail;

import snailmail.DistributionCenter;
import snailmail.House;
import snailmail.PostOffice;

module Village
{
    parameters:
        @display("i=misc/town_l;bgb=252,184");
        int villageID = default(-1);
        int numHouses = 3; // not default, fixed
    gates:
        inout village_gate;
    submodules:
        house[numHouses]: House;
        post: PostOffice;
//        distribution: DistributionCenter;
    connections:
        house[0].gate <--> post.gate[0];
        house[1].gate <--> post.gate[1];
        house[2].gate <--> post.gate[2];
        post.out_gate <--> village_gate;
}
