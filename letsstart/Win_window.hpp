//
//  Win_window.hpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 5/12/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//

#ifndef Win_window_hpp
#define Win_window_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Buttons.hpp"
class Win_window
{
private:
    Sprite WinWindowImage;
    Texture WinWindow_Texture;
    Text movement_counterr;
    Font movementcounterfontt;
    Text Score;
    Font ScoreFont;
    Text Movesmade;
    Font Movesmadefont;
    Text Scoremade;
    Font Scoremadefont;
public:
    Win_window();
    void setbuttons(int l, int x);
    void draw(RenderWindow& window);
    void settexture();
    void displaymoves(int l);
    void displayscore(int x);
    Buttons Restarttt;
    Buttons MainWindow;
};

#endif /* Win_window_hpp */
