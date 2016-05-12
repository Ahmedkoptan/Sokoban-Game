//
//  Quit_Window.hpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 5/3/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//

#ifndef Quit_Window_hpp
#define Quit_Window_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Buttons.hpp"
class Quit_Window
{
private:
    Sprite QuitWindowImage;
    Texture QuitWindow_Texture;
public:
    Quit_Window();
    void setbuttons();
    void draw(RenderWindow& window);
    void settexture();
    Buttons Exit;
    Buttons Cancel;
};

#endif /* Quit_Window_hpp */
