//
// Created by mateusz on 09.06.23.
//

#include "../headers/Car.h"

Car::Car(const std::vector<Pose> &v):fullPath(v) {

}

std::vector<Pose> Car::getFullPath() const {
    return fullPath;
}
