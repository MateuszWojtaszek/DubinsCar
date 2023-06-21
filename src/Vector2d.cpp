//
// Created by mateusz on 09.06.23.
//

#include "Vector2d.h"

Vector2d Vector2d::operator!() {
    return Vector2d(-this->pos_x, -this->pos_y);
}

Vector2d::Vector2d(float x, float y):pos_x(x),pos_y(y) {}

bool Vector2d::operator==(const Vector2d &v) const {
    if(this->pos_x==v.pos_x && this->pos_y==v.pos_y) return true;
    return false;
}

Vector2d operator*(const float &f,const Vector2d &v){
    return Vector2d(v.pos_x*f,v.pos_y*f);
}

std::ostream &operator<<(std::ostream &s, const Vector2d &v){
    return s<<v.pos_x<<','<<v.pos_y<<std::endl;
}

Vector2d operator+(const Vector2d &v1, const Vector2d &v2) {
    return Vector2d(v1.pos_x+v2.pos_x, v1.pos_y+v2.pos_y);
}

Vector2d operator*(const Vector2d &v, const float &f) {
    return Vector2d(v.pos_x*f,v.pos_y*f);
}

Vector2d operator-(const Vector2d &v1, const Vector2d &v2) {
    return Vector2d(v1.pos_x-v2.pos_x, v1.pos_y-v2.pos_y);
}

float operator*(const Vector2d &v1, const Vector2d &v2) {
    return v1.pos_x*v2.pos_x+v1.pos_y*v2.pos_y;
}

Vector2d operator/(const float &f, const Vector2d &v) {
    return Vector2d(v.pos_x/f, v.pos_y/f);
}

Vector2d operator/(const Vector2d &v, const float &f) {
    return Vector2d(v.pos_x/f, v.pos_y/f);
}

double Vector2d::getLength() const {return (sqrt(pow(static_cast<double>(this->pos_x), 2)
                                            + pow(static_cast<double>(this->pos_y), 2)));}

float Vector2d::getXpose() const {
    return this->pos_x;
}

float Vector2d::getYpose() const {
    return this->pos_y;
}
