//
// Created by mateusz on 09.06.23.
//

#ifndef DUBBINS_CAR_VECTOR2D_H
#define DUBBINS_CAR_VECTOR2D_H
#include <iostream>
#include <math.h>
//class that models vectors and operations on them
class Vector2d {
// ordinary positions on the Cartesian plane
float pos_x,pos_y;

/*************OPERATORS OVERLOADING************************
 * return type operator@(type of left operand &name of right operand
 *
 *                                                                  */
public:
//vector change to the opposite vector
Vector2d operator !();

//comparison of vectors
bool operator ==(const Vector2d &v) const;

//addition of vectors
friend Vector2d operator+(const Vector2d &v1, const Vector2d &v2);

//subtraction of vectors
friend Vector2d operator-(const Vector2d &v1, const Vector2d &v2);

//Multiplication by a number
friend Vector2d operator*(const float &f,const Vector2d &v);
friend Vector2d operator*(const Vector2d &v, const float &f);

//Dividing by a number
friend Vector2d operator/(const float &f,const Vector2d &v);
friend Vector2d operator/(const Vector2d &v, const float &f);

//writing to the output stream
friend std::ostream &operator<<(std::ostream &s, const Vector2d &v);

//Multiplication by a vector (scalar)
friend float operator*(const Vector2d &v1, const Vector2d &v2);



//Constructor
explicit Vector2d(float x,float y);

//length of vector - nodiscard cuz we need to be sure that we got a value and we are using it
[[nodiscard]] float getLength() const;

//simple getters
[[nodiscard]] float getXpose() const;
[[nodiscard]] float getYpose() const;
};



std::ostream &operator<<(std::ostream &s, const Vector2d &v);
Vector2d operator+(const Vector2d &v1, const Vector2d &v2);
Vector2d operator*(const Vector2d &v, const float &f);
Vector2d operator-(const Vector2d &v1, const Vector2d &v2);
float operator*(const Vector2d &v1, const Vector2d &v2);
#endif //DUBBINS_CAR_VECTOR2D_H
