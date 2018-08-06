//
//  Game.hpp
//  2D_GameEngine
//
//  Created by John Wang on 2018/8/5.
//  Copyright © 2018年 catman. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>


class Game{

public:
    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool running();
    
    
private:
    bool isRunning;
    int count=0;
    SDL_Window* window;
    SDL_Renderer* renderer;
    
};


#endif /* Game_hpp */
