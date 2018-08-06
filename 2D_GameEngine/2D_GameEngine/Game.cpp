//
//  Game.cpp
//  2D_GameEngine
//
//  Created by John Wang on 2018/8/5.
//  Copyright © 2018年 catman. All rights reserved.
//


#include<SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include<iostream>
#include "Game.hpp"
#include "TextureManager.h"
#include "GameObject.hpp"

using namespace std;

SDL_Texture* playerTex;
SDL_Rect srcR, destR;

GameObject* player;


//static SDL_Renderer* renderer;


Game::Game(){
    
}
Game::~Game(){
    
}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        cout<<"subsystems initialized"<< endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window){
            cout<<"window created"<<endl;
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout<<"renderer created"<<endl;
        }
        
        isRunning = true;
    }
    else{
        isRunning = false;
    }
//    SDL_Surface* tempSurface = IMG_Load("man.png");
//    playerTex = SDL_CreateTextureFromSurface(renderer, tempSurface);
//    SDL_FreeSurface(tempSurface);
    //playerTex = TextureManager::LoadTexture("man.png", renderer);
    player = new GameObject("man.png",renderer,0,500);
    
    
    
}
void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
            
        default:
            break;
    }
}
void Game::update(){
//    count++;
//    destR.h = 32;
//    destR.w = 32;
//    destR.x = count;
//    cout<<count<<endl;
    player->update();
}
void Game::render(){
    SDL_RenderClear(renderer);
    //SDL_RenderCopy(renderer, playerTex, nullptr, &destR);
    player->render();
    SDL_RenderPresent(renderer);
    
}
void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout<<"cleaned"<<endl;
}

bool Game::running(){
    return isRunning;
}
