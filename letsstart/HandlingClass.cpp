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
#include "Pause_Window.hpp"
#include "Win_window.hpp"
#include "Lose_window.hpp"
#include <iostream>
const int maximum_moves=100,maximum_time=120;

void setfalse ( bool&, bool&, bool&, bool&, bool&, bool&);
int calc_score(int timeleft, int movesleft);

HandlingClass::HandlingClass()
{
    currentlevel=1;
    movementcounter=0;
    score=0;
}
void HandlingClass::Start()
{
    const int XwindowSize=2880, YwindowSize=1800;
    int mytime;
    sf::RenderWindow game_window(sf::VideoMode(), "SFML Window", Style::Fullscreen);
    Main_Window main_window;
    Play_Window play_window;
    Instructions_Window instructions_window;
    Quit_Window quit_window;
    Pause_Window pause_window;
    Win_window win_window;
    Lose_window lose_window;
    main_window.setbuttons(currentlevel);
    main_window.settexture();
    play_window.settexture();
    clk.restart();
    mytime=clk.getElapsedTime().asSeconds();
    play_window.setbuttons(movementcounter, mytime);
    instructions_window.setbuttons();
    instructions_window.settexture();
    quit_window.settexture();
    quit_window.setbuttons();
    pause_window.setbuttons();
    pause_window.settexture();
    win_window.settexture();
    win_window.setbuttons(movementcounter,score);
    lose_window.settexture();
    lose_window.setbuttons(movementcounter);
    bool mw=true,p,i,q,ps,w,l;
    Music music;
    music.openFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/23 After The Fall.wav");
    music.play();
    music.setLoop(true);
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
                    if(w)
                    {
                        if(win_window.Restarttt.detector(event.mouseButton) && event.mouseButton.button==Mouse::Left)
                        {
                            p=true;
                            movementcounter=0;
                            play_window.setlevel(currentlevel);
                            play_window.countmove(0);
                            w=false;
                            clk.restart();
                            mytime=0;
                            play_window.displayclock(mytime);
                            break;
                        }
                        if(win_window.MainWindow.detector(event.mouseButton) && event.mouseButton.button==Mouse::Left)
                        {
                            mw=true;
                            w=false;
                            break;
                        }
                    }
                    if(l)
                    {
                        if(lose_window.Restartttt.detector(event.mouseButton) && event.mouseButton.button==Mouse::Left)
                        {
                            p=true;
                            movementcounter=0;
                            play_window.setlevel(currentlevel);
                            play_window.countmove(0);
                            l=false;
                            clk.restart();
                            mytime=0;
                            play_window.displayclock(mytime);
                            break;
                        }
                        if(lose_window.MainWindoww.detector(event.mouseButton) && event.mouseButton.button==Mouse::Left)
                        {
                            mw=true;
                            l=false;
                            break;
                        }
                    }
                    if(mw)
                    {
                        //play button pressed
                        if(main_window.Play.detector(event.mouseButton) && event.mouseButton.button==Mouse::Left)
                        {
                            movementcounter=0;
                            mytime=0;
                            play_window.countmove(movementcounter);
                            play_window.setlevel(currentlevel);
                            p=true;
                            mw=false;
                            clk.restart();
                            break;
                        }
                        
                        //lower level button pressed
                        if(main_window.Lowerlevel.detector(event.mouseButton) && event.mouseButton.button==Mouse::Left)
                        {
                            if(currentlevel>1 && currentlevel<7)
                            {
                                currentlevel--;
                                main_window.changelevel(currentlevel);
                                break;
                            }
                        }
                        //higher level button pressed
                        if(main_window.Higherlevel.detector(event.mouseButton) && event.mouseButton.button==Mouse::Left)
                        {
                            if(currentlevel>0 && currentlevel<6)
                            {
                                currentlevel++;
                                main_window.changelevel(currentlevel);
                                break;
                            }
                        }
                        //instructions button pressed
                        if(main_window.Instructions.detector(event.mouseButton) && event.mouseButton.button==Mouse::Left)
                        {
                            i=true;
                            mw=false;
                            break;
                        }
                        //quit button pressed
                        if(main_window.Quit.detector(event.mouseButton) && event.mouseButton.button==Mouse::Left)
                        {
                            q=true;
                            mw=false;
                            break;
                        }
                    }
                    if(p)
                    {
                        if(play_window.Restart.detector(event.mouseButton) && event.mouseButton.button==Mouse::Left)
                        {
                            play_window.setlevel(currentlevel);
                            break;
                        }
                        if(play_window.GoBack.detector(event.mouseButton) && event.mouseButton.button==Mouse::Left)
                        {
                            mw=true;
                            p=false;
                            break;
                        }
                        if(play_window.Pause.detector(event.mouseButton) && event.mouseButton.button==Mouse::Left)
                        {
                            ps=true;
                            p=false;
                            break;
                        }
                    }
                    if(q)
                    {
                        if(quit_window.Cancel.detector(event.mouseButton) && event.mouseButton.button==Mouse::Left)
                        {
                            mw=true;
                            q=false;
                            break;
                        }
                        if(quit_window.Exit.detector(event.mouseButton) && event.mouseButton.button==Mouse::Left)
                        {
                            game_window.close();
                            break;
                        }
                    }
                    if(i)
                    {
                        if(instructions_window.Back.detector(event.mouseButton) && event.mouseButton.button==Mouse::Left)
                        {
                            mw=true;
                            i=false;
                            break;
                        }
                    }
                    if(ps)
                    {
                        if(pause_window.EXITT.detector(event.mouseButton) && event.mouseButton.button== Mouse::Left)
                        {
                            game_window.close();
                            break;
                        }
                        if(pause_window.CANCELL.detector(event.mouseButton) && event.mouseButton.button==Mouse::Left)
                        {
                            p=true;
                            ps=false;
                            break;
                        }
                    }
                }
                case Event::KeyPressed:
                {
                    if(mw)
                    {
                        if(event.key.code==Keyboard::Escape)
                        {
                            q=true;
                            mw=false;
                            break;
                        }
                        //enter button pressed
                        //play button highlighted
                        //lower level button highkighted
                        //higher level button highlighted
                        //instruction button highlighted
                        //quit button highlighted
                    }
                    if(p)
                    {
                        if(play_window.checknotwin())
                        {
                            if(event.key.code==Keyboard::Left)
                            {
                                if(play_window.moveplayer(0, -1))
                                {
                                    movementcounter++;
                                    play_window.countmove(movementcounter);
                                    break;
                                }
                            }
                            if(event.key.code==Keyboard::Right)
                            {
                                if(play_window.moveplayer(0, 1))
                                {
                                    movementcounter++;
                                    play_window.countmove(movementcounter);
                                    break;
                                }
                            }
                            if(event.key.code==Keyboard::Down)
                            {
                                if(play_window.moveplayer(1, 0))
                                {
                                    movementcounter++;
                                    play_window.countmove(movementcounter);
                                    break;
                                }
                            }
                            if(event.key.code==Keyboard::Up)
                            {
                                if(play_window.moveplayer(-1, 0))
                                {
                                    movementcounter++;
                                    play_window.countmove(movementcounter);
                                    break;
                                }
                            }
                        }
                        else
                        {
                            if(!play_window.checknotwin())
                            {
                                w=true;
                                p=false;
                                break;
                            }
                        }
                        if(event.key.code==Keyboard::Escape)
                        {
                            q=true;
                            p=false;
                            break;
                        }
                    }
                    if(q)
                    {
                        if(event.key.code==Keyboard::Escape)
                        {
                            game_window.close();
                            break;
                        }
                    }
                }
            }
        }
        if(!play_window.checknotwin() && p)
        {
            w=true;
            p=false;
            win_window.displaymoves(movementcounter);
            score=calc_score(maximum_time-mytime, maximum_moves-movementcounter);
            win_window.displayscore(score);
            mytime=0;
            play_window.displayclock(mytime);
        }
        if(p && (mytime>=maximum_time || movementcounter>=maximum_moves))
        {
            l=true;
            p=false;
            lose_window.displaymoves(movementcounter);
            clk.restart();
            mytime=0;
            play_window.displayclock(mytime);
        }
        if(p && clk.getElapsedTime().asSeconds()>=mytime+1)
           {
               mytime=clk.getElapsedTime().asSeconds();
               play_window.displayclock(mytime);
           }
        // Clear screen
        game_window.clear(Color::White);
        if(mw)
        {
            setfalse(p,i,q, ps,w,l);
            main_window.draw(game_window);
        }
        else
        {
            if(p)
            {
                setfalse(mw,i,q, ps,w,l);
                play_window.draw(game_window);
            }
            else
            {
                if(i)
                {
                    setfalse(mw, p, q, ps,w,l);
                    instructions_window.draw(game_window);
                }
                else
                {
                    if(q)
                    {
                        setfalse(mw, p, i, ps, w,l);
                        quit_window.draw(game_window);
                    }
                    else
                    {
                        if(ps)
                        {
                            setfalse(mw, p, i, q, w,l);
                            pause_window.draw(game_window);
                        }
                        else
                        {
                            if(w)
                            {
                                setfalse(mw, p, i, q, ps,l);
                                win_window.draw(game_window);
                            }
                            else
                            {
                                if(l)
                                {
                                    setfalse(mw, p, i, q, ps,w);
                                    lose_window.draw(game_window);
                                }
                            }
                        }
                    }
                }
            }
        }
        // Update the window
        game_window.display();
    }

}
void setfalse (bool& a, bool& b, bool& c, bool& d, bool& e, bool& f)
{
    a=b=c=d=e=f=false;
}
int calc_score(int timeleft, int movesleft)
{
    int points=0;
    points=timeleft*movesleft*100;
    return points;
}





