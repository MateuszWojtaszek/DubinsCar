#include "../heders/Sector_C.h"
#include "../heders/PathPlanner.h"
#include "../heders/Sector_S.h"
#include "../heders/Sector.h"


int main() {
    Pose P_init(8, 12, 270);
    Pose P_end(14, 19, 180);
    PathPlanner planner(P_init, P_end);
    planner.planPathsFromOrigin();
    for (unsigned long val = 0; val < planner.getFullPath().size(); ++val) {
        std::cout<<planner.getFullPath().at(val);
    }

}
