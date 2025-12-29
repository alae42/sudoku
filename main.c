
#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>


int sudoku[162];
int drasudo[81]= {0};
int digits[11][7][5] = {
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



int cor(int row, int col) { return 9*row + col; }


void drawDigit(SDL_Renderer* renderer, int number, int w, int h, int cell_w, int cell_h) {
    int (*pattern)[5] = digits[number];
    int blockWidth = cell_w/ 5;
    int blockHeight = cell_h / 7;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 5; j++) {
            if(pattern[i][j]) {
                SDL_FRect r = { w + j*blockWidth, h + i*blockHeight, blockWidth, blockHeight };
                SDL_RenderFillRect(renderer, &r);
            }
        }
    }
}


void creat_grid(SDL_Renderer *renderer,float  cell_w, float cell_h){



    SDL_SetRenderDrawColor(renderer, 0,90,90, 255);
    for (int i = 0; i <= 9; i++) {
        SDL_RenderLine(renderer, i * cell_w, 0, i * cell_w, 9*cell_h);    
        SDL_RenderLine(renderer, 0, i * cell_h, 9*cell_w, i * cell_h);   
    }


    SDL_SetRenderDrawColor(renderer, 100, 0, 0, 255);
    for (int i = 0; i <= 9; i += 3) {
        SDL_RenderLine(renderer, i * cell_w +1, 0, i * cell_w+1, 9*cell_h);      
        SDL_RenderLine(renderer, 0, i * cell_h+1, 9*cell_w, i * cell_h+1);   
        
        SDL_RenderLine(renderer, i * cell_w -1, 0, i * cell_w-1, 9*cell_h);      
        SDL_RenderLine(renderer, 0, i * cell_h-1, 9*cell_w, i * cell_h-1);   
    }





}


void drawcross(SDL_Renderer *renderer, int p ,float cell_w,float cell_h ){
    SDL_SetRenderDrawColor(renderer, 80, 255, 20, 35);
    for (int i = 0; i <9; i++){
        SDL_FRect r1;
        if(drasudo[cor(i,p % 9)]==0){
            r1 = (SDL_FRect){ (p % 9)*cell_w, i*cell_h,cell_w,cell_h };
            SDL_RenderFillRect(renderer, &r1);
            drasudo[cor(i,p % 9)]=1;
        }

        if(drasudo[cor(p / 9,i)]==0){
            r1 = (SDL_FRect){ i*cell_w, (p/9)*cell_h,cell_w,cell_h };
            SDL_RenderFillRect(renderer, &r1);
            drasudo[9*(p / 9)+i]=1;
        }

        if(drasudo[cor(3*((p/9)/3)+i/3,3*((p%9)/3)+i%3)]==0){       
            r1=(SDL_FRect){ (3*((p%9)/3)+i%3)*cell_w, (3*((p/9)/3)+i/3)*cell_h,cell_w,cell_h };
            SDL_RenderFillRect(renderer, &r1);
            drasudo[cor(3*((p/9)/3)+i/3,3*((p%9)/3)+i%3)]=1;
        }
        


    }


}

void reset_drasudo() {
    for (int i = 0; i < 81; i++) drasudo[i] = 0;
}

int is_full(){
    int t=1;
    for (int i = 0; i < 81; i++) {if (sudoku[i] == 0){t=0;}}
    return t;
}

int main(int argc, char* argv[]) {

    char strdoku[164];

    FILE *pF= fopen("zudo.txt","r");
    fgets(strdoku,164,pF);
    fclose(pF);

    for (int i = 0; i < 162; i++){sudoku[i]=strdoku[i]- '0';}
    
    SDL_Window* window = SDL_CreateWindow("SDL3", 1000,1000,SDL_WINDOW_BORDERLESS|SDL_WINDOW_MOUSE_GRABBED);
    SDL_Event event;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);


    int c=0;
    int p;
    int pt;
    float x;
    float y;
    int f=0;
    int F=0;
    int running = 1;

    int width, height;
    while (running) {
        SDL_GetWindowSize(window, &width, &height);
        float cell_w = width / 9.0f;
        float cell_h = height / 9.0f;
        SDL_FRect r;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT ||(event.type == SDL_EVENT_KEY_DOWN && event.key.key==SDLK_ESCAPE)) {
                running = 0;
            }else if (event.type == SDL_EVENT_KEY_DOWN) {
                if (event.key.key==SDLK_Z){p-=9;if(p<0){p+=9;}continue;}
                if (event.key.key==SDLK_S){p+=9;if(p>80){p-=9;}continue;}
                if (event.key.key==SDLK_Q){p-=1;if(p<0){p+=1;}continue;}
                if (event.key.key==SDLK_D){p+=1;if(p>80){p-=1;};continue;}
                f=1;
                switch(event.key.key){
                    case SDLK_0:c=0;continue;
                    case SDLK_1:c=1;continue;
                    case SDLK_2:c=2;continue;
                    case SDLK_3:c=3;continue;
                    case SDLK_4:c=4;continue;
                    case SDLK_5:c=5;continue;
                    case SDLK_6:c=6;continue;
                    case SDLK_7:c=7;continue;
                    case SDLK_8:c=8;continue;
                    case SDLK_9:c=9;continue;
                }
            } else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
                x= event.button.x;
                y= event.button.y;
                pt=cor((int)(y/cell_h),(int)(x/cell_w));
                if (pt>80){continue;}
                if ((p==pt) && F ){F=0;}
                else{F=1;}

                p=pt;
                
            }
        }



        if (f==1){
            if (sudoku[p]==0 && c==sudoku[p+81] && F){sudoku[p]=c;}
            f=0;
            F=0;
        }
        
        
        SDL_SetRenderDrawColor(renderer, 255, 250, 255, 255);
        SDL_RenderClear(renderer);

        creat_grid(renderer,cell_w,cell_h );

        if(F){
            reset_drasudo();
            SDL_SetRenderDrawColor(renderer, 50, 70, 255, 150);
            r = (SDL_FRect){ (p % 9)*cell_w, (p/9)*cell_h,cell_w,cell_h };
            SDL_RenderFillRect(renderer, &r);
            drawcross(renderer, p ,cell_w,cell_h );
        
            if (sudoku[p]!=0){
                for (int i = 0; i < 81; i++){
                    if (sudoku[i]==sudoku[p]){
                        drasudo[i] = 1;
                        if (i!=p){
                            SDL_SetRenderDrawColor(renderer, 250, 50, 255, 120);
                            r = (SDL_FRect){ (i % 9)*cell_w, (i/9)*cell_h,cell_w,cell_h };
                            SDL_RenderFillRect(renderer, &r);
                        }
                    }
                }
            }
        }

        if (is_full()){
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderClear(renderer);
        }

        for (int i = 0; i < 81; i++){
            drawDigit(renderer, sudoku[i] , (i % 9)*cell_w +1, (i/9)*cell_h +1 ,cell_w,cell_h);
        }
        SDL_RenderPresent(renderer);

        SDL_Delay(20);

    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}


