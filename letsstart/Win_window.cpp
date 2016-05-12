//
//  Win_window.cpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 5/12/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//

#include "Win_window.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
Win_window::Win_window()
{
    
}
void Win_window::setbuttons(int movement_counterrr, int myscore)
{
    Restarttt.seteverything(200, 150, 100, 200, Color::White, "","restart.jpg");
    MainWindow.seteverything(400, 150, 100, 200, Color::White, "Main Window","");
    if (!movementcounterfontt.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/Times New Roman.ttf")) {
        return EXIT_FAILURE;
    }
    movement_counterr.setString(std::to_string(movement_counterrr));
    movement_counterr.setFont(movementcounterfontt);
    movement_counterr.setCharacterSize((0.17*200));
    movement_counterr.setOrigin(movement_counterr.getLocalBounds().width / 2, movement_counterr.getLocalBounds().height / 2);
    movement_counterr.setPosition(350,850-8);
    movement_counterr.setColor(sf::Color::White);
    if (!ScoreFont.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/Times New Roman.ttf")) {
        return EXIT_FAILURE;
    }
    Score.setString(std::to_string(myscore));
    Score.setFont(ScoreFont);
    Score.setCharacterSize((0.17*200));
    Score.setOrigin(Score.getLocalBounds().width / 2, Score.getLocalBounds().height / 2);
    Score.setPosition(350,1000-8);
    Score.setColor(sf::Color::White);
    if (!Movesmadefont.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/Times New Roman.ttf")) {
        return EXIT_FAILURE;
    }
    Movesmade.setString("Moves");
    Movesmade.setFont(Movesmadefont);
    Movesmade.setCharacterSize((0.3*200));
    Movesmade.setOrigin(Movesmade.getLocalBounds().width / 2, Movesmade.getLocalBounds().height / 2);
    Movesmade.setPosition(150,830-8);
    Movesmade.setColor(sf::Color::White);
    if (!ScoreFont.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/Times New Roman.ttf")) {
        return EXIT_FAILURE;
    }
    Scoremade.setString("Score");
    Scoremade.setFont(ScoreFont);
    Scoremade.setCharacterSize((0.3*200));
    Scoremade.setOrigin(Scoremade.getLocalBounds().width / 2, Scoremade.getLocalBounds().height / 2);
    Scoremade.setPosition(150,985-8);
    Scoremade.setColor(sf::Color::White);
}
void Win_window::settexture()
{
    if (!WinWindow_Texture.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/win.jpg")) {
        return EXIT_FAILURE;
    }
    WinWindowImage.setTexture(WinWindow_Texture);
    WinWindowImage.setScale(Vector2f (3.f,2.4f));
    WinWindowImage.setOrigin(WinWindowImage.getLocalBounds().width/2, WinWindowImage.getLocalBounds().height/2);
    WinWindowImage.setPosition(2880/2, 1800/2);
    
}
void Win_window::displaymoves(int l)
{
    movement_counterr.setString(std::to_string(l));
}
void Win_window::displayscore(int x)
{
    Score.setString(std::to_string(x));
}
void Win_window::draw(RenderWindow& window)
{
    window.draw(WinWindowImage);
    Restarttt.drawbutton(window);
    MainWindow.drawbutton(window);
    window.draw(movement_counterr);
    window.draw(Score);
    window.draw(Movesmade);
    window.draw(Scoremade);
}