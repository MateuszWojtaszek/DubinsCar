//
// Created by mateusz on 27.06.23.
//

#ifndef DUBBINS_CAR_VISUALIZATION_H
#define DUBBINS_CAR_VISUALIZATION_H

#include <SFML/Graphics.hpp>
#include "Car.h"
#include "Enums.h"

class Visualization {
    sf::RenderWindow &window;
    const Car &car;
    sf::CircleShape probe{1};
    sf::View view = {};
    sf::Sprite background = {}, banner{},infoText{}, RSR{}, LSR{}, LSL{}, RSL{}, Longest{},signature{}, Continue{}, sideBanner{}, bottomSideBanner{}, positionInfo{}, scale{};
    sf::Texture backgroundTexture{}, bannerTexture{}, infoTextTexture{}, RSRTexture{}, LSRTexture{},
    LSLTexture{}, RSLTexture{}, LongestTexture{},signatureTexture{}, ContinueTexture{}, sideBannerTexture{}, bottomSideBannerTexture{} ,positionInfoTexture{}, scaleTexture{};
    MODE mode = SHORTEST;
    STATUS status = START;

private:
    // maybe vector would be better
    void prepareBackground();

    void prepareBanner();

    void prepareSideBanner();

    void prepareBotttomSideBanner();

    void prepareInfoText();

    void prepareLSR();

    void checkLSR();

    void prepareRSR();

    void checkRSR();

    void prepareLSL();

    void checkLSL();

    void prepareRSL();

    void checkRSL();

    void prepareLongest();

    void checkLongest();

    void prepareSignature();

    void preparePositionInfo();

    void prepareScale();

    void prepareContinue();

    void checkContinue();

    void checkHighlight();


    bool isInBox(sf::Rect<float> test);


public:
    Visualization(sf::RenderWindow &win, const Car &c);

    void drawPath();

    void drawEnvironment();

    void drawAnimEnvironment();

    void highlight();

    MODE getMode() const;

    STATUS getStatus() const;


};


#endif //DUBBINS_CAR_VISUALIZATION_H
