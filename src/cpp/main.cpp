#include "../headers/Visualization.h"
#include "../headers/PathPlanner.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1143), "Dubins' vehicle animation - Wojtaszek Mateusz");
    window.setVerticalSyncEnabled(true);
    Visualization visualize(window);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
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
