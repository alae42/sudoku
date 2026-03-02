#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>


void drawDigit(SDL_Renderer* renderer, int number, int w, int h, int cell_w, int cell_h,int digits[10][7][5],int error ) {
    int (*pattern)[5] = digits[number];
    int blockWidth = cell_w/ 5;
    int blockHeight = cell_h / 7;

    SDL_SetRenderDrawColor(renderer, 255*error, 0, 0, 255);

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

void drawcross(SDL_Renderer *renderer, int p ,float cell_w,float cell_h){
    SDL_SetRenderDrawColor(renderer, 80, 255, 20, 35);
    for (int i = 0; i <9; i++){
        SDL_FRect r1;
        if(i/3!=(p/9)/3){
            r1 = (SDL_FRect){ (p % 9)*cell_w, i*cell_h,cell_w,cell_h };
            SDL_RenderFillRect(renderer, &r1);
        }

        if(i/3!= (p % 9)/3){
            r1 = (SDL_FRect){ i*cell_w, (p/9)*cell_h,cell_w,cell_h };
            SDL_RenderFillRect(renderer, &r1);
        }

        if(i!=0){       
            r1=(SDL_FRect){ (3*((p%9)/3)+(p+i)%3)*cell_w, (3*((p/9)/3)+(p/9+i/3)%3)*cell_h,cell_w,cell_h };
            SDL_RenderFillRect(renderer, &r1);
        }
    }
}

void highlight(SDL_Renderer *renderer, float cell_w, float cell_h,int sudoku[162],int p){
    SDL_SetRenderDrawColor(renderer, 50, 70, 255, 150);

    SDL_FRect r = { (p % 9)*cell_w, (p/9)*cell_h,cell_w,cell_h };
    SDL_RenderFillRect(renderer, &r);

    drawcross(renderer, p ,cell_w,cell_h);

    if (sudoku[p]!=0){
        for (int i = 0; i < 81; i++){
            if (sudoku[i]==sudoku[p] && i!=p ){
                    SDL_SetRenderDrawColor(renderer, 250, 50, 255, 120);
                    r = (SDL_FRect){ (i % 9)*cell_w, (i/9)*cell_h,cell_w,cell_h };
                    SDL_RenderFillRect(renderer, &r);
            }
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int is_full(int sudoku[162]){
    int t=1;
    for (int i = 0; i < 81; i++) {

        if (sudoku[i] == 0){t=0;}

    }
    
    return t;
}

void save_sudoku(int sudoku[162], char *filename) {
    FILE *file = fopen(filename, "w");

    for (int i = 0; i < 161; i++) {
        fprintf(file, "%d", sudoku[i]);
    }

    fclose(file);
}

