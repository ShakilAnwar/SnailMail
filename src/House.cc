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

#include "House.h"

Define_Module(House);

void House::initialize() {
    // send some messages to other houses / other villages
    // find out, which house and village we are
    int houses = getParentModule()->par("numHouses");
    int villages = getParentModule()->getParentModule()->par("numVillages");
    EV << "We have " << houses << " houses per village and " << villages
              << " villages.\n";
    // select randomly some village and house
    int destVil = intuniform(0, villages - 1);
    int destHouse = intuniform(0, houses - 1);
    cMessage *letter1 = new cMessage("Sending Letter");
    letter1->addPar("destVillage");
    letter1->par("destVillage") = destVil;
    letter1->addPar("destHouse");
    letter1->par("destHouse") = destHouse;
    sendDelayed(letter1, 50, "gate$o");
}

void House::handleMessage(cMessage *msg) {
    // is this a self-timer? no currently used.
    if (msg->isSelfMessage()) {
        EV << "Self-timers are currently not in use, stop simulation.\n";
        endSimulation();
    }
    if (((int) msg->par("destVillage")
            == (int) getParentModule()->par("villageID"))
            && ((int) msg->par("destHouse") == (int) par("houseID"))) {
        // letter received and checked that it was correctly sent. simply print out a debug message
        EV << "Letter received.\n";

//        After the letter received, the house send a reply to sender.
        cMessage *reply_message = new cMessage("Sending a reply message to sender");
//        Adding a dealy of 2 dayes = 172800 s from sending the reply message.
        sendDelayed(reply_message, 172800, "gate$o");
//        Simply print a debug message to the replied message.
        EV << "Successfully send a reply to sender.\n";
        // delete the message
        delete msg;
    }
}
