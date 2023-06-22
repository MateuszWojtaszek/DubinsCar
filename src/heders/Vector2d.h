//
// Created by mateusz on 09.06.23.
//

#ifndef DUBBINS_CAR_VECTOR2D_H
#define DUBBINS_CAR_VECTOR2D_H
#include <iostream>
#include <cmath>
//class that models vectors and operations on them
class Vector2d {
// ordinary positions on the Cartesian plane
double pos_x,pos_y;

/*************OPERATORS OVERLOADING************************
 * return type operator@(type of left operand &name of right operand
 *
 *                                                                  */
public:

/**
 *vector change to the opposite vector
 * @return
 */
Vector2d operator !();


/**
 *comparison of vectors
 * @param v
 * @return
 */
bool operator ==(const Vector2d &v) const;


/**
 *addition of vectors
 * @param v1
 * @param v2
 * @return
 */
friend Vector2d operator+(const Vector2d &v1, const Vector2d &v2);


/**
 *subtraction of vectors
 * @param v1
 * @param v2
 * @return
 */
friend Vector2d operator-(const Vector2d &v1, const Vector2d &v2);


/**
 *Multiplication by a number
 * @param d
 * @param v
 * @return
 */
friend Vector2d operator*(const double &d,const Vector2d &v);
friend Vector2d operator*(const Vector2d &v, const double &d);


/**
 *Dividing by a number
 * @param d
 * @param v
 * @return
 */
friend Vector2d operator/(const double &d,const Vector2d &v);
friend Vector2d operator/(const Vector2d &v, const double &d);


/**
 *writing to the output stream
 * @param s
 * @param v
 * @return
 */
friend std::ostream &operator<<(std::ostream &s, const Vector2d &v);

//Multiplication by a vector (scalar)
/**
 *
 * @param v1
 * @param v2
 * @return
 */
friend double operator*(const Vector2d &v1, const Vector2d &v2);



//Constructor
explicit Vector2d(double x,double y);

//length of vector - nodiscard cuz we need to be sure that we got a value and we are using it
[[nodiscard]] double getLength() const;

//simple getters
[[nodiscard]] double getXpose() const;
[[nodiscard]] double getYpose() const;
};



std::ostream &operator<<(std::ostream &s, const Vector2d &v);
Vector2d operator+(const Vector2d &v1, const Vector2d &v2);
Vector2d operator*(const Vector2d &v, const float &f);
Vector2d operator-(const Vector2d &v1, const Vector2d &v2);
double operator*(const Vector2d &v1, const Vector2d &v2);
#endif //DUBBINS_CAR_VECTOR2D_H
