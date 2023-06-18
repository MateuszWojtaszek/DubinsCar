//
// Created by mateusz on 09.06.23.
//

#include "Pose.h"

Pose::Pose(float x, float y, double a) : Vector2d(x, y), alfa(a),theta(0) {
    //changing angle to radians
    adjust_alfa();
    theta=M_PI*alfa/180;
}

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
