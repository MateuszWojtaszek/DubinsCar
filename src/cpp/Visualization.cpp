//
// Created by mateusz on 27.06.23.
//

#include "../heders/Visualization.h"

Visualization::Visualization(sf::RenderWindow &win, const Car &c) : window(win), car(const_cast<Car &>(c)) {
    probe.setFillColor(sf::Color::Green);
    prepareBackground();
    prepareBanner();
    prepareInfoText();
    prepareLSR();
    prepareRSR();
    prepareLSL();
    prepareRSL();
    prepareLongest();
    prepareSignature();
    prepareContinue();
    prepareSideBanner();
    prepareBotttomSideBanner();
    preparePositionInfo();
    prepareScale();
}


void Visualization::drawPath() {

    for (auto val: car.getFullPath()) {
        probe.setPosition(static_cast<float>(val.getXpose()), static_cast<float>(val.getYpose()));
        window.draw(probe);
    }
}

void Visualization::drawEnvironment() {
    window.draw(background);
    window.draw(infoText);
    window.draw(banner);
    window.draw(LSR);
    window.draw(RSR);
    window.draw(LSL);
    window.draw(RSL);
    window.draw(Longest);
    window.draw(Continue);
    window.draw(signature);
}

void Visualization::prepareBackground() {
    backgroundTexture.loadFromFile("/home/mateusz/CLionProjects/Dubbins_Car/DubinsCar/src/textures/background.jpg");
    background.setTexture(backgroundTexture);
}

void Visualization::prepareBanner() {
    bannerTexture.loadFromFile("/home/mateusz/CLionProjects/Dubbins_Car/DubinsCar/src/textures/banner.png");
    banner.setTexture(bannerTexture);
    banner.setPosition(static_cast<float>(window.getSize().x)/4.f,0);
}

void Visualization::prepareInfoText() {
    infoTextTexture.loadFromFile("/home/mateusz/CLionProjects/Dubbins_Car/DubinsCar/src/textures/infoText.png");
    infoText.setTexture(infoTextTexture);
    infoText.setPosition(static_cast<float>(window.getSize().x)/7.f,static_cast<float>(window.getSize().y)/7.f);
}

void Visualization::prepareLSR() {
    LSRTexture.loadFromFile("/home/mateusz/CLionProjects/Dubbins_Car/DubinsCar/src/textures/LSR.png");
    LSR.setTexture(LSRTexture);
    LSR.setPosition(static_cast<float>(window.getSize().x)/7.f,static_cast<float>(window.getSize().y)/3.f);
}

void Visualization::highlight() {
    checkLSR();
    checkRSR();
    checkLSL();
    checkRSL();
    checkLongest();
    checkHighlight();
    checkContinue();
}

void Visualization::prepareRSR() {
    RSRTexture.loadFromFile("/home/mateusz/CLionProjects/Dubbins_Car/DubinsCar/src/textures/RSR.png");
    RSR.setTexture(RSRTexture);
    RSR.setPosition(static_cast<float>(window.getSize().x)/5.f + 50,static_cast<float>(window.getSize().y)/3.f);
}

bool Visualization::isInBox(sf::Rect<float> test) {
    if(test.contains(static_cast<float>(sf::Mouse::getPosition(window).x),
                     static_cast<float>(sf::Mouse::getPosition(window).y))) return true;
    return false;
}

void Visualization::checkLSR() {
    if(isInBox(LSR.getGlobalBounds())){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            LSR.setColor(sf::Color::Magenta);
            mode = JUST_LSR;
        }
    }
    else{
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isInBox(Continue.getGlobalBounds()))
            LSR.setColor(sf::Color::White);
    }
}

void Visualization::checkRSR() {
    if(isInBox(RSR.getGlobalBounds())){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            RSR.setColor(sf::Color::Magenta);
            mode = JUST_RSR;
        }
    }
    else{
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isInBox(Continue.getGlobalBounds()))
            RSR.setColor(sf::Color::White);
    }
}

void Visualization::prepareLSL() {
    LSLTexture.loadFromFile("/home/mateusz/CLionProjects/Dubbins_Car/DubinsCar/src/textures/LSL.png");
    LSL.setTexture(LSLTexture);
    LSL.setPosition(static_cast<float>(window.getSize().x)/3.f,static_cast<float>(window.getSize().y)/3.f);
}

void Visualization::checkLSL() {
    if(isInBox(LSL.getGlobalBounds())){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            LSL.setColor(sf::Color::Magenta);
            mode = JUST_LSL;
        }
    }
    else{
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left ) && !isInBox(Continue.getGlobalBounds()))
            LSL.setColor(sf::Color::White);
    }
}

void Visualization::prepareRSL() {
    RSLTexture.loadFromFile("/home/mateusz/CLionProjects/Dubbins_Car/DubinsCar/src/textures/RSL.png");
    RSL.setTexture(RSLTexture);
    RSL.setPosition(static_cast<float>(window.getSize().x)/2.f - 100,static_cast<float>(window.getSize().y)/3.f);
}

void Visualization::checkRSL() {
    if(isInBox(RSL.getGlobalBounds())){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            RSL.setColor(sf::Color::Magenta);
            mode = JUST_RSL;
        }
    }
    else{
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isInBox(Continue.getGlobalBounds())) {
            RSL.setColor(sf::Color::White);
        }
    }
}

MODE Visualization::getMode() const {
    return mode;
}

void Visualization::prepareLongest() {
    LongestTexture.loadFromFile("/home/mateusz/CLionProjects/Dubbins_Car/DubinsCar/src/textures/Longest.png");
    Longest.setTexture(LongestTexture);
    Longest.setPosition(static_cast<float>(window.getSize().x)/7.f,static_cast<float>(window.getSize().y)/2.f);
}

void Visualization::checkLongest() {
    if(isInBox(Longest.getGlobalBounds())){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            Longest.setColor(sf::Color::Magenta);
            mode = LONGEST;
        }
    }
    else{
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isInBox(Continue.getGlobalBounds())) {
            Longest.setColor(sf::Color::White);
        }
    }
}

void Visualization::prepareContinue() {
    ContinueTexture.loadFromFile("/home/mateusz/CLionProjects/Dubbins_Car/DubinsCar/src/textures/Continue.png");
    Continue.setTexture(ContinueTexture);
    Continue.setPosition(static_cast<float>(window.getSize().x)/static_cast<float>(1.5),static_cast<float>(window.getSize().y)/static_cast<float>(1.5));
}

void Visualization::checkContinue() {
    if(isInBox(Continue.getGlobalBounds())) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) status = PLANNING;
    }
}

void Visualization::checkHighlight() {
    if ((Longest.getColor()==LSL.getColor()) && (LSR.getColor()==RSL.getColor()) && RSR.getColor() != sf::Color::Magenta) mode = SHORTEST;
}

STATUS Visualization::getStatus() const {
    return status;
}

void Visualization::prepareSideBanner() {
    sideBannerTexture.loadFromFile("/home/mateusz/CLionProjects/Dubbins_Car/DubinsCar/src/textures/side_banner.jpg");
    sideBanner.setTexture(sideBannerTexture);
    sideBanner.setPosition(0,0);
}

void Visualization::drawAnimEnvironment() {
    sf::Sprite tmp_sideBanner = sf::Sprite(sideBanner);
    sf::Sprite tmp_bottomSideBanner = sf::Sprite(bottomSideBanner);
    window.draw(sideBanner);
    window.draw(bottomSideBanner);
    tmp_sideBanner.setPosition(static_cast<float>(window.getSize().x) - sideBanner.getLocalBounds().width, 0);
    tmp_bottomSideBanner.setPosition(sideBanner.getGlobalBounds().width,sideBanner.getGlobalBounds().height-bottomSideBanner.getGlobalBounds().height);
    window.draw(tmp_sideBanner);
    window.draw(tmp_bottomSideBanner);
    window.draw(positionInfo);
    window.draw(scale);

}

void Visualization::prepareBotttomSideBanner() {
    bottomSideBannerTexture.loadFromFile("/home/mateusz/CLionProjects/Dubbins_Car/DubinsCar/src/textures/bottomSideBanner.jpg");
    bottomSideBanner.setTexture(bottomSideBannerTexture);
    bottomSideBanner.setPosition(sideBanner.getGlobalBounds().width,0);
}

void Visualization::prepareSignature() {
    signatureTexture.loadFromFile("/home/mateusz/CLionProjects/Dubbins_Car/DubinsCar/src/textures/signature.png");
    signature.setTexture(signatureTexture);
    signature.setPosition(static_cast<float>(window.getSize().x) / 2.f, static_cast<float>(window.getSize().y) / 2.f);
}

void Visualization::preparePositionInfo() {
    positionInfoTexture.loadFromFile("/home/mateusz/CLionProjects/Dubbins_Car/DubinsCar/src/textures/positionInfo.png");
    positionInfo.setTexture(positionInfoTexture);
    positionInfo.setPosition(sideBanner.getGlobalBounds().width+10,20);
}

void Visualization::prepareScale() {
    scaleTexture.loadFromFile("/home/mateusz/CLionProjects/Dubbins_Car/DubinsCar/src/textures/scale.png");
    scale.setTexture(scaleTexture);
    scale.setPosition(sideBanner.getGlobalBounds().width+10,sideBanner.getGlobalBounds().height-50);
}

