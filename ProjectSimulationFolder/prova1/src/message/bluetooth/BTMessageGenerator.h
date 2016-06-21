/*
 * BTMessageGenerator.h
 *
 *  Created on: 21/mag/2015
 *      Author: Lorenzo
 */

#ifndef BTMESSAGEGENERATOR_H_
#define BTMESSAGEGENERATOR_H_

#include <btmessage_m.h>
#include <OPCode.h>
#include <UnityMeasureCode.h>

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

#endif /* BTMESSAGEGENERATOR_H_ */
