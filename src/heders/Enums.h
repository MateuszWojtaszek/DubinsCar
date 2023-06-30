//
// Created by mateusz on 23.06.23.
//

#ifndef DUBBINS_CAR_ENUMS_H
#define DUBBINS_CAR_ENUMS_H
enum PATH {
    RSR,
    RSL,
    LSR,
    LSL,
    RLR,
    LRL,
    NONE
};
enum MODE{
    SHORTEST,
    LONGEST,
    JUST_RSR,
    JUST_RSL,
    JUST_LSR,
    JUST_LSL,
};
struct LenOfEachPart{
    double l1,l2,l3;
};

enum STATUS{
    START,
    PLANNING,
    ANIMATION
};
#endif //DUBBINS_CAR_ENUMS_H
