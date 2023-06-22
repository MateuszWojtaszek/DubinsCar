//
// Created by mateusz on 22.06.23.
//
#include "../heders/MATH.h"

double mod2pi(const double &val) {
    return fmod(val, 2 * M_PI);
}

double difference_ofCosines(const double &angle1, const double &angle2) {
    double tmp_cos1 = cos(angle1);
    double tmp_cos2 = cos(angle2);
    double difference_ofCosines = tmp_cos1 - tmp_cos2;
    return difference_ofCosines;
}

double cosine_OfAngleDifference(const double &angle1, const double &angle2) {
    double tmp_cos = cos(angle1 - angle2);
    return tmp_cos;
}

double getDistance_between_pos(const Pose &p1, const Pose &p2) {
    double tmp_distance;
    double tmpX_squared = pow(p1.getXpose() - p2.getXpose(), 2);
    double tmpY_squared = pow(p1.getYpose() - p2.getYpose(), 2);
    tmp_distance = sqrt(tmpX_squared + tmpY_squared);
    return tmp_distance;
}

double difference_ofSines(const double &angle1, const double &angle2) {
    double tmp_sin1 = sin(angle1);
    double tmp_sin2 = sin(angle2);
    double difference_ofSines = tmp_sin1 - tmp_sin2;
    return difference_ofSines;
}

double sine_OfAngleDifference(const double &angle1, const double &angle2) {
    double tmp_sin = sin(angle1 - angle2);
    return tmp_sin;
}

double squared(const double &val) {
    return pow(val, 2);
}
