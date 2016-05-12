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
    Play.seteverything(200, 850, 100, 200, Color::Blue, "Play","BRICK__.jpg");
    Instructions.seteverything(400, 850, 100, 200, Color::Blue, "Instructions","BRICK__.jpg");
    Quit.seteverything(600, 850, 100, 200, Color::Blue, "Quit","BRICK__.jpg");
    Lowerlevel.seteverything(800, 700, 100, 200, Color::Blue, "", "BRICK__.jpg");
    Higherlevel.seteverything(800, 1000, 100, 200, Color::Blue, "", "BRICK__.jpg");
    if (!displaylevelfont.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/Times New Roman.ttf")) {
        return EXIT_FAILURE;
    }
    displaylevel.setString(std::to_string(l));
    displaylevel.setFont(displaylevelfont);
    displaylevel.setCharacterSize((0.17*200));
    displaylevel.setOrigin(displaylevel.getLocalBounds().width / 2, displaylevel.getLocalBounds().height / 2);
    displaylevel.setPosition(850,800-8);
    displaylevel.setColor(sf::Color::Black);
}
void Main_Window::changelevel(int l)
{
    displaylevel.setString(std::to_string(l));
}
void Main_Window::settexture()
{
    if (!MainWindow_Texture.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/BackgroundSkyFinalLook.jpg")) {
        return EXIT_FAILURE;
    }
    MainWindowImage.setTexture(MainWindow_Texture);
    MainWindowImage.setScale(Vector2f (1.05f,1.6f));
    MainWindowImage.setOrigin(MainWindowImage.getLocalBounds().width/2, MainWindowImage.getLocalBounds().height/2);
    MainWindowImage.setPosition(500, 500);
}
void Main_Window::draw(RenderWindow& window)
{
    window.draw(MainWindowImage);
    window.draw(displaylevel);
    Play.drawbutton(window);
    Instructions.drawbutton(window);
    Quit.drawbutton(window);
    Lowerlevel.drawbutton(window);
    Higherlevel.drawbutton(window);
}