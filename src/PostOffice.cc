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

#include "PostOffice.h"

Define_Module(PostOffice);

void PostOffice::initialize() {

}

void PostOffice::handleMessage(cMessage *msg) {

//    EV<< "Message send by post office. \n";
//    send(msg, "out_gate$o");

    EV << "Message received.\n";
    // is this a self-timer? no currently used.
    if (msg->isSelfMessage()) {
        EV << "Self-timers are currently not in use, stop simulation.\n";
        endSimulation();
    }
    // if a message is received for my village, forward it to the house.
    if ((int) msg->par("destVillage")
            == (int) getParentModule()->par("villageID")) {
        EV << "Same village, send directly to house.\n";
        // find out which house
        int house = msg->par("destHouse");
        // get a pointer to the out gate
        cGate *where = gate("gate$o", house);
        // send it out
        send(msg, where);


    } else {
        EV << "Other village, send to distributor.\n";
        send(msg, "out_gate$o");
    }
}
