//
// Created by mateusz on 09.06.23.
//

#include "../heders/Sector_C.h"

Sector_C::Sector_C(const Pose &p1, const Pose &p2, TWIST T) : Sector(p1, p2),twist(T) {
    double difference_y = getFinalPose().getYpose()-getInitialPose().getYpose();
    double difference_x = getFinalPose().getXpose()-getInitialPose().getXpose();
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
void Sector_C::move1(double partOF_computeLength) {
    if(twist==L){
        auto tmp_x = tmpPos_A.getXpose() +
                                        sin(tmpPos_A.getTheta() + partOF_computeLength) - sin(tmpPos_A.getTheta());
        auto tmp_y = tmpPos_A.getYpose() -
                                        cos(tmpPos_A.getTheta() + partOF_computeLength) + cos(tmpPos_A.getTheta());
        double tmp_theta = tmpPos_A.getTheta() + partOF_computeLength;
        tmpPos_B = {tmp_x,tmp_y,tmp_theta*180/M_PI};
    }
    else {
        auto tmp_x = tmpPos_A.getXpose() -
                                        sin(tmpPos_A.getTheta() - partOF_computeLength) + sin(tmpPos_A.getTheta());
        auto tmp_y = tmpPos_A.getYpose() +
                                        cos(tmpPos_A.getTheta() - partOF_computeLength) - cos(tmpPos_A.getTheta());
        double tmp_theta = tmpPos_A.getTheta() - partOF_computeLength;
        tmpPos_B = {tmp_x, tmp_y, tmp_theta*57.3}; // back to angle cuz pose need thete in angle format
    }
}

Pose Sector_C::getPose_after() {
    return tmpPos_B;
}
// sampled route just for first LSL part
void Sector_C::setSector_Sampled_route() {
    double part=0.000;
    double tmp_foo = std::abs(getComputedLenght());
    while (part<tmp_foo) {
        move1(part);
        tmpPos_A = tmpPos_B;
        sampled_route.push_back(tmpPos_B);
        part+=0.001;
    }
}


double Sector_C::getComputedLenght() {
    return computeLength();
}

std::vector<Pose> Sector_C::getSector_Sampled_route() {
    return sampled_route;
}
