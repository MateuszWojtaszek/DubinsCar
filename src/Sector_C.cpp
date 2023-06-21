//
// Created by mateusz on 09.06.23.
//

#include "Sector_C.h"

Sector_C::Sector_C(const Pose &p1, const Pose &p2, TWIST T) : Sector(p1, p2),twist(T) {
    float difference_y = getFinalPose().getYpose()-getInitialPose().getYpose();
    float difference_x = getFinalPose().getXpose()-getInitialPose().getXpose();
    initialTheta_AB = fmod((atan2(difference_y, difference_x)), 2 * M_PI);
    distance = getDistance_between_pos(getInitialPose(),getFinalPose());
    tmpPos_A=getInitialPose();
}

double Sector_C::computeLength() {
    double tmp_thetaStart= getInitialPose().getTheta(); // or it is wrong getInitialPose().getTheta();
    double tmp_atan2 = computeAtan2();
    return -tmp_thetaStart+tmp_atan2;
}

double Sector_C::computeAtan2() {
    double tmpSin_diff = sinAndCosDiff().sin_difference;
    double tmpCos_diff = sinAndCosDiff().cos_difference;
    return mod2pi(atan2(tmpCos_diff,distance+tmpSin_diff));
}
double Sector_C::mod2pi(double variable) {
    return fmod(variable,M_PI*2);
}

SinAndCos_diff Sector_C::sinAndCosDiff() {
    double tmp_cos1 = cos(getFinalPose().getTheta());
    double tmp_cos2 = cos(getInitialPose().getTheta());
    double tmp_sin1 = sin(getInitialPose().getTheta());
    double tmp_sin2 = sin(getFinalPose().getTheta());
    return {tmp_sin1-tmp_sin2,tmp_cos2-tmp_cos1};
}
// just for first turn in LSL trajectory (just for first L)
void Sector_C::move1() {
    if(twist==L){
        auto tmp_x = static_cast<float>(static_cast<double>(tmpPos_A.getXpose()) +
                                        sin(tmpPos_A.getTheta() + computeLength()) - sin(tmpPos_A.getTheta()));
        auto tmp_y = static_cast<float>(static_cast<double>(tmpPos_A.getYpose()) -
                                        cos(tmpPos_A.getTheta() + computeLength()) + cos(tmpPos_A.getTheta()));
        double tmp_theta = tmpPos_A.getTheta() + computeLength();
        tmpPos_B = {tmp_x,tmp_y,tmp_theta*57.3};
    }
    else {
        auto tmp_x = static_cast<float>(static_cast<double>(tmpPos_A.getXpose()) -
                                        sin(tmpPos_A.getTheta() - computeLength()) + sin(tmpPos_A.getTheta()));
        auto tmp_y = static_cast<float>(static_cast<double>(tmpPos_A.getYpose()) +
                                        cos(tmpPos_A.getTheta() - computeLength()) - cos(tmpPos_A.getTheta()));
        double tmp_theta = tmpPos_A.getTheta() - computeLength();
        tmpPos_B = {tmp_x, tmp_y, tmp_theta*57.3}; // back to angle cuz pose need thete in angle format
    }
}

Pose Sector_C::getPose_after() {
    return tmpPos_B;
}
// sampled route just for first LSL part
std::vector<Pose> Sector_C::getSector_Sampled_route() {
    for (int part = 0; part<20; ++part) {
        move1();
        tmpPos_A=tmpPos_B;
        sampled_route.push_back(tmpPos_B);
    }
    return sampled_route;
}
