//
// Created by mateusz on 09.06.23.
//

#ifndef DUBBINS_CAR_PATHPLANNER_H
#define DUBBINS_CAR_PATHPLANNER_H


#include "Pose.h"
#include <map>
#include "MATH.h"
#include "Enums.h"
#include <vector>
#include "Sector_C.h"
#include "Sector_S.h"



class PathPlanner {
    PATH bestPath = NONE;
    /**
     ** a distance between init Pose and final Pose
     */
    double distance = 0;
    /**
     ** initial robot position
     */
    Pose initPose;
    /**
     ** final robot position
     */
    Pose finalPose;
    MODE mode;
    std::vector<Pose> fullPath = {};

    /**
     ** map containing the length of each part for each path
     */
    std::map<PATH, LenOfEachPart> partsOfEachPath = {};

    /**
     ** function that add a pair to a map
     * @param p - path
     * @param lep - lenght of each part
     */
    void addTo_partsOfEeachPath(const PATH &p, const LenOfEachPart &lep);

    std::vector<double> lengthOf_eachPart = {};
    /**
     * a map for each path with it's length
     */
    std::map<double, PATH> Paths = {};

    /**
     * function that adds the length of the path with its name to the map
     * @param d
     * @param p
     */
    void addTO_Paths(const double &d, const PATH &p);
    //! path preparation functions
    void planPath_LSL();

    void setPath_LSL(const double &startX, const double &startY, const double &rotAngle);

    void planPath_RSR();

    void setPath_RSR(const double &startX, const double &startY, const double &rotAngle);

    void planPath_RSL();

    void setPath_RSL(const double &startX, const double &startY, const double &rotAngle);

    void planPath_LSR();

    void setPath_LSR(const double &startX, const double &startY, const double &rotAngle);

    void planPath_RLR();

    void setPath_RLR(const double &startX, const double &startY, const double &rotAngle);

    void planPath_LRL();

    void setPath_LRL(const double &startX, const double &startY, const double &rotAngle);

    /**
     ** function that iterates a map Paths and set a variable bestPath
     */
    void setBestPath();

    /**
 * a funtion that plan paths
 */
    void planPaths();

    /**
     ** function that add full sector to the fullPath vector
     * @param s
     */
    void addToFullPath(const Sector *s);

    /**
     ** function that rotate full path by the angle between the start vector and the OX axis
     */
    void rotateFullPath(double angle);

    /**
     ** funtion that "prepares" a final Pos by rotating it to OX axis
     * @param angle
     */
    void rotatefinalPos(double angle);

    /**
     ** funtion that do translation to the full path -> returns to correct position
     * @param sX
     * @param sY
     */
    void translationFullPath(double sX, double sY);

public:
    /**
     *
     * @param p_in - initial Pose
     * @param p_fin - final Pose
     */
    PathPlanner(const Pose &p_in, const Pose &p_fin, MODE m);

    /**
     * simple getter for best path
     * @return bestPath
     */
    [[nodiscard]] PATH getBestPath() const;

    std::vector<double> getLengthOf_EachPart();

    void planPathsFromOrigin();

    std::vector<Pose> getFullPath();

};


#endif //DUBBINS_CAR_PATHPLANNER_H
