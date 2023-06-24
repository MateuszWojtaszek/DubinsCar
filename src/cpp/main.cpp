#include "../heders/Sector_C.h"
#include "../heders/PathPlanner.h"
#include "../heders/Sector_S.h"
int main() {
    Pose P_init(0, 0, -45);
    Pose P_end(2, 0, 45);
    PathPlanner planner(P_init, P_end);
    planner.planPaths();
    PATH bestPath = planner.getBestPath();
    Sector_C s1(P_init, P_end, bestPath, L1, planner.getLengthOf_EachPart().at(0));
    s1.setSampled_route();
    for (unsigned long int i = 0; i < s1.getSector_Sampled_route().size(); ++i) {
        std::cout<<s1.getSector_Sampled_route().at(i);
    }
    Sector_S s2(s1.getPoseAfter(),P_end,bestPath,S,planner.getLengthOf_EachPart().at(1));
    s2.setSampled_route();
    for (unsigned long int i = 0; i < s2.getSector_Sampled_route().size(); ++i) {
        std::cout<<s2.getSector_Sampled_route().at(i);
    }
    Sector_C s3(s2.getPoseAfter(),P_end,bestPath,L2,planner.getLengthOf_EachPart().at(2));
    s3.setSampled_route();
    for (unsigned long int i = 0; i < s3.getSector_Sampled_route().size(); ++i) {
        std::cout<<s3.getSector_Sampled_route().at(i);
    }

}
