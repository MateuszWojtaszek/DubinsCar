//
// Created by mateusz on 09.06.23.
//

#ifndef DUBBINS_CAR_POSE_H
#define DUBBINS_CAR_POSE_H
#include "Vector2d.h"
#include <cmath>
// class modeling robot poses and orientations (contains Vector2d, float theta <0.2pi>)
class Pose : public Vector2d{
    double alfa;
    double theta;
    void adjust_alfa();
public:
    Pose(float x, float y, double a);
    //simple getters
    [[nodiscard]] double getTheta() const;
    [[nodiscard]] Vector2d getVector() const;
};


#endif //DUBBINS_CAR_POSE_H
