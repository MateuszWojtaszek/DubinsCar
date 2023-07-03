//
// Created by mateusz on 09.06.23.
//

#ifndef DUBBINS_CAR_CAR_H
#define DUBBINS_CAR_CAR_H
#include <vector>
#include "Pose.h"
class Car {
   const std::vector<Pose> fullPath;
public:
    explicit Car(const std::vector<Pose> &v);
     [[nodiscard]] std::vector<Pose> getFullPath() const;
};


#endif //DUBBINS_CAR_CAR_H
