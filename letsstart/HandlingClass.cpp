//
//  HandlingClass.cpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 5/9/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//

#include "HandlingClass.hpp"
#include "ResourcePath.hpp"
#include "Buttons.hpp"
#include "Main_Window.hpp"
#include "Play_Window.hpp"
#include "Quit_Window.hpp"
#include "Instructions_Window.hpp"
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
void setfalse ( bool&, bool&, bool&);


HandlingClass::HandlingClass()
{
    currentlevel=1;
}
void HandlingClass::Start()
{
    const int XwindowSize=2300, YwindowSize=1500;
    sf::RenderWindow game_window(sf::VideoMode(XwindowSize, YwindowSize), "SFML Window");
    Main_Window main_window;
    Play_Window play_window;
    Instructions_Window instructions_window;
    Quit_Window quit_window;
    main_window.setbuttons(currentlevel);
    main_window.settexture();
    play_window.settexture();
    play_window.setbuttons();
    play_window.setlevel(currentlevel);
    instructions_window.setbuttons();
    instructions_window.settexture();
    quit_window.settexture();
    quit_window.setbuttons();
    bool mw=true,p,i,q;
    while (game_window.isOpen())
    {
        // Process events
        sf::Event event;
        while (game_window.pollEvent(event))
        {
            switch (event.type)
            {
                case Event::Closed:
                {
                    game_window.close();
                    break;
                }
                case Event::MouseButtonPressed:
                {
                    if(mw)
                    {
                        //play button pressed
                        if(main_window.Play.detector() && event.mouseButton.button==Mouse::Left)
                        {
                            play_window.setlevel(currentlevel);
                            p=true;
                            mw=false;
                        }
                        //play button highlighted
                        
                        //lower level button pressed
                        if(main_window.Lowerlevel.detector() && event.mouseButton.button==Mouse::Left)
                        {
                            if(currentlevel>1 && currentlevel<6)
                            {
                                currentlevel--;
                            }
                        }
                        //lower level button highkighted
                        
                        //higher level button pressed
                        if(main_window.Higherlevel.detector() && event.mouseButton.button==Mouse::Left)
                        {
                            if(currentlevel>0 && currentlevel<5)
                            {
                                currentlevel++;
                            }
                        }
                        //higher level button highlighted
                        
                        //instructions button pressed
                        if(main_window.Instructions.detector() && event.mouseButton.button==Mouse::Left)
                        {
                            i=true;
                            mw=false;
                        }
                        //instruction button highlighted
                        
                        //quit button pressed
                        if(main_window.Quit.detector() && event.mouseButton.button==Mouse::Left)
                        {
                            q=true;
                            mw=false;
                        }
                        //quit button highlighted
                        
                    }
                    if(q)
                    {
                        if(event.key.code==Keyboard::Escape)
                        {
                            game_window.close();
                            break;
                        }
                        //exit button pressed
                        //cancel button pressed
                    }
                    if(p)
                    {
                        if(play_window.checknotwin())
                        {
                            if(event.key.code==Keyboard::Left)
                            {
                                play_window.moveplayer(0, -1);
                                break;
                            }
                            if(event.key.code==Keyboard::Right)
                            {
                                play_window.moveplayer(0, 1);
                                break;
                            }
                            if(event.key.code==Keyboard::Down)
                            {
                                play_window.moveplayer(1, 0);
                                break;
                            }
                            if(event.key.code==Keyboard::Up)
                            {
                                play_window.moveplayer(-1, 0);
                                break;
                            }
                            if(event.key.code==Keyboard::Escape)
                            {
                                q=true;
                                p=false;
                                break;
                            }
                        }
                        else
                        {
                            //display win
                        }
                    }
                    if(i)
                    {
                        //back button pressed
                    }
                }
            }
            
        }
        // Clear screen
        game_window.clear(Color::White);
        if(mw)
        {
            setfalse(p,i,q);
            main_window.draw(game_window);
        }
        else
        {
            if(p)
            {
                setfalse(mw,i,q);
                play_window.draw(game_window);
            }
            else
            {
                if(i)
                {
                    setfalse(mw, p, q);
                    instructions_window.draw(game_window);
                }
                else
                {
                    if(q)
                    {
                        setfalse(mw, p, i);
                        quit_window.draw(game_window);
                    }
                }
            }
        }
        // Update the window
        game_window.display();
        
    }

}

void setfalse (bool& a, bool& b, bool& c)
{
    a=b=c=false;
}


/*
 
 
 
 Play_Menu.draw(main_window);
 
 
 
*/