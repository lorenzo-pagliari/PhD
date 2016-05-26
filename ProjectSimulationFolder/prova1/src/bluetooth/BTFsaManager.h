/*
 * BTFsaManager.h
 *
 *  Created on: 21/mag/2015
 *      Author: Lorenzo
 */

#ifndef BTFSAMANAGER_H_
#define BTFSAMANAGER_H_

#include <BTState.h>

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

#endif /* BTFSAMANAGER_H_ */
