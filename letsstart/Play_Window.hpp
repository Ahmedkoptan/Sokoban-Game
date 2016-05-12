//
//  Play_Window.hpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 4/29/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//

#ifndef Play_Window_hpp
#define Play_Window_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <fstream>
#include "Buttons.hpp"
class Play_Window
{
private:
    Sprite PlayWindowImage;
    Texture PlayWindow_Texture;
    char** map;
    std::string solution;
    int rows;
    int cols;
    std:: string next;
    Sprite GrassImage;
    Texture Grass_Texture;
    Sprite SpaceImage;
    Texture Space_Texture;
    Sprite PlayerImage;
    Texture Player_Texture;
    Sprite TilesImage;
    Texture Tiles_Texture;
    Sprite BoxImage;
    Texture Box_Texture;
    Sprite MarkImage;
    Texture Mark_Texture;
    int pi;
    int pj;
public:
    Buttons Restart;
    Buttons Pause;
    Buttons GoBack;
    Play_Window();
    void setbuttons();
    void draw(RenderWindow& window);
    void settexture();
    void setlevel(int l);
    void displaymap(RenderWindow& window);
    void draw_space(RenderWindow& window, int i, int j);
    void draw_player(RenderWindow& window, int i, int j);
    void draw_tiles(RenderWindow& window, int i, int j);
    void draw_grass(RenderWindow& window, int i, int j);
    void draw_box(RenderWindow& window, int i, int j);
    void draw_mark(RenderWindow& window, int i, int j);
    void moveplayer(int di, int dj);
    void findplayer();
    bool checknotwin();
    
};

#endif /* Play_Window_hpp */


