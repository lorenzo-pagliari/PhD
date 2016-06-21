/*
 * BTFsaManager.h
 *
 *  Created on: 15/giu/2016
 *      Author: Lorenzo
 */

#ifndef BLUETOOTH_BTFSAMANAGER_H_
#define BLUETOOTH_BTFSAMANAGER_H_


#include "BTState.h"

class BTFsaManager {

private:
    BTState state;

public:
    BTFsaManager();
    virtual ~BTFsaManager();

    //Getter
    virtual BTState getState();

    //Setters
        //real fsa state methods
    void standby();
    void scanning();
    void advertising();
    void initiating();
    void connectionMaster();
    void connectionSlave();
        //fake method only for start the simulation
    void start();


private:
    //Setter
    virtual void setState(BTState state);
    //Utility method
    bool isValidStateTransition(BTState state);
    const char * getStateName(BTState);
};


#endif /* BLUETOOTH_BTFSAMANAGER_H_ */
