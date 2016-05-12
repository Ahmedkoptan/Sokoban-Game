//
//  Lose_window.hpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 5/12/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//

#ifndef Lose_window_hpp
#define Lose_window_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Buttons.hpp"
class Lose_window
{
private:
    Sprite LoseWindowImage;
    Texture LoseWindow_Texture;
    Text movement_counterr;
    Font movementcounterfontt;
public:
    Lose_window();
    void setbuttons(int l);
    void draw(RenderWindow& window);
    void settexture();
    void displaymoves(int l);
    Buttons Restartttt;
    Buttons MainWindoww;
};


#endif /* Lose_window_hpp */
