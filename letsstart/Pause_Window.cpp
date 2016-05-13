//
//  Pause_Window.cpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 5/12/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//

#include "Pause_Window.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
Pause_Window::Pause_Window()
{
    
}
void Pause_Window::setbuttons()
{
    EXITT.seteverything((1800/2)+100, (2880/2)-200, 100, 200, Color::White, "Exit","");
    CANCELL.seteverything((1800/2)+100, (2880/2)+200, 100, 200, Color::White, "Return","");
    if (!Pauseefont.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/Times New Roman.ttf")) {
        return EXIT_FAILURE;
    }
    Pausee.setString("Paused");
    Pausee.setFont(Pauseefont);
    Pausee.setCharacterSize((0.3*200));
    Pausee.setOrigin(Pausee.getLocalBounds().width / 2, Pausee.getLocalBounds().height / 2);
    Pausee.setPosition(2880/2,(1800/2)-100);
    Pausee.setColor(sf::Color::White);
}
void Pause_Window::settexture()
{
    if (!QuitWindow_Texture.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/BackgroundSkyFinalLook.jpg")) {
        return EXIT_FAILURE;
    }
    QuitWindowImage.setTexture(QuitWindow_Texture);
    QuitWindowImage.setScale(Vector2f (3.f,2.85f));
    QuitWindowImage.setOrigin(QuitWindowImage.getLocalBounds().width/2, QuitWindowImage.getLocalBounds().height/2);
    QuitWindowImage.setPosition(2800/2, 1800/2);
}
void Pause_Window::draw(RenderWindow& window)
{
    window.draw(QuitWindowImage);
    EXITT.drawbutton(window);
    CANCELL.drawbutton(window);
}