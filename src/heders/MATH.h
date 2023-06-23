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
 * @return difference_ofCosines cos(angle1) - cos(angle2)
 */
double difference_ofCosines(const double &angle1, const double &angle2);

/**
 ** a function that return a cosine of angles difference cos(alfa-beta)
 * @param angle1
 * @param angle2
 * @return  cosine_OfAngleDifference cos(angle1-angle2)
 */
double cosine_OfAngleDifference(const double &angle1, const double &angle2);

/**
 ** a function that return a cosine of angles Sum cos(alfa+beta)
 * @param angle1
 * @param angle2
 * @return  cosine_OfAngleSum cos(angle1+angle2)
 */
double cosine_OfAngleSum(const double &angle1, const double &angle2);

/**
 ** a function that return a distance between two Positions
 * @param p1
 * @param p2
 * @return sqrt((p1.x-p2.x)^2+(p1.y-p2.y)^2)
 */
double getDistance_between_pos(const Pose &p1, const Pose &p2);

/**
 * a function that returns a difference of sines
 * @param angle1
 * @param angle2
 * @return difference_ofSines sin(angle1) - sin(angle2)
 */
double difference_ofSines(const double &angle1, const double &angle2);

/**
 ** a function that return a sine of angles difference sin(alfa-beta)
 * @param angle1
 * @param angle2
 * @return sine_OfAngleDifference sin(angle1-angle2)
 */
double sine_OfAngleDifference(const double &angle1, const double &angle2);

/**
 ** a function that return a sine of angles Sum sin(alfa+beta)
 * @param angle1
 * @param angle2
 * @return sine_OfAngleSum sin(angle1+angle2)
 */
double sine_OfAngleSum(const double &angle1, const double &angle2);

/**
 ** a function that return a squared value
 * @param val
 * @return val^2
 */
double squared(const double &val);

#endif //DUBBINS_CAR_MATH_H
