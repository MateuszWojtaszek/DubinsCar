//
// Created by mateusz on 09.06.23.
//

#include "Sector_S.h"

Sector_S::Sector_S(const Pose &p1, const Pose &p2) :Sector(p1, p2){
    float difference_y = getFinalPose().getYpose()-getInitialPose().getYpose();
    float difference_x = getFinalPose().getXpose()-getInitialPose().getXpose();
    initialTheta_AB = fmod((atan2(difference_y,difference_x)),2*M_PI);
    distance = getDistance_between_pos(getInitialPose(),getFinalPose());
}

double Sector_S::getSector_length() {
    return getDistance_between_pos(tmpPos_A,tmpPos_B);
}
