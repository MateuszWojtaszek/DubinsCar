//
// Created by mateusz on 09.06.23.
//

#include "../heders/Sector_C.h"


Sector_C::Sector_C(const Pose &p1, const Pose &p2, const PATH &p,const PART &par, const double &l)
        : Sector(p1, p2, p), length(l),part(par) {
    tmpPoseA = getInitialPose();
    sampled_route.push_back(tmpPoseA);
}

void Sector_C::move(double fragment) {
    if(part==L) moveForLeft(fragment);
    if(part==R) moveForRight(fragment);
}

void Sector_C::setSampled_route() {
    for (double particle = 0.01; particle < length;) {
        move(particle);
        sampled_route.push_back(tmpPoseB);
        particle+= 0.01;
    }
}

Pose Sector_C::getPoseAfter() {
    if (part==L) {
        double tmp_sin = sineOfAngleSum(tmpPoseA.getTheta(), length);
        double tmp_cos = cosineOfAngleSum(tmpPoseA.getTheta(), length);
        double tmp_x = tmpPoseA.getXpose() + tmp_sin - sin(tmpPoseA.getTheta());
        double tmp_y = tmpPoseA.getYpose() - tmp_cos + cos(tmpPoseA.getTheta());
        double tmp_theta = tmpPoseA.getTheta() + length;
        tmpPoseC = {tmp_x, tmp_y, tmp_theta * 180 / M_PI};
    }
    if(part==R){
        double tmp_sin = sineOfAngleDifference(tmpPoseA.getTheta(), length);
        double tmp_cos = cosineOfAngleDifference(tmpPoseA.getTheta(), length);
        double tmp_x = tmpPoseA.getXpose() - tmp_sin + sin(tmpPoseA.getTheta());
        double tmp_y = tmpPoseA.getYpose() + tmp_cos - cos(tmpPoseA.getTheta());
        double tmp_theta = tmpPoseA.getTheta() - length;
        tmpPoseC = {tmp_x, tmp_y, tmp_theta * 180 / M_PI};
    }
    return tmpPoseC;
}

void Sector_C::moveForLeft(double fragment) {
    double tmp_sin = sineOfAngleSum(tmpPoseA.getTheta(), fragment);
    double tmp_cos = cosineOfAngleSum(tmpPoseA.getTheta(), fragment);
    double tmp_x = tmpPoseA.getXpose() + tmp_sin - sin(tmpPoseA.getTheta());
    double tmp_y = tmpPoseA.getYpose() - tmp_cos + cos(tmpPoseA.getTheta());
    double tmp_theta = tmpPoseA.getTheta() + fragment;
    tmpPoseB = {tmp_x, tmp_y, tmp_theta*180/M_PI};
}

void Sector_C::moveForRight(double fragment) {
    double tmp_sin = sineOfAngleDifference(tmpPoseA.getTheta(), fragment);
    double tmp_cos = cosineOfAngleDifference(tmpPoseA.getTheta(), fragment);
    double tmp_x = tmpPoseA.getXpose() - tmp_sin + sin(tmpPoseA.getTheta());
    double tmp_y = tmpPoseA.getYpose() + tmp_cos - cos(tmpPoseA.getTheta());
    double tmp_theta = tmpPoseA.getTheta() - fragment;
    tmpPoseB = {tmp_x, tmp_y, tmp_theta*180/M_PI};
}

