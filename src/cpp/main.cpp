#include "../heders/Visualization.h"
#include "../heders/PathPlanner.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1143), "Dubins' vehicle animation - Wojtaszek Mateusz");
    window.setVerticalSyncEnabled(true);
    Visualization visualize(window);

    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
               std::cout<<"Pos x: "<<sf::Mouse::getPosition(window).x
               <<"Pos y: "<<sf::Mouse::getPosition(window).y<<std::endl;
            }
        }
        window.clear();
        // visualize.drawPath();
        if(visualize.getStatus() == START) {
            visualize.drawEnvironment();
            visualize.highlight();
        }
        if(visualize.getStatus() == PLANNING) {
            visualize.drawAnimEnvironment();
            visualize.animate();
        }
        if(visualize.getStatus() == ANIMATION){
            visualize.drawAnimEnvironment();
            visualize.animate();
            PathPlanner planner(visualize.getInitPosition(), visualize.getFinalPosition(), visualize.getMode());
            planner.planPathsFromOrigin();
            Car tesla(planner.getFullPath());
            visualize.drawPath(tesla);
        }
        window.display();
    }
}
