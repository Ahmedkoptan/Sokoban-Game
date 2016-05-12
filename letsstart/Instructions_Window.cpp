//
//  Instructions_Window.cpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 5/3/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Instructions_Window.hpp"
using namespace sf;
Instructions_Window::Instructions_Window()
{
    
}
void Instructions_Window::setbuttons()
{
    Back.seteverything(800, 500, 100, 200, Color::White, "Back","");
}
void Instructions_Window::settexture()
{
    if (!Instructions_Texture.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/BackgroundSkyFinalLook.jpg")) {
        return EXIT_FAILURE;
    }
    InstructionsWindowImage.setTexture(Instructions_Texture);
    InstructionsWindowImage.setScale(Vector2f (1.05f,1.6f));
    InstructionsWindowImage.setOrigin(InstructionsWindowImage.getLocalBounds().width/2, InstructionsWindowImage.getLocalBounds().height/2);
    InstructionsWindowImage.setPosition(500, 500);
}
void Instructions_Window::draw(RenderWindow& window)
{
    window.draw(InstructionsWindowImage);
    Back.drawbutton(window);
}