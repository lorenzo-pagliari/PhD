/*
 * BTFsaManager.cpp
 *
 *  Created on: 21/mag/2015
 *      Author: Lorenzo
 */

#include <bluetooth/BTFsaManager.h>
#include <stdexcept>

//======CONSTRUCTOR & DESTRIYER==========================
BTFsaManager::BTFsaManager() {
    state = BTState::STANDBY;
}

BTFsaManager::~BTFsaManager() {
}


//==============GETTER============================
BTState BTFsaManager::getState(){
    return state;
}


//==================SETTERS=======================
void BTFsaManager::setState(BTState state){
    this->state = state;
}


//================ PROTOCOL METHODS =======================
void BTFsaManager::start(){
    setState(BTState::START);
}

void BTFsaManager::standby(){
    setState(BTState::STANDBY);
}

void BTFsaManager::scanning()
{
    if(isValidStateTransition(SCANNING)){
        setState(BTState::SCANNING);
    }
}

void BTFsaManager::advertising()
{
    if(isValidStateTransition(ADVERTISING)){
        setState(BTState::ADVERTISING);
    }
}

void BTFsaManager::initiating()
{
    if(isValidStateTransition(INITIATING)){
        setState(BTState::INITIATING);
    }
}

void BTFsaManager::connectionMaster()
{
    if(isValidStateTransition(CONNECTION_MASTER)){
        setState(BTState::CONNECTION_MASTER);
    }
}

void BTFsaManager::connectionSlave()
{
    if(isValidStateTransition(CONNECTION_SLAVE)){
        setState(BTState::CONNECTION_SLAVE);
    }
}

//====================UTILITY METHOD================
bool BTFsaManager::isValidStateTransition(BTState destState){

    char buff[100];

    switch(this->state)
    {
    case START:
        if(destState == STANDBY || destState == ADVERTISING)
            return true;
        break;

    case STANDBY:

        if(destState != CONNECTION_MASTER || destState != CONNECTION_SLAVE )
            return true;

        break;

    case SCANNING:

        if(destState != CONNECTION_MASTER || destState != CONNECTION_SLAVE )
            return true;

        break;

    case ADVERTISING:

        if(destState != CONNECTION_MASTER)
            return true;

        break;

    case INITIATING:

        if(destState != CONNECTION_SLAVE )
            return true;

        break;

    case CONNECTION_MASTER:

        if(destState != CONNECTION_SLAVE)
            return true;

        break;

    case CONNECTION_SLAVE:

        if(destState != CONNECTION_MASTER)
            return true;

        break;

    default: throw std::runtime_error("INVALID BT FSA STATE !!");

    }

    sprintf(buff, "Bluetooth FSA INVALID STATE TRANSITION FROM %s TO %s !!", getStateName(state), getStateName(destState));

    std::string errorMessage(buff);

    throw std::logic_error(errorMessage);
}



const char *BTFsaManager::getStateName(BTState state){

    switch(state)
    {
    case START: return "START"; break;
    case STANDBY: return "STANDBY"; break;
    case ADVERTISING: return "ADVERTISING"; break;
    case INITIATING: return "INITIATING"; break;
    case CONNECTION_MASTER: return "CONNECTION_MASTER"; break;
    case CONNECTION_SLAVE: return "CONNECTION_SLAVE"; break;
    default: throw std::runtime_error("Unknown BT FSA STATE!!");
    }
}
