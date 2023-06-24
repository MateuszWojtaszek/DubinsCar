//
// Created by mateusz on 09.06.23.
//

#include "../heders/Sector_S.h"


Sector_S::Sector_S(const Pose &p1, const Pose &p2, const PATH &p, const PART &par,
                   const double &l) : Sector(p1, p2), path(p), part(par), length(l) {
    tmpPoseA = getInitialPose();
    sampled_route.push_back(tmpPoseA);
}

void Sector_S::setSampled_route() {
    for (double particle = 0.01; particle < length;) {
        move(particle);
        sampled_route.push_back(tmpPoseB);
        particle+= 0.01;
    }
}

Pose Sector_S::getPoseAfter() {
    double tmp_x=tmpPoseA.getXpose()+(length * cos(tmpPoseA.getTheta()));
    double tmp_y=tmpPoseA.getYpose()+(length * sin(tmpPoseA.getTheta()));
    tmpPoseC={tmp_x,tmp_y,tmpPoseA.getTheta()};
    return tmpPoseC;
}

void Sector_S::move(double fragment) {
double tmp_x=tmpPoseA.getXpose()+(fragment * cos(tmpPoseA.getTheta()));
double tmp_y=tmpPoseA.getYpose()+(fragment * sin(tmpPoseA.getTheta()));
tmpPoseB={tmp_x,tmp_y,tmpPoseA.getTheta()};
}
