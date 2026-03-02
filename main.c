
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "main.h"
#include "pickpuzle.h"


int digits[10][7][5] = {
    // 0
    {{0,0,0,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0}},

    // 1
    {{0,0,0,0,0},
     {0,0,1,0,0},
     {0,1,1,0,0},
     {0,0,1,0,0},
     {0,0,1,0,0},
     {0,1,1,1,0},
     {0,0,0,0,0}},

    // 2
    {{0,0,0,0,0},
     {0,1,1,1,0},
     {0,0,0,1,0},
     {0,1,1,1,0},
     {0,1,0,0,0},
     {0,1,1,1,0},
     {0,0,0,0,0}},

    // 3
    {{0,0,0,0,0},
     {0,1,1,1,0},
     {0,0,0,1,0},
     {0,1,1,1,0},
     {0,0,0,1,0},
     {0,1,1,1,0},
     {0,0,0,0,0}},

    // 4
    {{0,0,0,0,0},
     {0,1,0,1,0},
     {0,1,0,1,0},
     {0,1,1,1,0},
     {0,0,0,1,0},
     {0,0,0,1,0},
     {0,0,0,0,0}},

    // 5
    {{0,0,0,0,0},
     {0,1,1,1,0},
     {0,1,0,0,0},
     {0,1,1,1,0},
     {0,0,0,1,0},
     {0,1,1,1,0},
     {0,0,0,0,0}},

    // 6
    {{0,0,0,0,0},
     {0,1,1,1,0},
     {0,1,0,0,0},
     {0,1,1,1,0},
     {0,1,0,1,0},
     {0,1,1,1,0},
     {0,0,0,0,0}},

    // 7
    {{0,0,0,0,0},
     {0,1,1,1,0},
     {0,0,0,1,0},
     {0,0,0,1,0},
     {0,0,0,1,0},
     {0,0,0,1,0},
     {0,0,0,0,0}},



    // 8
    {{0,0,0,0,0},
     {0,1,1,1,0},
     {0,1,0,1,0},
     {0,1,1,1,0},
     {0,1,0,1,0},
     {0,1,1,1,0},
     {0,0,0,0,0}},

    // 9
    {{0,0,0,0,0},
     {0,1,1,1,0},
     {0,1,0,1,0},
     {0,1,1,1,0},
     {0,0,0,1,0},
     {0,1,1,1,0},
     {0,0,0,0,0}}
};
int sudoku[162];


int main(int argc, char* argv[]) {
    if (pickPuzzle(sudoku)==0){return 1;}

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("SDL3", 1000,900,SDL_WINDOW_RESIZABLE);
    SDL_Event event;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);


    int width, height;
    int c=0;
    int p;
    int pt;
    float x;
    float y;
    int f=0;
    int F=0;
    int error=0;
    SDL_FRect r;
    
    int running = 1;
    while (running) {
        SDL_GetWindowSize(window, &width, &height);
        float cell_w = width / 9.0f;
        float cell_h = height / 9.0f;
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT ||(event.type == SDL_EVENT_KEY_DOWN && event.key.key==SDLK_ESCAPE)) {
                save_sudoku(sudoku, "zave.txt");
                running = 0;    
        
            }else if (event.type == SDL_EVENT_KEY_DOWN) {
                if (event.key.key==SDLK_UP){p-=9;if(p<0){p+=9;}continue;}
                if (event.key.key==SDLK_DOWN){p+=9;if(p>80){p-=9;}continue;}
                if (event.key.key==SDLK_LEFT){p-=1;if(p<0){p+=1;}continue;}
                if (event.key.key==SDLK_RIGHT){p+=1;if(p>80){p-=1;}continue;}
        
                switch(event.key.key){
                    case SDLK_1:c=1;f=1;continue;
                    case SDLK_2:c=2;f=1;continue;
                    case SDLK_3:c=3;f=1;continue;
                    case SDLK_4:c=4;f=1;continue;
                    case SDLK_5:c=5;f=1;continue;
                    case SDLK_6:c=6;f=1;continue;
                    case SDLK_7:c=7;f=1;continue;
                    case SDLK_8:c=8;f=1;continue;
                    case SDLK_9:c=9;f=1;continue;
                }
        
            } else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
                x= event.button.x;
                y= event.button.y;
                pt=9*(int)(y/cell_h)+(int)(x/cell_w);
                if ((p==pt) && F ){F=0;}
                else{F=1;}
                p=pt;        
            }
        }

        if (f==1){
            f=0;
            if (sudoku[p]==0 && F){
                sudoku[p]=c;
                if (c!=sudoku[p+81]){F=0;error=1;}
            }
        }
        
        
        SDL_SetRenderDrawColor(renderer, 255, 250, 255, 255);
        SDL_RenderClear(renderer);

        creat_grid(renderer,cell_w,cell_h);

        if(F){highlight(renderer,cell_w,cell_h,sudoku,p);}

        if (is_full(sudoku)){
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderClear(renderer);
        }

        for (int i = 0; i < 81; i++){
            if (sudoku[i]==sudoku[i+81]||sudoku[i]==0){drawDigit(renderer, sudoku[i] , (i % 9)*cell_w +1, (i/9)*cell_h +1 ,cell_w,cell_h,digits,0);}
            else{drawDigit(renderer, c , (i % 9)*cell_w +1, (i/9)*cell_h +1 ,cell_w,cell_h,digits,1);sudoku[i]=0;}
        }
        
        SDL_RenderPresent(renderer);


        if (error){
            SDL_Delay(360);
            error=0;
        }else{SDL_Delay(15);}
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
