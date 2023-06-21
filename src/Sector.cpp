//
// Created by mateusz on 09.06.23.
//

#include "Sector.h"

double Sector::getSector_length() {
    return length;
}

void Sector::add_to_totalLength(double section) {
length+=section;
}

Sector::Sector(const Pose &p1, const Pose &p2)
:initial_pos(p1), final_pos(p2),length(0),sampled_route({}){

}

std::vector<Pose> Sector::getSector_Sampled_route() {
    return sampled_route;
}

double Sector::getDistance_between_pos() {
    double tmp_distance;
    tmp_distance = getDistance_between_pos(initial_pos,final_pos);
    return tmp_distance;
}

double Sector::getDistance_between_pos(const Pose &p1, const Pose &p2) {
    double tmp_distance;
    double tmpX_squared =pow(static_cast<double>(p1.getXpose() - p2.getXpose()), 2);
    double tmpY_squared = pow(static_cast<double>(p1.getYpose() - p2.getYpose()), 2);
    tmp_distance = sqrt(tmpX_squared+tmpY_squared);
    return tmp_distance;
}

Pose Sector::getInitialPose() const {
    return initial_pos;
}

Pose Sector::getFinalPose() const {
    return final_pos;
}


