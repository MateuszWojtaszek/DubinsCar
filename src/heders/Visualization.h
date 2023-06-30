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
    Pose initPose{0,0,0};
    Pose finalPose{0,0,0};
    double initX=0,finalX=0,initY=0,finalY=0,initAngle=0,finalAngle=0;
    sf::CircleShape probe{3}, initPoseProbe{3}, finalPoseProbe{3};
    sf::View view = {};
    sf::Sprite background = {}, banner{},infoText{}, RSR{}, LSR{}, LSL{}, RSL{}, Longest{},signature{},
    Continue{}, sideBanner{}, bottomSideBanner{}, positionInfo{}, scale{}, scale2{}, grid{}, zipper{}, zipper2{}, animateButton{};

    sf::Texture backgroundTexture{}, bannerTexture{}, infoTextTexture{}, RSRTexture{}, LSRTexture{},
    LSLTexture{}, RSLTexture{}, LongestTexture{},signatureTexture{}, ContinueTexture{}, sideBannerTexture{},
    bottomSideBannerTexture{} ,positionInfoTexture{}, scaleTexture{}, gridTexture{}, zipperTexture{}, animateButtonTexture{};

    MODE mode = SHORTEST;
    STATUS status = START;

private:
    // maybe vector would be better
    void prepareBackground();

    void prepareBanner();

    void prepareSideBanner();

    void prepareBotttomSideBanner();

    void prepareInfoText();

    void prepareGrid();

    void checkGrid();

    void preparePositionProbes();

    void prepareAnimateButton();

    void checkAnimateButton();

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

    void prepareZipper();

    void checkZipper(const sf::Sprite& s);

    void checkZipper2(const sf::Sprite& s);

    void checkFinalPoseAngle();

    void checkInitPoseAngle();

    void setPositions();

    Pose scaleProbes(Pose val);

    bool isInBox(sf::Rect<float> test);


public:
    explicit Visualization(sf::RenderWindow &win);

    void drawPath(const Car &car);

    void drawEnvironment();

    void drawAnimEnvironment();

    void highlight();

    void animate();

    MODE getMode() const;

    STATUS getStatus() const;

    Pose getInitPosition() const;

    Pose getFinalPosition() const;


};


#endif //DUBBINS_CAR_VISUALIZATION_H
