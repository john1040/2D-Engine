//
//  TextureManager.cpp
//  2D_GameEngine
//
//  Created by John Wang on 2018/8/6.
//  Copyright © 2018年 catman. All rights reserved.
//

#include <stdio.h>
#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture,SDL_Renderer* rend){
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* text = SDL_CreateTextureFromSurface(rend, tempSurface);
    SDL_FreeSurface(tempSurface);
    
    return text;
}
