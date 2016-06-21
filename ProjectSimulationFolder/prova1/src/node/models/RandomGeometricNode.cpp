/*
 * RandomGeometricNode.cpp
 *
 *  Created on: 28/apr/2015
 *      Author: Lorenzo
 */

#include "RandomGeometricNode.h"

Define_Module(RandomGeometricNode);

//================== CONSTRUCTOR ====================
RandomGeometricNode::RandomGeometricNode() {
    message = NULL;
    timer = NULL;
    protocolManager = NULL;
    batteryManager = NULL;
    periodicActionsTimer = NULL;
    advCounter = 0;
    txCounter = 0;
    busy = false;
    gateBinded = -1;
    btFsaManager = NULL;
}

//=================== DESTROYER =============================
RandomGeometricNode::~RandomGeometricNode() {
    if(timer!=NULL) cancelAndDelete(timer);
    if(periodicActionsTimer!=NULL) cancelAndDelete(periodicActionsTimer);
    delete message;
    delete protocolManager;
    delete batteryManager;
    delete btFsaManager;
}

//**************************************************************
//**************************************************************
//**************************************************************

//=============GETTERS========================
double RandomGeometricNode::getXcoordinate(){
    return this->xCoord;
}

double RandomGeometricNode::getYcoordinate(){
    return this->yCoord;
}

//==============SETTERS====================
void RandomGeometricNode::setXcoordinate(double x){
    this->xCoord = x;
}

void RandomGeometricNode::setYcoordinate(double y){
    this->yCoord = y;
}

//**************************************************************
//**************************************************************
//**************************************************************

/*====================INITIALIZATION METHOD ==============================*/

void RandomGeometricNode::initialize() {

//    arrivalSignal = registerSignal("arrival");
//    arrivalTimeSignal = registerSignal("arrivalTime");
//
//    this->xCoord = par("xCoord");
//    this->yCoord = par("yCoord");
//    printf("nodo %s creato in %d-%d\n",this->getIndex(), this->getXcoordinate(),this->getYcoordinate());
//    batteryManager = new BatteryManager(uniform(15, 100));
//    protocolManager = new ProtocolManager();
//    periodicActionsTimer = new cMessage("periodic actions");
//    timer = new cMessage("timeout");
//    btFsaManager = new BTFsaManager();

//    nodeInitializazion();

//    scheduleAt(simTime()+0.3,periodicActionsTimer);

    //This way is for forced parameter setting in .ini file
    //if(par("startTx")){

    //This way, get a new starting node for each repetition
//    if(getIndex() == getAncestorPar("startIndex").longValue()){
//        //50xriga = 205 caratteri
//        /*
//        message = BTMessageGenerator::createDataMessage(
//                "Ciao come stai ? Tutto bene ? Io, si grazie, e tu?"
//                "Anche io tutto ok grazie....anche se con sto tempo"
//                "mi fa un pò freddo....eh sì in effetti sta pioggia"
//                "ha un pò stufato....ci manca l'afa da 40gradi all'ombra");
//        */
//
//        message = BTMessageGenerator::createDataMessage("Oggi c'è il sole, che bello", 1, MB);
//
//        /*
//         * starting state
//         * is equivalent to the call to advertising(),
//         * but in this way is possible to see the visual
//         * effect of the first broadcasting
//         */
//        start();
//
//    }else{
//        initiating();
//    }
    initiating();
}

void RandomGeometricNode::nodeInitializazion()
{
    btFsaManager->standby();
    protocolManager->updateParameters(this,batteryManager);
    updateTagDisplayString();


    int numGate = gateSize("gate");
/*
    for(int i=0; i < numGate; ++i){
        gate("gate$i", i)->setDeliverOnReceptionStart(true);
    }
*/
}

//**************************************************************
//**************************************************************
//**************************************************************

/*=======================RECEIVE METHODS ==========================*/

void RandomGeometricNode::handleMessage(cMessage *msg)
{

    BTMessage *btmsg = NULL;
    BTMessage *temp = NULL;


    if(msg == periodicActionsTimer){

        //Time for periodical actions
        if(btFsaManager->getState() != BTState::STANDBY){
            periodicActions();
        }
    }else{

        if(dynamic_cast<BTMessage * >(msg) != NULL){
            btmsg = check_and_cast<BTMessage *>(msg);
        }

        switch(btFsaManager->getState())
        {
            case STANDBY: delete btmsg; break;
            case SCANNING: delete btmsg; break;
            case ADVERTISING:

                if(msg == timer){
                    //no reply to ADV_IND
                    //re-broadcast
                    if(advCounter < protocolManager->getAdvertiseLimit()){
                        advertising();
                    }else{
                        standby();
                    }

                }else{

                    //CONN_REQ check
                    if(btmsg->getOpcode() == CONN_REQ &&
                        this->message!=NULL && strcmp(btmsg->getPdu(),this->message->getTag())==0){

                        //request confermed, reset timer
                        cancelEvent(timer);
                        advCounter = 0;
                        gateBinded = btmsg->getArrivalGate()->getIndex();

                        busy = true;
                        connectionSlave();
                    }

                    delete btmsg;
                }
                break;

           case INITIATING:

                //check ADV_IND
                if(btmsg->getOpcode() == ADV_IND){

                    //check if message has already been received
                    if(this->message==NULL || strcmp(btmsg->getPdu(),this->message->getTag())!=0){

                        //have not the message, send a CONN_REQ
                        temp = BTMessageGenerator::createConnReqMessage(btmsg->getPdu());
                        forwardMessage(temp,btmsg->getArrivalGate()->getIndex());

                        gateBinded = btmsg->getArrivalGate()->getIndex();

                        delete temp;
                        delete btmsg;

                        busy = true;
                        connectionMaster();
                    }
                }

                break;

            case CONNECTION_MASTER:

                if(msg == timer){
                    //no response to CONN_REQ
                    //switch back to initiating mode
                    busy = false;
                    gateBinded = -1;
                    initiating();

                }else{

                    //check is not busy and if the message came from the correct node
                    if(!busy || btmsg->getArrivalGate()->getIndex() == gateBinded){

                        //This first IF is only a custom soluzion to avoid a simulator problem/convention.
                        //Is needed only to cancel the timer and let to wait the full trasmission of the packet.
                        if(btmsg->getOpcode() == START_TX){

                            busy = true;
                            cancelEvent(timer);

                            delete btmsg;

                        }else if(btmsg->getOpcode() == DATA && (this->message==NULL || btmsg != this->message)){
                            //check if is DATA and the message is not been received yet

                            busy = true;
                            cancelEvent(timer);

                            //massage saved
                            this->message = btmsg->dup();

                            //signal to save statistic on the arrival percentage
                            emit(arrivalSignal, true);

                            //Update Battery Level
                            decreaseBatteryLevelTransmission();

                            //Send ack
                            temp = BTMessageGenerator::createAckMessage("");
                            forwardMessage(temp,gateBinded);

                            delete btmsg;
                            delete temp;

                         }else if(btmsg->getOpcode() == TERMINATE_TX){

                             //signal to save statistic on the arrival time
                             //full transmission completed
                             emit(arrivalTimeSignal, btmsg->getArrivalTime().dbl());

                             //trasmission ended
                             temp = BTMessageGenerator::createTerminateTxMessage("");
                             forwardMessage(temp,gateBinded);

                             delete temp;
                             delete btmsg;
                             busy = false;
                             gateBinded = -1;
                             advertising();
                         }
                    }
                }

                break;

            case CONNECTION_SLAVE:

                if(!busy || btmsg->getArrivalGate()->getIndex() == gateBinded){

                    //chech if is START TX packet
                    if(btmsg->getOpcode() == START_TX){

                        //THIS PART IS A CUSTOM SOLUTION TO AVOID A SIMULATOR PROBLEM/CONVENTION
                        //IS NEEDED ONLY TO RESET THE TIMER ON THE DESTINATION NODE AND LET IT TO
                        //WAIT THE WHOLE MESSAGE TRANSMISSION
                        //*****************************************************
                        //SEND A START_TX TOO
                        temp = BTMessageGenerator::createStartTxMessage("");
                        forwardMessage(temp,gateBinded);
                        delete temp;
                        //*****************************************************

                        //send the message
                        forwardMessage(message,gateBinded);

                        delete btmsg;

                        txCounter++;

                        //Update Battery Level
                        decreaseBatteryLevelTransmission();

                        //retrasmission timeout
                        //timer = createTimeout();
                        //scheduleAt(simTime()+2.0,timer);

                    }else if(btmsg->getOpcode() == ACK){

                        //the whole message is arrived
                        //(no more pkts to send)
                        //send Terminate Tx command
                        temp = BTMessageGenerator::createTerminateTxMessage("");
                        forwardMessage(temp,gateBinded);

                        delete temp;
                        delete btmsg;

                    }else if(btmsg->getOpcode() == TERMINATE_TX){

                        //trasmission ended

                        delete btmsg;
                        busy = false;
                        gateBinded = -1;

                        //if dynamic fanout is not reached, continue on advertise
                        if(txCounter < protocolManager->getDynamicFanout()){
                            advertising();
                        }else{
                            //the correct state switch is initiating, but because the message is only one
                            //the fsa is putted in standby state.

                            //initiating();
                            standby();
                        }
                    }
                }

                break;

            //VIRTUAL STATE USED ONLY FOR THE INITIALIZATION OF THE FIRST SENDER
            //USED ONLY FOR VISUAL EFFECT DURING THE SIMULATION
            case BTState::START:

                if(batteryManager->getBatteryLevel()>=10)
                    advertising();

                break;

            default: throw cRuntimeError("Unknown status");
        }
    }
}


//=====================TRASMISSION METHODS====================================

void RandomGeometricNode::forwardMessage(cMessage *msg, int outGate)
{
    cMessage *msgCopy = msg->dup();

    cChannel *c = gate("gate$o",outGate)->findTransmissionChannel();

    simtime_t txDelay = c->getTransmissionFinishTime() - simTime();

    if(!c->isBusy() && c!=NULL){
        send(msgCopy, "gate$o", outGate);
    }else{
        forwardDelayedMessage(msgCopy,outGate,txDelay.dbl());
    }
}


void RandomGeometricNode::forwardDelayedMessage(cMessage *msg, int outGate, double delay)
{
    cMessage *msgCopy = msg->dup();

    cChannel *c = gate("gate$o",outGate)->findTransmissionChannel();

    simtime_t txDelay = c->getTransmissionFinishTime() - simTime();

    if(!c->isBusy()){
        sendDelayed(msgCopy,delay, "gate$o", outGate);
    }else{
        sendDelayed(msgCopy,txDelay + delay, "gate$o", outGate);
    }
}

void RandomGeometricNode::broadcastMessage(cMessage *msg)
{
    int nGate = gateSize("gate");
    std::list<int> gateIndexList;
    std::list<int>::iterator it;

    for(int i=0; i < nGate; i++){
        gateIndexList.push_back(i);
    }

    //for(std::list<int>::iterator it = gateIndexList.begin(); it != fifth.end(); it++){}

    for(int i=0; i < nGate; i++){
        it = gateIndexList.begin();
        std::advance(it,intuniform(0,gateIndexList.size()-1));
        forwardMessage(msg,*it);
        gateIndexList.erase(it);
    }


    /*
    for(int i=0; i < nGate; i++){
        forwardMessage(msg,i);
    }
    */
}


//**************************************************************
//**************************************************************
//**************************************************************

//================== FSA METHODS =================

void RandomGeometricNode::switchState(BTState destState)
{
    switch(destState){

    case START:
        btFsaManager->start();
        break;
    case STANDBY:
            btFsaManager->standby();
            break;
    case ADVERTISING:
            btFsaManager->advertising();
            break;
    case INITIATING:
            btFsaManager->initiating();
            break;
    case CONNECTION_MASTER:
            btFsaManager->connectionMaster();
            break;
    case CONNECTION_SLAVE:
            btFsaManager->connectionSlave();
            break;

    default: throw std::runtime_error("INVALID BT FSA STATE !!");

    }

    updateIconDisplayString();
}

//**************************************************************
//**************************************************************
//**************************************************************

//===================UTILITY METHODS===============

void RandomGeometricNode::updateDisplayString(const char *par, int index, const char *value){
    if(getEnvir()->isGUI())
        getDisplayString().setTagArg(par,index,value);
}

void RandomGeometricNode::updateIconDisplayString()
{
    const char *color;

    if(getEnvir()->isGUI()){
        switch(btFsaManager->getState())
        {
            case STANDBY: color = ""; break;
            case SCANNING: color = "yellow"; break;
            case ADVERTISING: color = "orange"; break;
            case INITIATING: color = "green"; break;
            case CONNECTION_MASTER: color = "blue"; break;
            case CONNECTION_SLAVE: color = "magenta"; break;
            case START: color = "red"; break;
            default: throw cRuntimeError("Unknown status");
        }
    }

    updateDisplayString("i", 1, color);
}

void RandomGeometricNode::updateTagDisplayString()
{
    char buff[40];
    if(getEnvir()->isGUI()){
        sprintf(buff, "B: %d%% DF: %d AL: %d", batteryManager->getBatteryLevel(),protocolManager->getDynamicFanout(), protocolManager->getAdvertiseLimit());
        updateDisplayString("t", 0, buff);
    }
}



void RandomGeometricNode::startTimer(BTState state){

    cChannel *c;

    switch(state)
    {
    case START:
        timer->setName("timer Start");
        scheduleAt(simTime()+1.0,timer);
        break;

    case ADVERTISING:
        timer->setName("timer advertising");

        c = gate("gate$o",0)->findTransmissionChannel();

        if(c!=NULL){
            if(!c->isBusy()){
                scheduleAt(simTime() + 5,timer);
            }else{
                scheduleAt(c->getTransmissionFinishTime() + 5,timer);
            }
        }
        break;

    case CONNECTION_MASTER:
        timer->setName("timer conn_mester");

        c = gate("gate$o",gateBinded)->findTransmissionChannel();

        if(c!=NULL){
            if(!c->isBusy()){
                scheduleAt(simTime() + 2,timer);
            }else{
                scheduleAt(c->getTransmissionFinishTime() + 2,timer);
            }
        }
        break;
    }

}
//**************************************************************
//**************************************************************
//**************************************************************


//================ PROTOCOL METHODS =======================

void RandomGeometricNode::start(){
    switchState(START);

    startTimer(START);

    //signal to save statistic on the arrival percentage
    emit(arrivalSignal, true);

    //signal to save statistic on the arrival time
    //full transmission completed
    emit(arrivalTimeSignal, 0);
}

void RandomGeometricNode::standby(){
    switchState(STANDBY);
}

void RandomGeometricNode::advertising()
{
    switchState(ADVERTISING);

    BTMessage *temp= BTMessageGenerator::createAdvIndMessage(message->getTag());
    broadcastMessage(temp);

    delete temp;

    advCounter++;

    cancelEvent(timer);
    startTimer(ADVERTISING);
}

void RandomGeometricNode::initiating()
{
    switchState(INITIATING);
}

void RandomGeometricNode::connectionMaster()
{
    switchState(CONNECTION_MASTER);

    BTMessage *start = BTMessageGenerator::createStartTxMessage("");
    forwardDelayedMessage(start,gateBinded,1.25);

    delete start;
    startTimer(CONNECTION_MASTER);
}

void RandomGeometricNode::connectionSlave()
{
    switchState(CONNECTION_SLAVE);
}


//**************************************************************
//**************************************************************
//**************************************************************



//==============PERIODIC ACTIONS METHODS==================
void RandomGeometricNode::periodicActions(){
    //UPDATE BATTERY
    decreaseBatteryLevelIdle();

    //if battery >= 10% i can still work && I'll do the calculations of parameter
    if(busy || (batteryManager->getBatteryLevel() >= 10)){

        updateParameters();

    }else{
        standby();
    }

    //update the displayed tag
    updateTagDisplayString();
}



void RandomGeometricNode::updateParameters(){
    protocolManager->updateParameters(this,batteryManager);
    scheduleAt(simTime() + 30, periodicActionsTimer);
}


//**************************************************************
//**************************************************************
//**************************************************************



//==============BATTERY METHODS==================

void RandomGeometricNode::decreaseBatteryLevelIdle(){

    batteryManager->decreaseBatteryLevelIdle();
    updateTagDisplayString();
}



void RandomGeometricNode::decreaseBatteryLevelTransmission(){

    batteryManager->decreaseBatteryLevelTransmission();
    updateTagDisplayString();
}

//**************************************************************
//**************************************************************
//**************************************************************
