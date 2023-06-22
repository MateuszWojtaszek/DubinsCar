#include "../heders/Sector_C.h"
#include "../heders/Sector_S.h"
int main() {
Pose P_in(0,0,0);
Pose P_end(2,2,30);
Sector_C s1(P_in,P_end,L);
std::cout<<Sector::getDistance_between_pos(P_in,P_end)<<std::endl;
s1.setSector_Sampled_route();
    for (unsigned long pos = 0; pos< s1.getSector_Sampled_route().size(); ++pos) {
        std::cout<<(s1.getSector_Sampled_route().at(pos))<<std::endl;
        //std::cout<<"im here"<<std::endl;
    }
Pose p_s=s1.getPose_after();
    Sector_S line(p_s,P_end,P_in);
    line.setSector_Sampled_route();
    for (unsigned long pos = 0; pos< line.getSector_Sampled_route().size(); ++pos) {
        std::cout<<line.getSector_Sampled_route().at(pos)<<std::endl;
        //std::cout<<"im here"<<std::endl;
    }
    return 0;
}
