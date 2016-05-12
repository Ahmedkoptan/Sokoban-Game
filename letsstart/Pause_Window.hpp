//
//  Pause_Window.hpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 5/12/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//

#ifndef Pause_Window_hpp
#define Pause_Window_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Buttons.hpp"
class Pause_Window
{
private:
    Sprite QuitWindowImage;
    Texture QuitWindow_Texture;
public:
    Pause_Window();
    void setbuttons();
    void draw(RenderWindow& window);
    void settexture();
    Buttons EXITT;
    Buttons CANCELL;
};

#endif /* Pause_Window_hpp */
