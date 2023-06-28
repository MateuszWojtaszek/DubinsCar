//
// Created by mateusz on 27.06.23.
//

#ifndef DUBBINS_CAR_VISUALIZATION_H
#define DUBBINS_CAR_VISUALIZATION_H
#include <SFML/Graphics.hpp>
#include "Car.h"
class Visualization {
    sf::RenderWindow &window;
    const Car &car;
    sf::CircleShape probe{1};
    sf::View view={};
    sf::Sprite banner={};
    sf::Texture bannerTexture={};
    sf::Sprite background={};
    sf::Texture backgroundTexture={};
    sf::Sprite infoText{};
    sf::Texture infoTextTexture{};

    void prepareBackground();
    void prepareBanner();
    void prepareInfoText();
public:
    Visualization(sf::RenderWindow &win,const Car &c);
    void drawPath();
    void drawEnvironment();
};


#endif //DUBBINS_CAR_VISUALIZATION_H
