//
// Created by mateusz on 22.06.23.
//

#ifndef DUBBINS_CAR_MATH_H
#define DUBBINS_CAR_MATH_H

#include <cmath>
#include "Pose.h"

/**
 ** a function that returns a %2pi value
 * @param val
 * @return val % 2*M_PI
 */
double mod2pi(const double &val);

/**
 ** a function that return a difference of cosines
 * @param angle1
 * @param angle2
 * @return differenceOfCosines cos(angle1) - cos(angle2)
 */
double differenceOfCosines(const double &angle1, const double &angle2);

/**
 ** a function that return a sum of cosines
 * @param angle1
 * @param angle2
 * @return sumOfCosines cos(angle1) + cos(angle2)
 */
double sumOfCosines(const double &angle1, const double &angle2);

/**
 ** a function that return a cosine of angles difference cos(alfa-beta)
 * @param angle1
 * @param angle2
 * @return  cosineOfAngleDifference cos(angle1-angle2)
 */
double cosineOfAngleDifference(const double &angle1, const double &angle2);

/**
 ** a function that return a cosine of angles Sum cos(alfa+beta)
 * @param angle1
 * @param angle2
 * @return  cosineOfAngleSum cos(angle1+angle2)
 */
double cosineOfAngleSum(const double &angle1, const double &angle2);

/**
 ** a function that return a distance between two Positions
 * @param p1
 * @param p2
 * @return sqrt((p1.x-p2.x)^2+(p1.y-p2.y)^2)
 */
double getDistanceBetweenPos(const Pose &p1, const Pose &p2);

/**
 ** a function that returns a difference of sines
 * @param angle1
 * @param angle2
 * @return differenceOfSines sin(angle1) - sin(angle2)
 */
double differenceOfSines(const double &angle1, const double &angle2);

/**
 ** a function that returns a sum of sines
 * @param angle1
 * @param angle2
 * @return differenceOfSines sin(angle1) + sin(angle2)
 */
double sumOfSines(const double &angle1, const double &angle2);

/**
 ** a function that return a sine of angles difference sin(alfa-beta)
 * @param angle1
 * @param angle2
 * @return sineOfAngleDifference sin(angle1-angle2)
 */
double sineOfAngleDifference(const double &angle1, const double &angle2);



/**
 ** a function that return a sine of angles Sum sin(alfa+beta)
 * @param angle1
 * @param angle2
 * @return sineOfAngleSum sin(angle1+angle2)
 */
double sineOfAngleSum(const double &angle1, const double &angle2);

/**
 ** a function that return a squared value
 * @param val
 * @return val^2
 */
double squared(const double &val);

#endif //DUBBINS_CAR_MATH_H
