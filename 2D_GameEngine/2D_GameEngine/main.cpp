//
//  main.cpp
//  2D_GameEngine
//
//  Created by John Wang on 2018/8/5.
//  Copyright © 2018年 catman. All rights reserved.
//

#include <iostream>
#include "Game.hpp"
int main(int argc, const char * argv[]) {
    
    // we limit the frame rate to 60
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    
    Uint32 frameStart;
    int frameTime;
    
    Game* game = nullptr;
    game = new Game();
    game->init("engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    
    while(game->running()){
        
        frameStart = SDL_GetTicks();
        
        game->handleEvents();
        game->update();
        game->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
        //handle user input
        //update objects
        //render changes to display
    }
    
    game->clean();
    return 0;
}
