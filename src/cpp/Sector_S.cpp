//
// Created by mateusz on 09.06.23.
//

#include "../heders/Sector_S.h"

Sector_S::Sector_S(const Pose &p1, const Pose &p2 ,  Pose test) :Sector(p1, p2),test(test){
    double difference_y = getFinalPose().getYpose()-getInitialPose().getYpose();
    double difference_x = getFinalPose().getXpose()-getInitialPose().getXpose();
    initialTheta_AB = fmod((atan2(difference_y,difference_x)),2*M_PI);
    distance = getDistance_between_pos(getInitialPose(),getFinalPose());
    tmpPos_A=getInitialPose();
}

double Sector_S::getSector_length() {
    return sectorLength;
}

void Sector_S::move(double partOF_computeLength) {
auto tmp_x = tmpPos_A.getXpose() + partOF_computeLength * cos(tmpPos_A.getTheta());
auto tmp_y = tmpPos_A.getYpose() + partOF_computeLength * sin(tmpPos_A.getTheta());
auto tmp_theta = tmpPos_A.getTheta();
tmpPos_B = {tmp_x,tmp_y,tmp_theta};
}

double Sector_S::computeLength() {
   double tmp_cos=2*cos(getInitialPose().getTheta()-getFinalPose().getTheta());
   double tmp_sin=2*distance* (sin(getInitialPose().getTheta())- sin(getFinalPose().getTheta()));
   double tmp_d= pow(distance,2);
    return 0.2;
}

void Sector_S::setSector_Sampled_route() {
    double part=0.000;
    double tmp_foo = std::abs(getComputedLenght());
    while (part<tmp_foo) {
        move(part);
        tmpPos_A = tmpPos_B;
        sampled_route.push_back(tmpPos_B);
        part+=0.001;
    }
}

double Sector_S::getComputedLenght() {
    return computeLength();
}

std::vector<Pose> Sector_S::getSector_Sampled_route() {
    return sampled_route;
}
