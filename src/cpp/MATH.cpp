//
// Created by mateusz on 22.06.23.
//
#include "../heders/MATH.h"

double mod2pi(const double &val) {
    double tmp_val = std::fmod(val, 2 * M_PI);
    if(tmp_val<0) tmp_val+=2*M_PI;
    if(tmp_val>360) tmp_val-=2*M_PI;
    return tmp_val;
}

double differenceOfCosines(const double &angle1, const double &angle2) {
    return cos(angle1)-cos(angle2);
}

double sumOfCosines(const double &angle1, const double &angle2){
    return cos(angle1) + cos(angle2) ;
}

double cosineOfAngleDifference(const double &angle1, const double &angle2) {
    return cos(angle1 - angle2);
}

double cosineOfAngleSum(const double &angle1, const double &angle2) {
    return cos(angle1 + angle2);
}

double getDistanceBetweenPos(const Pose &p1, const Pose &p2) {
    double tmpX_squared = pow(p1.getXpose() - p2.getXpose(), 2);
    double tmpY_squared = pow(p1.getYpose() - p2.getYpose(), 2);
    return sqrt(tmpX_squared + tmpY_squared);
}

double differenceOfSines(const double &angle1, const double &angle2) {
    return sin(angle1)-sin(angle2);
}

double sumOfSines(const double &angle1, const double &angle2){
    return sin(angle1)+ sin(angle2);
}

double sineOfAngleDifference(const double &angle1, const double &angle2){
    return sin(angle1 - angle2);
}

double sineOfAngleSum(const double &angle1, const double &angle2){
    return sin(angle1 + angle2);
}

double squared(const double &val){
    return pow(val, 2);
}
