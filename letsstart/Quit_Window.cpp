//
//  Quit_Window.cpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 5/3/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Quit_Window.hpp"
using namespace sf;
Quit_Window::Quit_Window()
{
    
}
void Quit_Window::setbuttons()
{
    Exit.seteverything((1800/2)+100, (2880/2)-200, 100, 200, Color::White, "Yes","");
    Cancel.seteverything((1800/2)+100, (2880/2)+200, 100, 200, Color::White, "No","");
    if (!Quitfont.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/Times New Roman.ttf")) {
        return EXIT_FAILURE;
    }
    Quit.setString("Are you sure you want to quit?");
    Quit.setFont(Quitfont);
    Quit.setCharacterSize((0.3*200));
    Quit.setOrigin(Quit.getLocalBounds().width / 2, Quit.getLocalBounds().height / 2);
    Quit.setPosition(2880/2,(1800/2)-100);
    Quit.setColor(sf::Color::White);
}
void Quit_Window::settexture()
{
    if (!QuitWindow_Texture.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/BackgroundSkyFinalLook.jpg")) {
        return EXIT_FAILURE;
    }
    QuitWindowImage.setTexture(QuitWindow_Texture);
    QuitWindowImage.setScale(Vector2f (3.f,2.85f));
    QuitWindowImage.setOrigin(QuitWindowImage.getLocalBounds().width/2, QuitWindowImage.getLocalBounds().height/2);
    QuitWindowImage.setPosition(2880/2, 1800/2);
}
void Quit_Window::draw(RenderWindow& window)
{
    window.draw(QuitWindowImage);
    Exit.drawbutton(window);
    Cancel.drawbutton(window);
    window.draw(Quit);
}