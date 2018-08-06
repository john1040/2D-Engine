//
//  GameObject.cpp
//  2D_GameEngine
//
//  Created by John Wang on 2018/8/6.
//  Copyright © 2018年 catman. All rights reserved.
//

#include "GameObject.hpp"
#include "TextureManager.h"
GameObject::GameObject(const char* textureSheet,SDL_Renderer* rend, int x, int y){
    renderer = rend;
    objectTexture = TextureManager::LoadTexture(textureSheet, rend);
    
    xpos = x;
    ypos = y;
    xVel = 0;
    yVel = 0;
    
}
GameObject::~GameObject(){
    
}
void GameObject::update(){
    
    // positions determines the movement of the player
    xpos++;
    //ypos++;
    
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w*2;
    destRect.h = srcRect.h*2;
    
    
}
void GameObject::render(){
    SDL_RenderCopy(renderer, objectTexture, &srcRect, &destRect);
    
}

void GameObject::move(){
    xpos += xVel;
    
    if(xpos < 0 || xpos > SCREEN_WIDTH){
        xpos -= xVel;
    }
}

void GameObject::handleEvent(SDL_Event& e){
    // if a key is pressed:
    if(e.type == SDL_KEYDOWN && e.key.repeat == 0){
        switch (e.key.keysym.sym) {
            case SDLK_LEFT:
                xVel -= VELOCITY;
                break;
            case SDLK_RIGHT:
                xVel += VELOCITY;
                break;
            
        }
    }
}



