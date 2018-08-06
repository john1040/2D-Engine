//
//  TextureManager.h
//  2D_GameEngine
//
//  Created by John Wang on 2018/8/6.
//  Copyright © 2018年 catman. All rights reserved.
//
//
//#ifndef TextureManager_h
//#define TextureManager_h
//
//
//#endif /* TextureManager_h */

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
class TextureManager{
public:
    static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* rend);
};
