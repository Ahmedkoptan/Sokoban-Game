//
//  Buttons.hpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 4/28/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//

#ifndef Buttons_hpp
#define Buttons_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
class Buttons
{
private:
    RectangleShape mybutton;
    float Si;
    float Sj;
    float Pi;
    float Pj;
    Text mytext;
    Font font;
    Sprite ButtonImage;
    Texture Button_Texture;
public:
    Buttons();
    void seteverything( float posi, float posj, float sizei, float sizej, Color c, std::string text, std::string imagename);
    bool detector();
    //void setcolor&musicchange
    void drawbutton(RenderWindow& window);
};

#endif /* Buttons_hpp */
