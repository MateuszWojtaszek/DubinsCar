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
PathPlanner::PathPlanner(const Pose &p_in, const Pose &p_fin, MODE m) : initPose(p_in), finalPose(p_fin), mode(m) {
    distance = getDistanceBetweenPos(initPose, finalPose);
    lengthOf_eachPart.reserve(3);
}

void PathPlanner::planPaths() {
    switch (mode) {

        case SHORTEST: {
            if (distance < 4) {
                planPath_RLR();
                planPath_LRL();

            } else {
                planPath_LSL();
                planPath_LSR();
                planPath_RSL();
                planPath_RSR();
            }
        }
            break;
        case LONGEST: {
                planPath_LSL();
                planPath_LSR();
                planPath_RSL();
                planPath_RSR();
            }
            break;
        case JUST_RSR:
            planPath_RSR();
            break;
        case JUST_RSL:
            planPath_RSL();
            break;
        case JUST_LSR:
            planPath_LSR();
            break;
        case JUST_LSL:
            planPath_LSL();
            break;
    }
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
    double lengthOF_Path = lengthOF_firstL + lengthOF_S + lengthOF_SecondL;
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
    double tmp_sum = distance - sin(initPose.getTheta()) + sin(finalPose.getTheta());
    double arctan = mod2pi(std::atan2(diffOfCos, tmp_sum));
    lengthOF_firstR = mod2pi(initPose.getTheta() + arctan);

    /**
    * * Dependencies of second part
    */
    double lengthOF_S;
    double cosOfDiffAngle = cosineOfAngleDifference(initPose.getTheta(), finalPose.getTheta());
    double distSquared = squared(distance);
    double diffOfSin = differenceOfSines(finalPose.getTheta(), initPose.getTheta());
    lengthOF_S = sqrt(2 + distSquared - (2 * cosOfDiffAngle) + (2 * distance * diffOfSin));
    /**
    * * Dependencies of third part
    */
    double lengthOF_SecondR;
    lengthOF_SecondR = mod2pi(mod2pi(-finalPose.getTheta()) + arctan);
    //* * length of Path
    double lengthOF_Path = lengthOF_firstR + lengthOF_S + lengthOF_SecondR;
    //* *  Add length of specific path to the map
    addTO_Paths(lengthOF_Path, RSR);
    LenOfEachPart LofEP = {lengthOF_firstR, lengthOF_S, lengthOF_SecondR};
    addTo_partsOfEeachPath(RSR, LofEP);
}

void PathPlanner::planPath_RSL() {

    /**
    * * Dependencies of second part
    */
    double lengthOF_S;
    double cosOfDiffAngle = cosineOfAngleDifference(initPose.getTheta(), finalPose.getTheta());
    double sineSum = sumOfSines(initPose.getTheta(), finalPose.getTheta());
    double distSquared = squared(distance);
    lengthOF_S = sqrt(-2 + distSquared + 2 * cosOfDiffAngle - 2 * distance * sineSum);

    /**
    * * Dependencies of first part
    */
    double lengthOf_R;
    double cosSum = sumOfCosines(initPose.getTheta(), finalPose.getTheta());
    double tmp_sum = distance - sin(initPose.getTheta()) - sin(finalPose.getTheta());
    double arctan1 = mod2pi(atan2(cosSum, tmp_sum));
    double arctan2 = mod2pi(atan2(2, lengthOF_S));
    lengthOf_R = mod2pi(initPose.getTheta() - arctan1 + arctan2);
    /**
    * * Dependencies of third part
    */
    double lengthOf_L;
    lengthOf_L = mod2pi(mod2pi(finalPose.getTheta()) - arctan1 + arctan2);
    //* * length of Path
    double lengthOF_Path = lengthOf_R + lengthOF_S + lengthOf_L;
    //* *  Add length of specific path to the map
    addTO_Paths(lengthOF_Path, RSL);
    LenOfEachPart LofEP = {lengthOf_R, lengthOF_S, lengthOf_L};
    addTo_partsOfEeachPath(RSL, LofEP);
}

void PathPlanner::planPath_LSR() {
    /**
    * * Dependencies of second part
    */
    double lengthOF_S;
    double cosOfDiffAngle = cosineOfAngleDifference(initPose.getTheta(), finalPose.getTheta());
    double sineSum = sumOfSines(initPose.getTheta(), finalPose.getTheta());
    double distSquared = squared(distance);
    lengthOF_S = sqrt(-2 + distSquared - 2 * cosOfDiffAngle + 2 * distance * sineSum);

    /**
    * * Dependencies of first part
    */
    double lengthOf_L;
    double cosSum = sumOfCosines(initPose.getTheta(), finalPose.getTheta());
    double tmp_sum = distance + sin(initPose.getTheta()) + sin(finalPose.getTheta());
    double arctan1 = mod2pi(atan2(-cosSum, tmp_sum));
    double arctan2 = mod2pi(atan2(-2, lengthOF_S));
    lengthOf_L = mod2pi(-initPose.getTheta() + arctan1 - arctan2);

    /**
    * * Dependencies of third part
    */
    double lengthOf_R;
    lengthOf_R = mod2pi(-finalPose.getTheta() + arctan1 - arctan2);

    //* * length of Path
    double lengthOF_Path = lengthOf_L + lengthOF_S + lengthOf_R;
    //* *  Add length of specific path to the map
    addTO_Paths(lengthOF_Path, LSR);
    LenOfEachPart LofEP = {lengthOf_L, lengthOF_S, lengthOf_R}; // jak nie dziala to zamien
    addTo_partsOfEeachPath(LSR, LofEP);
}

void PathPlanner::planPath_RLR() {
    /**
    * * Dependencies of second part
    */
    double lengthOf_L;
    double cosOfDiffAngle = cosineOfAngleDifference(initPose.getTheta(), finalPose.getTheta());
    double sindiff = differenceOfSines(initPose.getTheta(), finalPose.getTheta());
    double distSquared = squared(distance);
    double tmp_sum = 6 - distSquared + 2 * cosOfDiffAngle + 2 * distance * sindiff;
    lengthOf_L = acos(1.0 / 8 * tmp_sum);

    /**
    * * Dependencies of first part
    */
    double lengthOf_R1;
    double cosdiff = differenceOfCosines(initPose.getTheta(), finalPose.getTheta());
    double tmp_sum2 = distance - sin(initPose.getTheta()) + sin(finalPose.getTheta());
    double arctan = mod2pi(atan2(cosdiff, tmp_sum2));
    lengthOf_R1 = mod2pi(initPose.getTheta() - arctan + lengthOf_L / 2);

    /**
    * * Dependencies of third part
    */
    double lengthOf_R2;
    lengthOf_R2 = mod2pi(initPose.getTheta() - finalPose.getTheta() - lengthOf_R1 + lengthOf_L);

    //* * length of Path
    double lengthOF_Path = lengthOf_R1 + lengthOf_L + lengthOf_R2;
    //* *  Add length of specific path to the map
    addTO_Paths(lengthOF_Path, RLR);
    LenOfEachPart LofEP = {lengthOf_R1, lengthOf_L, lengthOf_R2}; // jak nie dziala to zamien
    addTo_partsOfEeachPath(RLR, LofEP);
}

void PathPlanner::planPath_LRL() {
    /**
    * * Dependencies of second part
    */
    double lengthOf_R;
    double cosOfDiffAngle = cosineOfAngleDifference(initPose.getTheta(), finalPose.getTheta());
    double sindiff = differenceOfSines(finalPose.getTheta(), initPose.getTheta());
    double distSquared = squared(distance);
    double tmp_sum = 6 - distSquared + 2.0 * cosOfDiffAngle + 2 * distance * sindiff;
    lengthOf_R = mod2pi(acos(tmp_sum / 8));

    /**
    * * Dependencies of first part
    */
    double lengthOf_L1;
    double cosdiff = differenceOfCosines(initPose.getTheta(), finalPose.getTheta());
    double tmp_sum2 = distance + sin(initPose.getTheta()) - sin(finalPose.getTheta());
    double arctan = atan2(cosdiff, tmp_sum2);
    lengthOf_L1 = mod2pi(-initPose.getTheta() - arctan + lengthOf_R / 2);

    /**
    * * Dependencies of third part
    */
    double lengthOf_L2;
    lengthOf_L2 = mod2pi(mod2pi(finalPose.getTheta() - initPose.getTheta() - lengthOf_L1 + mod2pi(lengthOf_R)));

    //* * length of Path
    double lengthOF_Path = lengthOf_L1 + lengthOf_R + lengthOf_L2;
    //* *  Add length of specific path to the map
    addTO_Paths(lengthOF_Path, LRL);
    LenOfEachPart LofEP = {lengthOf_L1, lengthOf_R, lengthOf_L2}; // jak nie dziala to zamien
    addTo_partsOfEeachPath(LRL, LofEP);
}

void PathPlanner::addTO_Paths(const double &d, const PATH &p) {
    Paths[d] = p;
}

void PathPlanner::setBestPath() {
    double tmp_best = 0;
    if (mode==LONGEST) {
        for (auto path: Paths) {
            if (tmp_best < path.first || tmp_best == 0) tmp_best = path.first;
        }
    } else{
        for (auto path: Paths) {
            if (tmp_best > path.first || tmp_best == 0) tmp_best = path.first;
        }
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
    initPose = {0, 0, initPose.getTheta() * 180.0 /
                      M_PI};                //? perform translations to the origin of the coordinate system
    finalPose = {finalPose.getXpose() - startX1, finalPose.getYpose() - startY1,
                 finalPose.getTheta() * (180 / M_PI)};
    rotateAngle = mod2pi(atan2(finalPose.getYpose(), finalPose.getXpose()));
    rotatefinalPos(rotateAngle); //? rotate the end position on the OX axis
    planPaths();
    switch (bestPath) {
        case RSR:
            setPath_RSR(startX1, startY1, rotateAngle);
            break;
        case RSL:
            setPath_RSL(startX1, startY1, rotateAngle);
            break;
        case LSR:
            setPath_LSR(startX1, startY1, rotateAngle);
            break;
        case LSL:
            setPath_LSL(startX1, startY1, rotateAngle);
            break;
        case RLR:
            setPath_RLR(startX1, startY1, rotateAngle);
            break;
        case LRL:
            setPath_LRL(startX1, startY1, rotateAngle);
            break;
        case NONE:
            break;
        default:
            std::cerr << "ERROR" << std::endl;
            break;
    }
}

void PathPlanner::addToFullPath(const Sector *s) {
    for (unsigned long int val = 0; val < s->getSector_Sampled_route().size(); ++val) {
        fullPath.push_back(s->getSector_Sampled_route().at(val));
    }
}

void PathPlanner::translationFullPath(double sX, double sY) {
    for (auto &val: fullPath) {
        val = {val.getXpose() + sX, val.getYpose() + sY, val.getTheta() * 180 / M_PI};
    }
}

std::vector<Pose> PathPlanner::getFullPath() {
    return fullPath;
}

void PathPlanner::setPath_LSL(const double &startX, const double &startY, const double &rotAngle) {
    Sector_C s1(initPose, finalPose, bestPath, L, lengthOf_eachPart.at(0));
    s1.setSampled_route();
    Sector_S s2(s1.getPoseAfter(), finalPose, bestPath, lengthOf_eachPart.at(1));
    s2.setSampled_route();
    Sector_C s3(s2.getPoseAfter(), finalPose, bestPath, L, lengthOf_eachPart.at(2));
    s3.setSampled_route();
    addToFullPath(&s1);
    addToFullPath(&s2);
    addToFullPath(&s3);
    //? we perform the inverse transformation
    rotateFullPath(rotAngle);
    translationFullPath(startX, startY);
}

void PathPlanner::setPath_RSR(const double &startX, const double &startY, const double &rotAngle) {
    Sector_C s1(initPose, finalPose, bestPath, R, lengthOf_eachPart.at(0));
    s1.setSampled_route();
    Sector_S s2(s1.getPoseAfter(), finalPose, bestPath, lengthOf_eachPart.at(1));
    s2.setSampled_route();
    Sector_C s3(s2.getPoseAfter(), finalPose, bestPath, R, lengthOf_eachPart.at(2));
    s3.setSampled_route();
    addToFullPath(&s1);
    addToFullPath(&s2);
    addToFullPath(&s3);
    //? we perform the inverse transformation
    rotateFullPath(rotAngle);
    translationFullPath(startX, startY);


}

void PathPlanner::rotatefinalPos(double angle) {
    initPose = {0, 0, (initPose.getTheta() - angle) * 180.0 /
                      M_PI};  //? we need to correct the orientation according to the rotation
    double tmp_x2 = finalPose.getXpose() * cos(angle) + finalPose.getYpose() * sin(angle);
    double tmp_y2 = -finalPose.getXpose() * sin(angle) + finalPose.getYpose() * cos(angle);
    finalPose = {tmp_x2, tmp_y2, (finalPose.getTheta() - angle) * 180.0 /
                                 M_PI};  //? we need to correct the orientation according to the rotation
}

void PathPlanner::rotateFullPath(double angle) {
    for (auto &val: fullPath) {
        double tmp_x = val.getXpose() * cos(angle) - val.getYpose() * sin(angle);
        double tmp_y = val.getXpose() * sin(angle) + val.getYpose() * cos(angle);
        val = {tmp_x, tmp_y, val.getTheta() * 180 / M_PI};
    }

}

void PathPlanner::setPath_RSL(const double &startX, const double &startY, const double &rotAngle) {
    Sector_C s1(initPose, finalPose, bestPath, R, lengthOf_eachPart.at(0));
    s1.setSampled_route();
    Sector_S s2(s1.getPoseAfter(), finalPose, bestPath, lengthOf_eachPart.at(1));
    s2.setSampled_route();
    Sector_C s3(s2.getPoseAfter(), finalPose, bestPath, L, lengthOf_eachPart.at(2));
    s3.setSampled_route();
    addToFullPath(&s1);
    addToFullPath(&s2);
    addToFullPath(&s3);
    //? we perform the inverse transformation
    rotateFullPath(rotAngle);
    translationFullPath(startX, startY);
}

void PathPlanner::setPath_LSR(const double &startX, const double &startY, const double &rotAngle) {
    Sector_C s1(initPose, finalPose, bestPath, L, lengthOf_eachPart.at(0));
    s1.setSampled_route();
    Sector_S s2(s1.getPoseAfter(), finalPose, bestPath, lengthOf_eachPart.at(1));
    s2.setSampled_route();
    Sector_C s3(s2.getPoseAfter(), finalPose, bestPath, R, lengthOf_eachPart.at(2));
    s3.setSampled_route();
    addToFullPath(&s1);
    addToFullPath(&s2);
    addToFullPath(&s3);
    //? we perform the inverse transformation
    rotateFullPath(rotAngle);
    translationFullPath(startX, startY);
}

void PathPlanner::setPath_RLR(const double &startX, const double &startY, const double &rotAngle) {
    Sector_C s1(initPose, finalPose, bestPath, R, lengthOf_eachPart.at(0));
    s1.setSampled_route();
    Sector_C s2(s1.getPoseAfter(), finalPose, bestPath, L, lengthOf_eachPart.at(1));
    s2.setSampled_route();
    Sector_C s3(s2.getPoseAfter(), finalPose, bestPath, R, lengthOf_eachPart.at(2));
    s3.setSampled_route();
    addToFullPath(&s1);
    addToFullPath(&s2);
    addToFullPath(&s3);
    //? we perform the inverse transformation
    rotateFullPath(rotAngle);
    translationFullPath(startX, startY);
}

void PathPlanner::setPath_LRL(const double &startX, const double &startY, const double &rotAngle) {
    Sector_C s1(initPose, finalPose, bestPath, L, lengthOf_eachPart.at(0));
    s1.setSampled_route();
    Sector_C s2(s1.getPoseAfter(), finalPose, bestPath, R, lengthOf_eachPart.at(1));
    s2.setSampled_route();
    Sector_C s3(s2.getPoseAfter(), finalPose, bestPath, L, lengthOf_eachPart.at(2));
    s3.setSampled_route();
    addToFullPath(&s1);
    addToFullPath(&s2);
    addToFullPath(&s3);
    //? we perform the inverse transformation
    rotateFullPath(rotAngle);
    translationFullPath(startX, startY);
}
