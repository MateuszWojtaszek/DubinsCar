//
// Created by mateusz on 09.06.23.
//

#ifndef DUBBINS_CAR_SECTOR_C_H
#define DUBBINS_CAR_SECTOR_C_H
#include "Sector.h"
enum TWIST{
    R,
    L
};
struct SinAndCos_diff{
    double sin_difference;
    double cos_difference;
};
// Sector class derivative for circular motion
class Sector_C: public Sector{
    std::vector<Pose> sampled_route={};
    TWIST twist;
    Pose tmpPos_A={0,0,0};
    Pose tmpPos_B={0,0,0};
    // if it not works, check here first
    double initialTheta_AB=0;
    double distance=0;
    double computeLength();
    double computeAtan2();
    static double mod2pi(double variable);
    SinAndCos_diff sinAndCosDiff();

public:
    Sector_C(const Pose &p1, const Pose &p2,TWIST T);
    /**
     * a function thats moves a robot
     * @param partOF_computeLength
     */
    void move1(double partOF_computeLength);
    Pose getPose_after();
    void setSector_Sampled_route();
    std::vector<Pose> getSector_Sampled_route() override;
    double getComputedLenght();

};


#endif //DUBBINS_CAR_SECTOR_C_H
