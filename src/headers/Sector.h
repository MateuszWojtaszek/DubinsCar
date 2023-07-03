//
// Created by mateusz on 09.06.23.
//

#ifndef DUBBINS_CAR_SECTOR_H
#define DUBBINS_CAR_SECTOR_H

#include "Pose.h"
#include <vector>
#include "Enums.h"
#include "MATH.h"



// base class for sectors of type Sector_C ( circle) Sector_S (straight)
class Sector {
    Pose initial_pos, final_pos;
protected:
    Pose tmpPoseA = {0, 0, 0};
    Pose tmpPoseB = {0, 0, 0};
    std::vector<Pose> sampled_route = {};
    virtual void move(double fragment)= 0;
    Pose tmpPoseC={0,0,0};
    PATH path = NONE;
public:
    virtual ~Sector() = default;

    Sector(const Pose &p1, const Pose &p2, const PATH &p);

    [[nodiscard]] virtual std::vector<Pose> getSector_Sampled_route() const;

    [[nodiscard]] Pose getInitialPose() const;

    [[nodiscard]] Pose getFinalPose() const;
    virtual void setSampled_route()=0;
    virtual Pose getPoseAfter()=0;
};


#endif //DUBBINS_CAR_SECTOR_H
