/*
 * BTMessageGenerator.h
 *
 *  Created on: 16/giu/2016
 *      Author: Lorenzo
 */

#ifndef SRC_MESSAGE_BLUETOOTH_BTMESSAGEGENERATOR_H_
#define SRC_MESSAGE_BLUETOOTH_BTMESSAGEGENERATOR_H_

#include <btmessage_m.h>
#include "OPCode.h"
#include "UnityMeasureCode.h"

class BTMessageGenerator {

protected:
    static BTMessage *createMessage(OPCode, const char *, int, UnityMeasureCode);
//    static const char *createTag(cPacket *);
    static int calculatePduSize(int, UnityMeasureCode);

public:
    static BTMessage *createAckMessage(const char *);
    static BTMessage *createAdvIndMessage(const char *);
    static BTMessage *createConnReqMessage(const char *);
    static BTMessage *createDataMessage(const char * pdu);
    static BTMessage *createDataMessage(const char * pdu, int, UnityMeasureCode);
    static BTMessage *createStartTxMessage(const char *);
    static BTMessage *createTerminateTxMessage(const char *);
};



#endif /* SRC_MESSAGE_BLUETOOTH_BTMESSAGEGENERATOR_H_ */
