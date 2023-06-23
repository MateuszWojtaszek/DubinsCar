#include "../heders/Sector_C.h"
#include "../heders/PathPlanner.h"

int main() {
    Pose P_init(0, 0, -135);
    Pose P_end(2, 2, 135);
    PathPlanner planner(P_init, P_end);
    planner.planPaths();
    PATH bestPath = planner.getBestPath();
    Sector_C s(P_init, P_end, bestPath, L1, planner.getLengthOf_EachPart().at(0));
    s.setSampled_route();
    for (unsigned long int i = 0; i < s.getSector_Sampled_route().size(); ++i) {
        std::cout<<s.getSector_Sampled_route().at(i);
    }
}
