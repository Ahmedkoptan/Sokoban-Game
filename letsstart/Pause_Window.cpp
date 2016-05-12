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
    EXITT.seteverything(500, 300, 100, 200, Color::White, "Exit","");
    CANCELL.seteverything(500, 700, 100, 200, Color::White, "Cancel","");
}
void Pause_Window::settexture()
{
    if (!QuitWindow_Texture.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/BackgroundSkyFinalLook.jpg")) {
        return EXIT_FAILURE;
    }
    QuitWindowImage.setTexture(QuitWindow_Texture);
    QuitWindowImage.setScale(Vector2f (1.05f,1.6f));
    QuitWindowImage.setOrigin(QuitWindowImage.getLocalBounds().width/2, QuitWindowImage.getLocalBounds().height/2);
    QuitWindowImage.setPosition(500, 500);
}
void Pause_Window::draw(RenderWindow& window)
{
    window.draw(QuitWindowImage);
    EXITT.drawbutton(window);
    CANCELL.drawbutton(window);
}