//
//  Instructions_Window.hpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 5/3/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//

#ifndef Instructions_Window_hpp
#define Instructions_Window_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Buttons.hpp"
class Instructions_Window
{
private:
    Sprite InstructionsWindowImage;
    Texture Instructions_Texture;
public:
    Instructions_Window();
    void setbuttons();
    void settexture();
    void draw(RenderWindow& window);
    Buttons Back;
};

#endif /* Instructions_Window_hpp */
