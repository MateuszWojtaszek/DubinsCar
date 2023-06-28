#include "../heders/Visualization.h"
#include "../heders/PathPlanner.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(1920,1143),"test");
    window.setVerticalSyncEnabled(true);
    Pose P_init(50, 100, -45);
    Pose P_end(90,250 , 180);
    PathPlanner planner(P_init, P_end);
    planner.planPathsFromOrigin();
    Car tesla(planner.getFullPath());
    Visualization visualize(window,tesla);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
                std::cout<<"Pos x: "<<sf::Mouse::getPosition(window).x
                <<"Pos y: "<<sf::Mouse::getPosition(window).y<<std::endl;
        }
        window.clear();
       // visualize.drawPath();
        visualize.drawEnvironment();
        window.display();
    }
}
