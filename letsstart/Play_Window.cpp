//
//  Play_Window.cpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 4/29/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Play_Window.hpp"
#include <iostream>
using namespace sf;
Play_Window::Play_Window()
{
    rows=0;
    cols=0;
    pi=0;
    pj=0;
}
void Play_Window::setbuttons()
{
    Pause.seteverything(200, 150, 100, 200, Color::White, "","pause_button.jpg");
    Restart.seteverything(400, 150, 100, 200, Color::White, "","restart.jpg");
    GoBack.seteverything(300, 150, 100, 200, Color::White, "Back", "restart.jpg");
}
void Play_Window::settexture()
{
    if (!PlayWindow_Texture.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/BackgroundSkyFinalLook.jpg")) {
        return EXIT_FAILURE;
    }
    PlayWindowImage.setTexture(PlayWindow_Texture);
    PlayWindowImage.setScale(Vector2f (1.05f,1.6f));
    PlayWindowImage.setOrigin(PlayWindowImage.getLocalBounds().width/2, PlayWindowImage.getLocalBounds().height/2);
    PlayWindowImage.setPosition(500, 500);
    
    if (!Grass_Texture.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/grass.png")) {
        return EXIT_FAILURE;
    }
    GrassImage.setTexture(Grass_Texture);
    GrassImage.setScale(Vector2f (0.4f,0.4f));
    
    if (!Box_Texture.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/box.png")) {
        return EXIT_FAILURE;
    }
    BoxImage.setTexture(Box_Texture);
    BoxImage.setScale(Vector2f (0.2f,0.2f));
    
    if (!Tiles_Texture.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/brick.png")) {
        return EXIT_FAILURE;
    }
    TilesImage.setTexture(Tiles_Texture);
    TilesImage.setScale(Vector2f (0.34f,0.34f));
    
    if (!Player_Texture.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/player_sprite_by_brubee2k.png")) {
        return EXIT_FAILURE;
    }
    PlayerImage.setTexture(Player_Texture);
    PlayerImage.setScale(Vector2f (1.f,1.f));
}





void Play_Window::setlevel(int l)
{
    std::ifstream myinput,myinput2,myinput3;
    myinput.open("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/Level"+std::to_string(l)+".txt");
    if(myinput.fail())
    {
        std::cout<<"Error in 1"<<std::endl;
        exit(1);
    }
    else
    {
        getline(myinput,next);
        while(next!="Solution:\r")
        {
            rows++;
            getline(myinput,next);
        }
        myinput.close();
        myinput2.open("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/Level"+std::to_string(l)+".txt");
        if(myinput2.fail())
        {
            std::cout<<"Error in 2"<<std::endl;
            exit(1);
        }
        else
        {
            getline(myinput2,next);
            cols=next.length()-1;
            map=new char*[rows];
            for(int i=0; i<rows;i++)
            {
                map[i]=new char[next.length()-1];
                getline(myinput2,next);
            }
            myinput2.close();
            myinput3.open("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/Level"+std::to_string(l)+".txt");
            if(myinput3.fail())
            {
                std::cout<<"Error in 3"<<std::endl;
                exit(1);
            }
            else
            {
                getline(myinput3,next);
                for(int i=0;i<rows;i++)
                {
                    for(int j=0;j<next.length()-1;j++)
                    {
                        map[i][j]=next.at(j);
                    }
                    getline(myinput3,next);
                }
                myinput3.close();
            }
        }
    }
}






void Play_Window::displaymap(RenderWindow& window)
{
     for (int i = 0; i < rows; i++)
     {
         for (int j = 0; j < cols; j++)
         {
             if (map[i][j] == ' ')
                 draw_space(window, i, j);
             
             if (map[i][j] == 'p' ||  map[i][j] =='P')
                 draw_player(window, i, j);
             
             if (map[i][j] == '#')
                 draw_tiles(window, i, j);
             
             if (map[i][j] == '.')
                 draw_grass(window, i, j);
             
             if (map[i][j] == 'b' ||  map[i][j] =='B')
                 draw_box(window, i, j);
             
             if (map[i][j] == 'm')
                 draw_mark(window, i, j);
         }
     }
}
void Play_Window::draw_space(RenderWindow& window, int i, int j)
{
    sf::RectangleShape rectangle_white;
    rectangle_white.setSize(sf::Vector2f(100, 100));
    rectangle_white.setFillColor(sf::Color::Transparent);
    rectangle_white.setPosition(1000+j * 100, i * 100);
    window.draw(rectangle_white);
}
void Play_Window::draw_player(RenderWindow& window, int i, int j)
{
    PlayerImage.setPosition(1000+j * 100, i * 100);
    GrassImage.setPosition(1000+j * 100, i * 100);
    window.draw(GrassImage);
    window.draw(PlayerImage);
}
void Play_Window::draw_tiles(RenderWindow& window, int i, int j)
{
    TilesImage.setPosition(1000+j * 100, i * 100);
    window.draw(TilesImage);
}
void Play_Window::draw_grass(RenderWindow& window, int i, int j)
{
    GrassImage.setPosition(1000+j * 100, i * 100);
    window.draw(GrassImage);
}
void Play_Window::draw_box(RenderWindow& window, int i, int j)
{
    BoxImage.setPosition(1000+j * 100, i * 100);
    window.draw(BoxImage);
}
void Play_Window::draw_mark(RenderWindow& window, int i, int j)
{
    sf::CircleShape circle(25);
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(1000+j * 100 + 25, i * 100 + 25);
    GrassImage.setPosition(1000+j * 100, i * 100);
    window.draw(GrassImage);
    window.draw(circle);
}
void Play_Window::findplayer()
{
    int q=0,u=0;
    bool flag=false;
    while(q<rows && !flag)
    {
        u=0;
        while(u<cols && !flag)
        {
            if(map[q][u]=='p' || map[q][u]=='P')
            {
                flag=true;
                q--;
            }
            else
            {
                u++;
            }
        }
        q++;
    }
    pi=q;
    pj=u;
}
void Play_Window::moveplayer(int di, int dj)
{
    findplayer();
    if (map[pi][pj] == 'p')
    {
        if (map[pi + di][pj + dj] == '.')
        {
            map[pi][pj] = '.';
            map[pi + di][pj + dj] = 'p';
            return;
        }
        
        if (map[pi + di][pj + dj] == 'm')
        {
            map[pi][pj] = '.';
            map[pi + di][pj + dj] = 'P';
            return;
        }
        
        if (map[pi + di][pj + dj] == 'b' && map[pi + di + di][pj + dj + dj] == '.')
        {
            map[pi][pj] = '.';
            map[pi + di][pj + dj] = 'p';
            map[pi + di + di][pj + dj + dj] = 'b';
            return;
        }
        
        if (map[pi + di][pj + dj] == 'b' && map[pi + di + di][pj + dj + dj] == 'm')
        {
            map[pi][pj] = '.';
            map[pi + di][pj + dj] = 'p';
            map[pi + di + di][pj + dj + dj] = 'B';
            return;
        }
        
        if (map[pi + di][pj + dj] == 'B' && map[pi + di + di][pj + dj + dj] == '.')
        {
            map[pi][pj] = '.';
            map[pi + di][pj + dj] = 'P';
            map[pi + di + di][pj + dj + dj] = 'b';
            return;
        }
        
        if (map[pi + di][pj + dj] == 'B' && map[pi + di + di][pj + dj + dj] == 'm')
        {
            map[pi][pj] = '.';
            map[pi + di][pj + dj] = 'P';
            map[pi + di + di][pj + dj + dj] = 'B';
            return;
        }
        
    }
    
    if (map[pi][pj] == 'P')
    {
        if (map[pi + di][pj + dj] == '.')
        {
            map[pi][pj] = 'm';
            map[pi + di][pj + dj] = 'p';
            return;
        }
        
        if (map[pi + di][pj + dj] == 'm')
        {
            map[pi][pj] = 'm';
            map[pi + di][pj + dj] = 'P';
            return;
        }
        
        if (map[pi + di][pj + dj] == 'b' && map[pi + di + di][pj + dj + dj] == '.')
        {
            map[pi][pj] = 'm';
            map[pi + di][pj + dj] = 'p';
            map[pi + di + di][pj + dj + dj] = 'b';
            return;
        }
        
        if (map[pi + di][pj + dj] == 'b' && map[pi + di + di][pj + dj + dj] == 'm')
        {
            map[pi][pj] = 'm';
            map[pi + di][pj + dj] = 'p';
            map[pi + di + di][pj + dj + dj] = 'B';
            return;
        }
        
        if (map[pi + di][pj + dj] == 'B' && map[pi + di + di][pj + dj + dj] == '.')
        {
            map[pi][pj] = 'm';
            map[pi + di][pj + dj] = 'P';
            map[pi + di + di][pj + dj + dj] = 'b';
            return;
        }
        
        if (map[pi + di][pj + dj] == 'B' && map[pi + di + di][pj + dj + dj] == 'm')
        {
            map[pi][pj] = 'm';
            map[pi + di][pj + dj] = 'P';
            map[pi + di + di][pj + dj + dj] = 'B';
            return;
        }
    }
}
bool Play_Window::checknotwin()
{
    int i=0, j=0;
    bool flag=false;
    while(i<rows && !flag)
    {
        j=0;
        while(j<cols && !flag)
        {
            if(map[i][j]=='m')
            {
                flag=true;
            }
            else
            {
                j++;
            }
        }
        i++;
    }
    return flag;
}
void Play_Window::draw(RenderWindow& window)
{
    window.draw(PlayWindowImage);
    Pause.drawbutton(window);
    Restart.drawbutton(window);
    displaymap(window);
}
/*Play_Window::~Play_Window()
{
    for(int i=0; i<rows;i++)
    {
        delete [] *(map+i);
    }
    delete [] map;
}
*/




/*
 void swap(int A[][colm], int i, int j, int di, int dj)
 {
 
	
 }
*/
