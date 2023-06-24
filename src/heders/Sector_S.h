//
// Created by mateusz on 09.06.23.
//

#ifndef DUBBINS_CAR_SECTOR_S_H
#define DUBBINS_CAR_SECTOR_S_H
#include "Sector.h"
//derivative of class sector from straight line
class Sector_S: public Sector{
    PATH path = NONE;
    PART part = NOPE;
    double length = 0;
    void move(double fragment);
    Pose tmpPoseC={0,0,0};
public:
    /**
     *
     * @param p1
     * @param p2
     * @param p
     * @param par
     * @param l
     */
    Sector_S(const Pose &p1, const Pose &p2, const PATH &p, const PART &par,
             const double &l);

    void setSampled_route();
    Pose getPoseAfter();

};


#endif //DUBBINS_CAR_SECTOR_S_H
