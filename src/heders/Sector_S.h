//
// Created by mateusz on 09.06.23.
//

#ifndef DUBBINS_CAR_SECTOR_S_H
#define DUBBINS_CAR_SECTOR_S_H
#include "Sector.h"
//derivative of class sector from straight line
class Sector_S: public Sector{
Pose tmpPos_A={0,0,0};
Pose tmpPos_B={0,0,0};
double initialTheta_AB=0;
double distance=0;
double computeLength();
double sectorLength=0;
std::vector<Pose> sampled_route={};
Pose test={0,0,0};
public:
    void move(double partOF_computeLength);
     double getSector_length() override;
    Sector_S(const Pose &p1, const Pose &p2, Pose test);
    void setSector_Sampled_route();
    std::vector<Pose> getSector_Sampled_route() override;
    double getComputedLenght();
};


#endif //DUBBINS_CAR_SECTOR_S_H
