#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>


int letters[20][9][9] = {
/* =================   ================= */
{
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
},

/* ================= O ================= */
{
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,1,1,1,0,0,0},
 {0,0,1,0,0,0,1,0,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,0,1,0,0,0,1,0,0},
 {0,0,0,1,1,1,0,0,0},
 {0,0,0,0,0,0,0,0,0}
},

/* ================= L ================= */
{
 {0,0,0,0,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,0},
 {0,0,0,0,0,0,0,0,0}
},

/* ================= D ================= */
{
 {0,0,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,0,0,0},
 {0,1,0,0,0,0,1,0,0},
 {0,1,0,0,0,0,1,0,0},
 {0,1,0,0,0,0,1,0,0},
 {0,1,0,0,0,0,1,0,0},
 {0,1,0,0,0,0,1,0,0},
 {0,1,1,1,1,1,0,0,0},
 {0,0,0,0,0,0,0,0,0}
},

/* ================= N ================= */
{
 {0,0,0,0,0,0,0,0,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,1,0,0,0,0,1,0},
 {0,1,0,1,0,0,0,1,0},
 {0,1,0,0,1,0,0,1,0},
 {0,1,0,0,0,1,0,1,0},
 {0,1,0,0,0,0,1,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,0,0,0,0,0,0,0,0}
},

/* ================= E ================= */
{
 {0,0,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,0},
 {0,1,0,0,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,0,0,0},
 {0,1,0,0,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,0},
 {0,0,0,0,0,0,0,0,0}
},

/* ================= W ================= */
{
 {0,0,0,0,0,0,0,0,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,0,0,1,0,0,1,0},
 {0,1,0,1,0,1,0,1,0},
 {0,1,1,0,0,0,1,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,0,0,0,0,0,0,0,0}
},
/* ================= A ================= */
{
 {0,0,0,0,0,0,0,0,0},
 {0,0,1,1,1,1,1,0,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,1,1,1,1,1,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,0,0,0,0,0,0,0,0}
},

/* ================= S ================= */
{
 {0,0,0,0,0,0,0,0,0},
 {0,0,1,1,1,1,1,0,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,0,0,0,0,0,0,0},
 {0,0,1,1,1,1,1,0,0},
 {0,0,0,0,0,0,0,1,0},
 {0,0,0,0,0,0,0,1,0},
 {0,1,1,1,1,1,1,0,0},
 {0,0,0,0,0,0,0,0,0}
},


/* ================= Y ================= */
{
 {0,0,0,0,0,0,0,0,0},
 {0,1,0,0,0,0,0,1,0},
 {0,0,1,0,0,0,1,0,0},
 {0,0,0,1,0,1,0,0,0},
 {0,0,0,0,1,0,0,0,0},
 {0,0,0,0,1,0,0,0,0},
 {0,0,0,0,1,0,0,0,0},
 {0,0,0,0,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
},

/* ================= R ================= */
{
 {0,0,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,0,0,0},
 {0,1,0,0,0,0,1,0,0},
 {0,1,0,0,0,0,1,0,0},
 {0,1,1,1,1,1,0,0,0},
 {0,1,0,0,1,0,0,0,0},
 {0,1,0,0,0,1,0,0,0},
 {0,1,0,0,0,0,1,0,0},
 {0,0,0,0,0,0,0,0,0}
},

/* ================= M ================= */
{
 {0,0,0,0,0,0,0,0,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,1,0,0,0,1,1,0},
 {0,1,0,1,0,1,0,1,0},
 {0,1,0,0,1,0,0,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,0,0,0,0,0,0,0,0}
},

/* ================= H ================= */
{
 {0,0,0,0,0,0,0,0,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,1,1,1,1,1,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,1,0,0,0,0,0,1,0},
 {0,0,0,0,0,0,0,0,0}
},

/* ================= X ================= */
{
 {0,0,0,0,0,0,0,0,0},
 {0,1,0,0,0,0,0,1,0},
 {0,0,1,0,0,0,1,0,0},
 {0,0,0,1,0,1,0,0,0},
 {0,0,0,0,1,0,0,0,0},
 {0,0,0,1,0,1,0,0,0},
 {0,0,1,0,0,0,1,0,0},
 {0,1,0,0,0,0,0,1,0},
 {0,0,0,0,0,0,0,0,0}
},

/* ================= T ================= */
{
 {0,0,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,0},
 {0,0,0,0,1,0,0,0,0},
 {0,0,0,0,1,0,0,0,0},
 {0,0,0,0,1,0,0,0,0},
 {0,0,0,0,1,0,0,0,0},
 {0,0,0,0,1,0,0,0,0},
 {0,0,0,0,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
}
};

void drawletter(SDL_Renderer* renderer, int letter, int w, int h, int cell_w, int cell_h,int letters[20][9][9]) {
    int (*pattern)[9] = letters[letter];
    int blockWidth = cell_w/ 9;
    int blockHeight = cell_h / 9;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for(int i = 0; i <9; i++) {
        for(int j = 0; j < 9; j++) {
            if(pattern[i][j]) {
                SDL_FRect r = { w + j*blockWidth, h + i*blockHeight, blockWidth, blockHeight };
                SDL_RenderFillRect(renderer, &r);
            }
        }
    }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void txt_window1(SDL_Renderer* renderer, int cell_w, int cell_h){
    int pattern[10]={0,1,2,3,0,0,4,5,6,0};
    for (int j=0;j<10;j++){
        drawletter(renderer, pattern[j],j*cell_w ,2*cell_h , cell_w, cell_h  ,  letters);
    }
}

void box_window1(SDL_Renderer *renderer,float  cell_w, float cell_h){
    SDL_SetRenderDrawColor(renderer, 0,2,2,255);
    float x1=cell_w;
    float x4=4 * cell_w;
    float x6=6 * cell_w;
    float x9=9 * cell_w;
    float y2=2 * cell_h;
    float y3=3 * cell_h;

    SDL_FPoint box1[] = {
    {x1, y2},
    {x1, y3},
    {x4, y3},
    {x4, y2},
    {x1, y2}
    };
    SDL_RenderLines(renderer, box1, 5);

    SDL_FPoint box2[] = {
    {x6, y2},
    {x6, y3},
    {x9, y3},
    {x9, y2},
    {x6, y2}
    };
    SDL_RenderLines(renderer, box2, 5);
}

int wantSave(){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("SDL3", 1000,500,SDL_WINDOW_BORDERLESS);
    SDL_Event event;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

    int save;
    int p;
    int running = 1;
    int width, height;

    while (running) {
        SDL_GetWindowSize(window, &width, &height);
        float cell_w = width / 10.0f;
        float cell_h = height / 5.0f;
        
        SDL_FRect r;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key==SDLK_ESCAPE) {
                save=-1;
                running = 0;
            }

            else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
                p=10*(int)(event.button.y/cell_h)+(int)(event.button.x/cell_w);
                if (p==21||p==22||p==23){
                    save=1;
                    running=0;
                }else if (p==26||p==27||p==28){
                    save=0;
                    running=0;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 250, 255, 255);
        SDL_RenderClear(renderer);

        box_window1(renderer,cell_w,cell_h);
        txt_window1(renderer,cell_w,cell_h);

        SDL_RenderPresent(renderer);
        SDL_Delay(20);

    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return save;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void txt_window2(SDL_Renderer* renderer, int cell_w, int cell_h){
    int EASY[]      = {0,0,0,5, 7, 8, 9,0,0,0,0,0,0};
    int NORMAL[]    = {0,0,0,4, 1, 10, 11, 7, 2,0,0,0,0};
    int HARD[]      = {0,0,0,12, 7, 10, 3,0,0,0,0,0,0};
    int EXTREME[]   = {0,0,0,5, 13, 14, 10, 5, 11, 5,0,0,0};

    for (int j=0;j<13;j++){drawletter(renderer, EASY[j],j*cell_w +4 , 2*cell_h+4 , cell_w, cell_h  ,  letters);}
    for (int j=0;j<13;j++){drawletter(renderer, NORMAL[j],j*cell_w +4, 4*cell_h+4 , cell_w, cell_h  ,  letters);}
    for (int j=0;j<13;j++){drawletter(renderer, HARD[j],j*cell_w +4, 6*cell_h +4, cell_w, cell_h  ,  letters);}
    for (int j=0;j<13;j++){drawletter(renderer, EXTREME[j],j*cell_w+4 , 8*cell_h+4 , cell_w, cell_h  ,  letters);}

}

void box_window2(SDL_Renderer *renderer,float  cell_w, float cell_h){
    SDL_SetRenderDrawColor(renderer, 0,2,2,255);

    float x3 = 3* cell_w;
    float x7 = 7* cell_w;
    float x9 = 9* cell_w;
    float x10 = 10* cell_w;

    float y2 = 2* cell_h;
    float y3 = 3* cell_h;
    float y4 = 4* cell_h;
    float y5 = 5* cell_h;
    float y6 = 6* cell_h;
    float y7 = 7* cell_h;
    float y8 = 8* cell_h;
    float y9 = 9* cell_h;

    SDL_FPoint box2[] = {
    {x3, y2},
    {x7, y2},
    {x7, y3},
    {x3, y3},
    {x3, y2}
    };
    SDL_RenderLines(renderer, box2, 5);

    SDL_FPoint box3[] ={
    {x3, y6},
    {x7, y6},
    {x7, y7},
    {x3, y7},
    {x3, y6}
    };
    SDL_RenderLines(renderer, box3, 5);

    SDL_FPoint box4[] = {
    {x3, y4},
    {x9, y4},
    {x9, y5},
    {x3, y5},
    {x3, y4}
    };
    SDL_RenderLines(renderer, box4, 5);

    SDL_FPoint box5[] = {
    {x3, y8},
    {x10, y8},
    {x10, y9},
    {x3, y9},
    {x3, y8}
    };
    SDL_RenderLines(renderer, box5, 5);



}

int whatdif(){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("SDL3", 870,750, SDL_WINDOW_BORDERLESS );
    SDL_Event event;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

    int dif;
    int p;
    int running = 1;
    int width, height;

    while (running) {
        SDL_GetWindowSize(window, &width, &height);
        float cell_w = width / 13.0f;
        float cell_h = height / 11.0f;
        SDL_FRect r;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key==SDLK_ESCAPE) {
                dif=-1;
                running = 0;
                }
            else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
                p=13*(int)(event.button.y/cell_h)+(int)(event.button.x/cell_w);
                if (p==29||p==30||p==31||p==32){
                    dif=0;
                    running=0;
                }else if (p==55||p==56||p==57||p==58||p==59||p==60){
                    dif=1;
                    running=0;
                }else if (p==81||p==82||p==83||p==84){
                    dif=2;
                    running=0;
                }else if (p==107||p==108||p==109||p==110||p==111||p==112||p==113){
                    dif=3;
                    running=0;
                }

            }
        
        }
        
        SDL_SetRenderDrawColor(renderer, 255, 250, 255, 255);
        SDL_RenderClear(renderer);
        box_window2(renderer,cell_w,cell_h);
        txt_window2(renderer,cell_w,cell_h);
        SDL_RenderPresent(renderer);
        SDL_Delay(20);

    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return dif;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int pickPuzzle(int sudoku[162]){
    int save=wantSave();
    int dificulty;
    int len;
    char strdoku[164];
    srand(time(NULL));
    FILE *pF;
    if(save==-1){return 0;}

    if (save==1){        
        pF= fopen("zave.txt","r");len=1;
    }

    if(save==0 || pF==NULL){
        dificulty=whatdif();
        if(dificulty==-1){return 0;}
        if (dificulty==0) {pF= fopen("sudoku_facile.txt","r");len=3;
        }else if (dificulty==1) {pF= fopen("sudoku_normale.txt","r");len=4;
        }else if (dificulty==2) {pF= fopen("sudoku_difficile.txt","r");len=1;
        }else if (dificulty==3) {pF= fopen("sudoku_extreme.txt","r");len=1;
        }
    }

    int r=rand()%len;
    for (int i = 0; i <= r; i++){fgets(strdoku, 164, pF);}

    fclose(pF);
    for (int i = 0; i < 162; i++){sudoku[i]=strdoku[i]- '0';}

    return 1;
}

