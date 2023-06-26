//
// Created by mateusz on 09.06.23.
//

#include "../heders/PathPlanner.h"

/**
 ** a function that return bestPath
 * @return bestPath
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
    distance = getDistanceBetweenPos(initPose, finalPose);
    lengthOf_eachPart.resize(3);
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
    double diffOfCos = differenceOfCosines(finalPose.getTheta(), initPose.getTheta());
    double diffOfSin = differenceOfSines(initPose.getTheta(), finalPose.getTheta());
    double arctan = mod2pi(std::atan2(diffOfCos, distance + diffOfSin));
    lengthOF_firstL = mod2pi(-initPose.getTheta() + arctan);

/**
* * Dependencies of second part
*/
    double lengthOF_S;
    double cosOfDiffAngle = cosineOfAngleDifference(initPose.getTheta(), finalPose.getTheta());
    double distSquared = squared(distance);
    lengthOF_S = sqrt(2 + distSquared - (2 * cosOfDiffAngle) + (2 * distance * diffOfSin));
/**
* * Dependencies of third part
*/
    double lengthOF_SecondL;
    lengthOF_SecondL = mod2pi(finalPose.getTheta() - arctan);
//* * length of Path
    double lengthOF_Path = -initPose.getTheta() + finalPose.getTheta() + lengthOF_S;
//* *  Add length of specific path to the map
    addTO_Paths(lengthOF_Path, LSL);
    LenOfEachPart LofEP = {lengthOF_firstL, lengthOF_S, lengthOF_SecondL};
    addTo_partsOfEeachPath(LSL, LofEP);
}

void PathPlanner::planPath_RSR() {
/**
* * Dependencies of first part
*/
    double lengthOF_firstR;
    double diffOfCos = differenceOfCosines(finalPose.getTheta(), initPose.getTheta());
    double diffOfSin = differenceOfSines(initPose.getTheta(), finalPose.getTheta());
    double arctan = mod2pi(std::atan2(diffOfCos, distance + diffOfSin));
    lengthOF_firstR = mod2pi(initPose.getTheta() - arctan);

/**
* * Dependencies of second part
*/
    double lengthOF_S;
    double cosOfDiffAngle = cosineOfAngleDifference(initPose.getTheta(), finalPose.getTheta());
    double distSquared = squared(distance);
    lengthOF_S = sqrt(2 + distSquared - (2 * cosOfDiffAngle) + (2 * distance * diffOfSin));
/**
* * Dependencies of third part
*/
    double lengthOF_SecondR;
    lengthOF_SecondR = mod2pi(-finalPose.getTheta()) + arctan;
//* * length of Path
    double lengthOF_Path = initPose.getTheta() - finalPose.getTheta() + lengthOF_S;
//* *  Add length of specific path to the map
    addTO_Paths(lengthOF_Path, RSR);
    LenOfEachPart LofEP = {lengthOF_firstR, lengthOF_S, lengthOF_SecondR};
    addTo_partsOfEeachPath(RSR, LofEP);
}

void PathPlanner::planPath_RSL() {

}

void PathPlanner::planPath_LSR() {

}

void PathPlanner::planPath_RLR() {

}

void PathPlanner::planPath_LRL() {

}

void PathPlanner::addTO_Paths(const double &d, const PATH &p) {
    Paths[d] = p;
}

void PathPlanner::setBestPath() {
    double tmp_best = 0;
    for (auto path: Paths) {
        if (tmp_best > path.first || tmp_best == 0) tmp_best = path.first;
    }
    //? looking for pointer to best path
    auto path = Paths.find(tmp_best);
    bestPath = path->second;
    auto part = partsOfEachPath.find(bestPath);
    lengthOf_eachPart = {part->second.l1, part->second.l2, part->second.l3};
}

void PathPlanner::addTo_partsOfEeachPath(const PATH &p, const LenOfEachPart &lep) {
    partsOfEachPath[p] = lep;
}

std::vector<double> PathPlanner::getLengthOf_EachPart() {
    return lengthOf_eachPart;
}

void PathPlanner::planPathsFromOrigin() {
    double rotateAngle;
    double startX1 = initPose.getXpose();
    double startY1 = initPose.getYpose();
    double startX2 = finalPose.getXpose();
    double startY2 = finalPose.getYpose();
    initPose = {0, 0, initPose.getTheta() * 180 / M_PI};
    finalPose = {finalPose.getXpose() - startX1, finalPose.getYpose() - startY1,
                 finalPose.getTheta() * 180 / M_PI};
    rotateAngle = mod2pi(atan2(finalPose.getYpose(), finalPose.getXpose()));
    planPaths();
    if(bestPath==LSL) {
        Sector_C s1(initPose, finalPose, bestPath, L, lengthOf_eachPart.at(0));
        s1.setSampled_route();
        Sector_S s2(s1.getPoseAfter(), finalPose, bestPath, lengthOf_eachPart.at(1));
        s2.setSampled_route();
        Sector_C s3(s2.getPoseAfter(), finalPose, bestPath, L, lengthOf_eachPart.at(2));
        s3.setSampled_route();
        addToFullPath(&s1);
        addToFullPath(&s2);
        addToFullPath(&s3);
        rotateFullPath(rotateAngle);
        translationFullPath(startX1, startY1);
    }
    if(bestPath==RSR) {
        Sector_C s1(initPose, finalPose, bestPath, R, lengthOf_eachPart.at(0));
        s1.setSampled_route();
        Sector_S s2(s1.getPoseAfter(), finalPose, bestPath, lengthOf_eachPart.at(1));
        s2.setSampled_route();
        Sector_C s3(s2.getPoseAfter(), finalPose, bestPath, R, lengthOf_eachPart.at(2));
        s3.setSampled_route();
        addToFullPath(&s1);
        addToFullPath(&s2);
        addToFullPath(&s3);
        rotateFullPath(rotateAngle);
        translationFullPath(startX1, startY1);
    }

}

void PathPlanner::addToFullPath(const Sector *s) {
    for (unsigned long int val = 0; val < s->getSector_Sampled_route().size(); ++val) {
        fullPath.push_back(s->getSector_Sampled_route().at(val));
    }
}

void PathPlanner::rotateFullPath(double angle) {
    for (auto &val: fullPath) {
        double tmp_x = val.getXpose() * cos(angle) - val.getYpose() * sin(angle);
        double tmp_y = val.getXpose() * sin(angle) + val.getYpose() * cos(angle);
        val = {tmp_x, tmp_y, val.getTheta() * 180 / M_PI}; // should be ok
    }
}

void PathPlanner::translationFullPath(double sX, double sY) {
    for (auto &val: fullPath) {
        val = {val.getXpose() + sX, val.getYpose() + sY, val.getTheta() * 180 / M_PI}; // should be ok
    }
}

std::vector<Pose> PathPlanner::getFullPath() {
    return fullPath;
}
