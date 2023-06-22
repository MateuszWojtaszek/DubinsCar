//
// Created by mateusz on 09.06.23.
//

#ifndef DUBBINS_CAR_PATHPLANNER_H
#define DUBBINS_CAR_PATHPLANNER_H

#include "Sector_S.h"
#include "Sector_C.h"
#include <map>
#include "../heders/MATH.h"

enum PATH {
    RSR,
    RSL,
    LSR,
    LSL,
    RLR,
    LRL,
    NONE
};


class PathPlanner {
    PATH bestPath = NONE;
/**
 * a distance between init Pose and final Pose
 */
    double distance;
    Pose initPose;
    Pose finalPose;
/**
 * a map for each path with it's length
 */
    std::map<double, PATH> Paths;

    void addTO_Paths(const PATH &p, const double &d);

    void planPath_LSL();

    void planPath_RSR();

    void planPath_RSL();

    void planPath_LSR();

    void planPath_RLR();

    void planPath_LRL();
    /**
     * a function that iterates a map Paths and set a variable bestPath
     */
    void setBestPath();

public:
    /**
     *
     * @param p_in - initial Pose
     * @param p_fin - final Pose
     */
    PathPlanner(const Pose &p_in, const Pose &p_fin);

    void planPaths();

    [[nodiscard]] PATH getBestPath() const;

};


#endif //DUBBINS_CAR_PATHPLANNER_H
