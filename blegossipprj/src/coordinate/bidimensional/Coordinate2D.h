/*
 * Coordinate2D.cpp
 *
 *  Created on: 15/giu/2016
 *      Author: Lorenzo
 */

#ifndef COORDINATE2D_H_
#define COORDINATE2D_H_

class Coordinate2D {

private:
    double xCoord,yCoord;

public:
    Coordinate2D();
    Coordinate2D(double, double);
    virtual ~Coordinate2D();

    //Getter
    double getXcoord();
    double getYcoord();

    //Setter
    void setXcoord(double);
    void setYcoord(double);

protected:
    virtual void initialize();
};

#endif /* COORDINATE2D_H_ */
