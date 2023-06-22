//
// Created by mateusz on 09.06.23.
//

#ifndef DUBBINS_CAR_SECTOR_H
#define DUBBINS_CAR_SECTOR_H
#include "Pose.h"
#include <vector>
// base class for sectors of type Sector_C ( circle) Sector_S (straight)
class Sector {
    Pose initial_pos,final_pos;
    double length;
    std::vector<Pose> sampled_route;
    void add_to_totalLength(double section);
    double getDistance_between_pos();
public:
    virtual ~Sector() = default;
    virtual double getSector_length();
    Sector(const Pose &p1, const Pose &p2);
    virtual std::vector<Pose> getSector_Sampled_route();
    static double getDistance_between_pos(const Pose &p1, const Pose &p2);
    [[nodiscard]] Pose getInitialPose()const;
    [[nodiscard]] Pose getFinalPose() const;
};


#endif //DUBBINS_CAR_SECTOR_H
