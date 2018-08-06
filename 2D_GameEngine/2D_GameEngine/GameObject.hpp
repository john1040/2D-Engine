//
//  GameObject.hpp
//  2D_GameEngine
//
//  Created by John Wang on 2018/8/6.
//  Copyright © 2018年 catman. All rights reserved.
//

//#ifndef GameObject_hpp
//#define GameObject_hpp
//
//#include <stdio.h>
//
//#endif /* GameObject_hpp */
#include<SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
class GameObject{
public:
    GameObject(const char* textureSheet,SDL_Renderer* rend,int x,int y);
    ~GameObject();
    void update();
    void render();
    void move();
    void handleEvent(SDL_Event& e);
    
    
private:
    int xpos;
    int ypos;
    int xVel;
    int yVel;
    static const int VELOCITY = 10;
    int SCREEN_WIDTH = 600;
    
    SDL_Texture* objectTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
    
};
