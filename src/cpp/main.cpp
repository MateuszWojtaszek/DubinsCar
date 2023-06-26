#include "../heders/Sector_C.h"
#include "../heders/PathPlanner.h"
#include "../heders/Sector_S.h"
#include "../heders/Sector.h"


int main() {
    Pose P_init(3, 5, 270);
    Pose P_end(25, 50, -270);
    PathPlanner planner(P_init, P_end);
    planner.planPathsFromOrigin();
    for (unsigned long val = 0; val < planner.getFullPath().size(); ++val) {
        std::cout<<planner.getFullPath().at(val);
    }

}
