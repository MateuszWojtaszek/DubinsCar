//
// Created by mateusz on 09.06.23.
//

#include "../heders/Car.h"

Car::Car(const std::vector<Pose> &v):fullPath(v) {

}

void Car::showFullPath() const {
    for (const auto & val : fullPath) {
        std::cout<<val;
    }
}

std::vector<Pose> Car::getFullPath() const {
    return fullPath;
}
