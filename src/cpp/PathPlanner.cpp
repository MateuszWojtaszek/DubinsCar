//
// Created by mateusz on 09.06.23.
//

#include "../heders/PathPlanner.h"

/**
 *
 * @return
 */
PATH PathPlanner::getBestPath() const {
    return bestPath;
}

/**
 *
 * @param p_in
 * @param p_fin
 */
PathPlanner::PathPlanner(const Pose &p_in, const Pose &p_fin) : initPose(p_in), finalPose(p_fin) {
    distance = getDistance_between_pos(initPose, finalPose);
}

void PathPlanner::planPaths() {
    planPath_LSL();
    planPath_LRL();
    planPath_LSR();
    planPath_RLR();
    planPath_RSL();
    planPath_RSR();
    setBestPath();
}

void PathPlanner::planPath_LSL() {
/**
* * Dependencies of first part
*/
    double lengthOF_firstL;
    double diffOfCos = difference_ofCosines(finalPose.getTheta(), initPose.getTheta());
    double diffOfSin = difference_ofSines(initPose.getTheta(), finalPose.getTheta());
    double arctan = mod2pi(atan2(diffOfCos, distance + diffOfSin));
    lengthOF_firstL = -initPose.getTheta() + arctan;

/**
* * Dependencies of second part
*/
    double lengthOF_S;
    double cosOfDiffAngle = cosine_OfAngleDifference(initPose.getTheta(), finalPose.getTheta());
    double distSquared = squared(distance);
    lengthOF_S = sqrt(2 + distSquared - (2 * cosOfDiffAngle) + (2 * distance * diffOfSin));
/**
* * Dependencies of third part
*/
    double lengthOF_SecondL;
    lengthOF_SecondL = finalPose.getTheta() - arctan;
//* * length of Path
    double lengthOF_Path = lengthOF_firstL + lengthOF_S + lengthOF_SecondL;
//* *  Add length of specific path to the map
    addTO_Paths(LSL, lengthOF_Path);
}

void PathPlanner::planPath_RSR() {

}

void PathPlanner::planPath_RSL() {

}

void PathPlanner::planPath_LSR() {

}

void PathPlanner::planPath_RLR() {

}

void PathPlanner::planPath_LRL() {

}

void PathPlanner::addTO_Paths(const PATH &p, const double &d) {
    Paths[d] = p;
}

void PathPlanner::setBestPath() {
    double tmp_best=0;
    for (auto path:Paths) {
        if(tmp_best>path.first || tmp_best==0) tmp_best = path.second;
    }
    //? looking for pointer to best path
    auto path = Paths.find(tmp_best);
    bestPath=path->second;
}
