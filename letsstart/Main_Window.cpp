//
//  Main_Window.cpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 4/29/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "Main_Window.hpp"
Main_Window::Main_Window()
{
    
}
void Main_Window::setbuttons(int l)
{
    Play.seteverything(400, 2800/2, 100, 200, Color::White, "Play","");
    Instructions.seteverything(600, 2800/2, 100, 200, Color::White, "Instructions","");
    Quit.seteverything(800, 2800/2, 100, 200, Color::White, "Quit","");
    Lowerlevel.seteverything(1400, (2800/2)-200, 100, 200, Color::White, "", "arrow 2.png");
    Higherlevel.seteverything(1400, (2800/2)+200, 100, 200, Color::White, "", "arrow.png");
    if (!displaylevelfont.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/Times New Roman.ttf")) {
        return EXIT_FAILURE;
    }
    displaylevel.setString(std::to_string(l));
    displaylevel.setFont(displaylevelfont);
    displaylevel.setCharacterSize((0.17*200));
    displaylevel.setOrigin(displaylevel.getLocalBounds().width / 2, displaylevel.getLocalBounds().height / 2);
    displaylevel.setPosition(2800/2,1400-8);
    displaylevel.setColor(sf::Color::White);
    if (!Levelfont.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/Times New Roman.ttf")) {
        return EXIT_FAILURE;
    }
    Level.setString("Level");
    Level.setFont(Levelfont);
    Level.setCharacterSize((0.3*200));
    Level.setOrigin(Level.getLocalBounds().width / 2, Level.getLocalBounds().height / 2);
    Level.setPosition(2800/2,1200-8);
    Level.setColor(sf::Color::White);
}
void Main_Window::changelevel(int l)
{
    displaylevel.setString(std::to_string(l));
}
void Main_Window::settexture()
{
    if (!MainWindow_Texture.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/ss-009.jpg")) {
        return EXIT_FAILURE;
    }
    MainWindowImage.setTexture(MainWindow_Texture);
    MainWindowImage.setScale(Vector2f (1.5f,1.7f));
    MainWindowImage.setOrigin(MainWindowImage.getLocalBounds().width/2, MainWindowImage.getLocalBounds().height/2);
    MainWindowImage.setPosition(2880/2, 1800/2);
}
void Main_Window::draw(RenderWindow& window)
{
    window.draw(MainWindowImage);
    Play.drawbutton(window);
    Instructions.drawbutton(window);
    Quit.drawbutton(window);
    Lowerlevel.drawbutton(window);
    Higherlevel.drawbutton(window);
    window.draw(displaylevel);
    window.draw(Level);
    
}