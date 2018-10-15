//
//  Buttons.cpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 4/28/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//

#include "Buttons.hpp"
using namespace sf;
Buttons::Buttons()
{
    Si=0;
    Sj=0;
    Pi=0;
    Pj=0;
}
void Buttons::seteverything(float posi, float posj, float sizei, float sizej, Color c, std::string text, std::string imagename)
{
    Si=sizei;Sj=sizej;Pi=posi;Pj=posj;
    mybutton.setSize(Vector2f (Sj,Si));
    mybutton.setOrigin(Sj/2, Si/2);
    mybutton.setPosition(Pj, Pi);
    mybutton.setFillColor(c);
    if (!font.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/Times New Roman.ttf")) {
        return;
    }
    mytext.setString(text);
    mytext.setFont(font);
    mytext.setCharacterSize((0.0017*Si*Sj));
    mytext.setOrigin(mytext.getLocalBounds().width / 2, mytext.getLocalBounds().height / 2);
    mytext.setPosition(Pj,Pi-8);
    mytext.setColor(sf::Color::Black);
    if(imagename!="")
    {
        if (!Button_Texture.loadFromFile("/Users/ahmedkoptanmacbook/Imp/AUC/Course content/Fall 2015-Summer 2016/Spring 2016/CS 110/NEW/project/letsstart/"+imagename)) {
            return;
        }
        ButtonImage.setTexture(Button_Texture);
        ButtonImage.setScale(Vector2f (0.2f,0.19f));
        ButtonImage.setOrigin(ButtonImage.getLocalBounds().width/2, ButtonImage.getLocalBounds().height/2);
        ButtonImage.setPosition(Pj, Pi);
    }
    mybutton.setOutlineThickness(10);
    mybutton.setOutlineColor(Color::Black);
    
}
bool Buttons::detector(Event::MouseButtonEvent mousebutton)
{
    float x = mousebutton.x;
    float y = mousebutton.y;
    
    if((x<=(Pj+(Sj/2)))&&(x>=(Pj-(Sj/2)))&&(y<=(Pi+(Si/2)))&&(y>=(Pi-(Si/2))))
    {
        return true;
    }
    else
        return false;
}
void Buttons::drawbutton(RenderWindow& window)
{
    window.draw(mybutton);
    window.draw(ButtonImage);
    window.draw(mytext);
}




