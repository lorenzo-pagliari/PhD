/*
 * BTState.h
 *
 *  Created on: 15/giu/2016
 *      Author: Lorenzo
 */

#ifndef BLUETOOTH_BTSTATE_H_
#define BLUETOOTH_BTSTATE_H_

enum BTState {
        STANDBY,
        SCANNING,
        ADVERTISING,
        INITIATING,
        CONNECTION_MASTER,
        CONNECTION_SLAVE,
        START
};

#endif /* BLUETOOTH_BTSTATE_H_ */
