//
// Created by mateusz on 27.06.23.
//

#include "../heders/Visualization.h"

Visualization::Visualization(sf::RenderWindow &win, const Car &c) : window(win), car(const_cast<Car &>(c)) {
    probe.setFillColor(sf::Color::Green);
    prepareBackground();
    prepareBanner();
    prepareInfoText();
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
