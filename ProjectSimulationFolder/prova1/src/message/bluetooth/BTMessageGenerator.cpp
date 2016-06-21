/*
 * BTMessageGenerator.cpp
 *
 *  Created on: 21/mag/2015
 *      Author: Lorenzo
 */

#include <BTMessageGenerator.h>
#include <math.h>


//=============CREATE TAG & CREATE MESSAGE=====================================
//const char * BTMessageGenerator::createTag(cPacket *m){
//
//    char buff[50];
//    sprintf(buff, "%s%ld",m->getName(),m->getId());
//
//    std::string s(buff);
//
//    return s.c_str();
//}

int BTMessageGenerator::calculatePduSize(int pduSize, UnityMeasureCode unityMeasure){

    int totPduByte = 0;

    if(pduSize < 0){
        throw std::runtime_error("Invalid pduSize !!! the pduSize value has to be greater or equal than 0(zero) !!");
    }

    switch(unityMeasure)
    {
    case B:
        totPduByte = pduSize;
        break;
    case KB:
        totPduByte = pduSize * pow(1024, unityMeasure);
        break;
    case MB:
        totPduByte = pduSize * pow(1024, unityMeasure);
        break;
    case GB:
        totPduByte = pduSize * pow(1024, unityMeasure);
        break;
    default: throw std::runtime_error("Unknown Unity Measure of the Message !! The valid unity measure code are GB, MG, KB, B"); break;
    }

    return totPduByte;
}

BTMessage * BTMessageGenerator::createMessage(OPCode oc, const char *pdu, int pduSize, UnityMeasureCode unityMeasure){

    BTMessage *m;
    int nByteHandF = 1 + 4 + 3;
    int nBytePdu = 2;
    int nPck = 1;
    int totByte;

    switch(oc){
        //ACK
        case ACK:
            m = new BTMessage("ACK",0); //0=red color
            break;

        //ADV_IND
        case ADV_IND:
            m = new BTMessage("ADV_IND",4); //4=yellow color
            nBytePdu += 6 + sizeof(pdu)*strlen(pdu);
            break;

        //CONN_REQ
        case CONN_REQ:
            m = new BTMessage("CONN_REQ",2); //2=blue color
            nBytePdu += 6 + 6 + 22;
            break;

        //DATA
        case DATA:
            m = new BTMessage("DATA",6); //6=pink color
            nBytePdu += 33;
            if(pduSize > 0){
                nPck = ceil(calculatePduSize(pduSize,unityMeasure)/(double)33);
            }else{
                nPck = ceil(strlen(pdu)/(double)33);
            }
            break;

        //START_TX
        case START_TX:
            m = new BTMessage("START_TX",5); //0=red color
            break;

        //TERMINATE_TX
        case TERMINATE_TX:
            m = new BTMessage("TERMINATE_TX",5); //0=red color
            break;

//        default: throw cRuntimeError("Unknown Operational Code");
    }


    totByte = nPck * (nByteHandF + nBytePdu);

    m->setOpcode(oc);
//    m->setTag(createTag(m));
    m->setTag("tag");
    m->setPdu(pdu);
    m->setByteLength(totByte);

    return m;
}

//===============INDIVIDUAL CREATE METHODS===============================
BTMessage * BTMessageGenerator::createAckMessage(const char *pdu){

    return createMessage(ACK, pdu, 0, B);
}

BTMessage * BTMessageGenerator::createAdvIndMessage(const char *pdu){

    return createMessage(ADV_IND, pdu, 0, B);
}

BTMessage * BTMessageGenerator::createConnReqMessage(const char *pdu){

    return createMessage(CONN_REQ, pdu, 0, B);
}

/**
 * The size of the packet will be calculated on the real Byte size of the pdu passed in input.
 */
BTMessage * BTMessageGenerator::createDataMessage(const char *pdu){

    return createMessage(DATA, pdu, 0, B);
}

/**
 * The size of the packet will be calculated on the pduSize and unityMeasure parameters passed in input.
 * The real size of the pdu inserted will be general ignored. If the pduSize passed in input will be
 * equal or less than zero, the real pdu size of the pdu passed in input will be used instead.
 */
BTMessage * BTMessageGenerator::createDataMessage(const char *pdu, int pduSize, UnityMeasureCode unityMeasure){

    return createMessage(DATA, pdu, pduSize, unityMeasure);
}

BTMessage * BTMessageGenerator::createStartTxMessage(const char *pdu){

    return createMessage(START_TX, pdu, 0, B);
}

BTMessage * BTMessageGenerator::createTerminateTxMessage(const char *pdu){

    return createMessage(TERMINATE_TX, pdu, 0, B);
}

