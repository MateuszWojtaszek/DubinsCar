#include "../heders/Sector_C.h"
#include "../heders/PathPlanner.h"

int main() {
    Pose P_init(0, 0, 0);
    Pose P_end(2, 2, 30);
    PathPlanner planner(P_init, P_end);
    planner.planPaths();
    PATH bestPath = planner.getBestPath();
    Sector_C s(P_init, P_end, bestPath, L1, (270.0/360)*2*M_PI);
    s.setSampled_route();
    for (unsigned long int i = 0; i < s.getSector_Sampled_route().size(); ++i) {
        std::cout<<s.getSector_Sampled_route().at(i);
    }
}
