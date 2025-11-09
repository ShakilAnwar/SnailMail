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

#include "DistributionCenter.h"

Define_Module(DistributionCenter);

void DistributionCenter::initialize() {

}

void DistributionCenter::handleMessage(cMessage *msg) {
// If there is self message the simulation going to send.
    if (msg->isSelfMessage()) {
           EV << "Self-timers are currently not in use, stop simulation.\n";
           endSimulation();
       }
    EV << "Message received by the Distributor. \n";
//    Finding out the letter belong to which village.
    int village = msg->par("destVillage");
    cGate *correctvillage = gate("distribution_gate$o", village);
//    Sending the letter the desired village.
    send(msg, correctvillage);

}
