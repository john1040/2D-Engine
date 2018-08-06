//
//  Map.hpp
//  2D_GameEngine
//
//  Created by John Wang on 2018/8/6.
//  Copyright © 2018年 catman. All rights reserved.
//

//#ifndef Map_hpp
//#define Map_hpp
//
//#include <stdio.h>
//
//#endif /* Map_hpp */

#include "Game.hpp"

class Map{
    
public:
    Map();
    ~Map();
    
    void loadMap();
    void drawMap();
    
private:
    
    SDL_Rect srcRect, destRect;
    SDL_Texture* grass, *dirt,*water;
    
    int map[20][25];
    
};
