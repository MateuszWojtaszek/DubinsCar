#include "Sector_C.h"
int main() {
Pose P_in(2,2,0);
Pose P_end(6,9,45);
Sector_C s1(P_in,P_end,L);
std::cout<<Sector::getDistance_between_pos(P_in,P_end)<<std::endl;
    for (unsigned long pos = 0; pos < 120; ++pos) {
        std::cout<<s1.getSector_Sampled_route().at(pos)<<std::endl;
        //std::cout<<"im here"<<std::endl;
    }

}
