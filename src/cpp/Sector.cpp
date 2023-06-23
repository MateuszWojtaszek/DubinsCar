//
// Created by mateusz on 09.06.23.
//

#include "../heders/Sector.h"

Sector::Sector(const Pose &p1, const Pose &p2)
:initial_pos(p1), final_pos(p2){

}

std::vector<Pose> Sector::getSector_Sampled_route() {
    return sampled_route;
}

Pose Sector::getInitialPose() const {
    return initial_pos;
}

Pose Sector::getFinalPose() const {
    return final_pos;
}


