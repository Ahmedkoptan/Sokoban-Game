//
//  HandlingClass.hpp
//  letsstart
//
//  Created by Ahmed Mostafa Galal Koptan on 5/9/16.
//  Copyright © 2016 Ahmed Mostafa Galal Koptan. All rights reserved.
//

#ifndef HandlingClass_hpp
#define HandlingClass_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Buttons.hpp"
#include "Main_Window.hpp"
#include "Play_Window.hpp"
#include "Quit_Window.hpp"
#include "Instructions_Window.hpp"
class HandlingClass
{
private:
    int currentlevel;
    
    
public:
    HandlingClass();
    void Start();
    
};


#endif /* HandlingClass_hpp */
