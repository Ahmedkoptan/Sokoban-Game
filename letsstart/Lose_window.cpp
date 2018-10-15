//
//  Lose_window.cpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 5/12/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//

#include "Lose_window.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
Lose_window::Lose_window()
{
    
}
void Lose_window::setbuttons(int movement_counterrr)
{
    Restartttt.seteverything(500, 300, 100, 200, Color::White, "","restart.jpg");
    MainWindoww.seteverything(500, 700, 100, 200, Color::White, "Main Window","");
    if (!movementcounterfontt.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/Times New Roman.ttf")) {
        return;
    }
    movement_counterr.setString(std::to_string(movement_counterrr));
    movement_counterr.setFont(movementcounterfontt);
    movement_counterr.setCharacterSize((0.17*200));
    movement_counterr.setOrigin(movement_counterr.getLocalBounds().width / 2, movement_counterr.getLocalBounds().height / 2);
    movement_counterr.setPosition(850,800-8);
    movement_counterr.setColor(sf::Color::White);
}
void Lose_window::settexture()
{
    if (!LoseWindow_Texture.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/ha-ha-you-lose.png")) {
        return;
    }
    LoseWindowImage.setTexture(LoseWindow_Texture);
    LoseWindowImage.setScale(Vector2f (2.f,1.6f));
    LoseWindowImage.setOrigin(LoseWindowImage.getLocalBounds().width/2, LoseWindowImage.getLocalBounds().height/2);
    LoseWindowImage.setPosition(2880/2, 1800/2);
    
}
void Lose_window::displaymoves(int l)
{
    movement_counterr.setString(std::to_string(l));
}
void Lose_window::draw(RenderWindow& window)
{
    window.draw(LoseWindowImage);
    Restartttt.drawbutton(window);
    MainWindoww.drawbutton(window);
}
