//
// Generated file, do not edit! Created by nedtool 5.0 from src/experiments/m1.msg.
//

#ifndef __M1_M_H
#define __M1_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0500
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
	#include "OPCode.h"
// }}

/**
 * Class generated from <tt>src/experiments/m1.msg:21</tt> by nedtool.
 * <pre>
 * packet M1
 * {
 *     int source;
 *     int destination;
 *     int opcode @enum(OPCode);
 *     string tag;
 *     string pdu;
 * }
 * </pre>
 */
class M1 : public ::omnetpp::cPacket
{
  protected:
    int source;
    int destination;
    int opcode;
    ::omnetpp::opp_string tag;
    ::omnetpp::opp_string pdu;

  private:
    void copy(const M1& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const M1&);

  public:
    M1(const char *name=nullptr, int kind=0);
    M1(const M1& other);
    virtual ~M1();
    M1& operator=(const M1& other);
    virtual M1 *dup() const {return new M1(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual int getSource() const;
    virtual void setSource(int source);
    virtual int getDestination() const;
    virtual void setDestination(int destination);
    virtual int getOpcode() const;
    virtual void setOpcode(int opcode);
    virtual const char * getTag() const;
    virtual void setTag(const char * tag);
    virtual const char * getPdu() const;
    virtual void setPdu(const char * pdu);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const M1& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, M1& obj) {obj.parsimUnpack(b);}


#endif // ifndef __M1_M_H
