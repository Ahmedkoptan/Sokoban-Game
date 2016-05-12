//
//  Main_Window.hpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 4/29/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//

#ifndef Main_Window_hpp
#define Main_Window_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Buttons.hpp"

class Main_Window
{
private:
    Sprite MainWindowImage;
    Texture MainWindow_Texture;
    Text displaylevel;
    Font displaylevelfont;
    Text Level;
    Font Levelfont;
public:
    Buttons Play;
    Buttons Instructions;
    Buttons Quit;
    Buttons Lowerlevel;
    Buttons Higherlevel;
    Main_Window();
    void setbuttons(int l);
    void settexture();
    void changelevel(int l);
    //setmusic
    void draw(RenderWindow&);
};

#endif /* Main_Window_hpp */
