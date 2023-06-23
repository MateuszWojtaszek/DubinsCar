//
// Created by mateusz on 09.06.23.
//

#ifndef DUBBINS_CAR_PATHPLANNER_H
#define DUBBINS_CAR_PATHPLANNER_H


#include "Pose.h"
#include <map>
#include "../heders/MATH.h"
#include "Enums.h"
#include <vector>



class PathPlanner {
    PATH bestPath = NONE;
/**
 ** a distance between init Pose and final Pose
 */
    double distance=0;
    Pose initPose;
    Pose finalPose;
    /**
     ** map containing the length of each part for each path
     */
    std::map<PATH,LenOfEachPart> partsOfEachPath={};
    /**
     ** a function that add a pair to a map
     * @param p - path
     * @param lep - lenght of each part
     */
    void addTo_partsOfEeachPath(const PATH &p, const LenOfEachPart &lep);

    std::vector<double> lengthOf_eachPart={};
/**
 * a map for each path with it's length
 */
    std::map<double, PATH> Paths={};

    void addTO_Paths(const double &d,const PATH &p);

    void planPath_LSL();

    void planPath_RSR();

    void planPath_RSL();

    void planPath_LSR();

    void planPath_RLR();

    void planPath_LRL();
    /**
     ** a function that iterates a map Paths and set a variable bestPath
     */
    void setBestPath();

public:
    /**
     *
     * @param p_in - initial Pose
     * @param p_fin - final Pose
     */
    PathPlanner(const Pose &p_in, const Pose &p_fin);
    /**
     * a funtion that plan paths
     */
    void planPaths();
    /**
     * simple getter for best path
     * @return bestPath
     */
    [[nodiscard]] PATH getBestPath() const;

    std::vector<double> getLengthOf_EachPart();

};


#endif //DUBBINS_CAR_PATHPLANNER_H
