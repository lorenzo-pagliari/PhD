/*
 * BTState.h
 *
 *  Created on: 21/mag/2015
 *      Author: Lorenzo
 */

#ifndef BTSTATE_H_
#define BTSTATE_H_

enum BTState {
        STANDBY,
        SCANNING,
        ADVERTISING,
        INITIATING,
        CONNECTION_MASTER,
        CONNECTION_SLAVE,
        START
};



#endif /* BTSTATE_H_ */
