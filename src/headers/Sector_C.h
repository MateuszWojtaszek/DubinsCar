//
// Created by mateusz on 09.06.23.
//

#ifndef DUBBINS_CAR_SECTOR_C_H
#define DUBBINS_CAR_SECTOR_C_H
#include "Sector.h"

// Sector class derivative for circular motion
class Sector_C: public Sector{
    double length = 0;
void move(double fragment) override;
void moveForLeft(double fragment);
void moveForRight(double fragment);
    PART part;

public:
    /**
     * constructor of the Sector_c object, taking the start and end positions, respectively,
     * and the type of path along with its length
     * @param p1
     * @param p2
     * @param p
     * @param par
     * @param l
     */
Sector_C(const Pose &p1, const Pose &p2,const PATH &p,const PART &par,const double &l);

void setSampled_route() override;
Pose getPoseAfter() override;
};


#endif //DUBBINS_CAR_SECTOR_C_H
