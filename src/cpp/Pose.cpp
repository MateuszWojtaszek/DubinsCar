//
// Created by mateusz on 09.06.23.
//

#include "../headers/Pose.h"

Pose::Pose(double x, double y, double a) : Vector2d(x, y), alfa(a),theta(0) {
    //changing angle to radians
    adjust_alfa();
    theta=M_PI*alfa/180;
}
//! When writing the program, returning the angle in radians caused problems.
//! The constructor accepts degrees, which caused complications and the constant change of radians to degrees
//! - adding the function getAngleFormat or something similar would have been a better solution,
//! looking from today's point of view
double Pose::getTheta() const {
    return theta;
}

Vector2d Pose::getVector() const {
    return Vector2d(this->getXpose(), this->getYpose());
}

void Pose::adjust_alfa() {
    if(alfa>360){
        double tmp_a=alfa-static_cast<int>(alfa);
        alfa=static_cast<double>(static_cast<int>(alfa)%360)+tmp_a;
    }
}
