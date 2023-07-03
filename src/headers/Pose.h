//
// Created by mateusz on 09.06.23.
//

#ifndef DUBBINS_CAR_POSE_H
#define DUBBINS_CAR_POSE_H
#include "Vector2d.h"
#include <cmath>
/*
 * ** class modeling robot poses and orientations (contains Vector2d, float theta <0.2pi>)
 *    Here in general there should be no inheritance, but it is too late to change it
 */
class Pose : public Vector2d{
    double alfa;
    double theta;
    /**
     ** a function that converts alfa to range 2pi
     */
    void adjust_alfa();
public:
    /**
     * * a constructor that creat a Pose object and converse a(alfa) to radians
     * @param x
     * @param y
     * @param a
     * ! Param a need to be an angle
     */
    Pose(double x, double y, double a);
    /**
     * *simple geter
     * @return
     */
    [[nodiscard]] double getTheta() const;
    /**
     * *simple getter
     * @return
     */
    [[nodiscard]] Vector2d getVector() const;
};


#endif //DUBBINS_CAR_POSE_H
