//
// Created by mateusz on 09.06.23.
//

#ifndef DUBBINS_CAR_SECTOR_H
#define DUBBINS_CAR_SECTOR_H

#include "Pose.h"
#include <vector>
#include "Enums.h"
#include "MATH.h"

enum PART {
    L,
    L1,
    L2,
    R,
    R1,
    R2,
    S,
    NOPE
};

// base class for sectors of type Sector_C ( circle) Sector_S (straight)
class Sector {
    Pose initial_pos, final_pos;
protected:
    std::vector<Pose> sampled_route = {};
    Pose tmpPoseA = {0, 0, 0};
    Pose tmpPoseB = {0, 0, 0};
public:
    virtual ~Sector() = default;

    /**
     *
     * @param p1
     * @param p2
     */
    Sector(const Pose &p1, const Pose &p2);

    std::vector<Pose> getSector_Sampled_route();

    [[nodiscard]] Pose getInitialPose() const;

    [[nodiscard]] Pose getFinalPose() const;
};


#endif //DUBBINS_CAR_SECTOR_H
