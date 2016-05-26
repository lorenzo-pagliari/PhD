/*
 * Coordinate2D.cpp
 *
 *  Created on: 08/mag/2015
 *      Author: Lorenzo
 */

#include <Coordinate2D.h>

Coordinate2D::Coordinate2D() {
    this->xCoord = 0;
    this->yCoord = 0;
}

Coordinate2D::Coordinate2D(double x, double y) {
    this->xCoord = x;
    this->yCoord = y;
}

Coordinate2D::~Coordinate2D() {

}

//===============GETTERS=============
double Coordinate2D::getXcoord(){
    return this->xCoord;
}

double Coordinate2D::getYcoord(){
    return this->yCoord;
}

//===============SETTERS=============
void Coordinate2D::setXcoord(double x){
    this->xCoord = x;
}

void Coordinate2D::setYcoord(double y){
    this->yCoord = y;
}

void Coordinate2D::initialize() {

     /*
     * il posizionamento grafico non è molto efficace in quanto
     * posiziona secondo pixel e non secondo presunte unità
     * di misura
     *
    char b[20];
    sprintf(b, "%lf", this->xPos);
    getDisplayString().setTagArg("p",0,b);

    sprintf(b, "%lf", this->yPos);
    getDisplayString().setTagArg("p",1,b);
    */


    /*
    if(par("startTx")){
        this->message = new cMessage("MESSAGGIO 1");
        advertising();
    }else{
        initiating();
    }*/

}
