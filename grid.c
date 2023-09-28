#include "grid.h"

/*This code can render a grid, so u can easily implement a game based on it, or make everything u want based on grid*/

#if 0
//FULLSCREEN
#define WINDOWS_X 0
#define WINDOWS_Y 0
#define WINDOWS_WIDTH 1920
#define WINDOWS_HEIGHT 1080

#else
#define WINDOWS_X 10
#define WINDOWS_Y -20
#define WINDOWS_WIDTH 1900
#define WINDOWS_HEIGHT 1080
#endif

#define GRID_SIZE 20
#define GRID_DIM 1000

void render_grid(SDL_Renderer *renderer,int x, int y){
    
    SDL_SetRenderDrawColor(renderer,0x55,0x55,0x55,255);

    int cell_size = GRID_DIM/GRID_SIZE;

    SDL_Rect cell;
    cell.w = cell_size;
    cell.h = cell_size;

    for(int i = 0;i<GRID_SIZE;i++){
        for(int j = 0;j<GRID_SIZE;j++){
            cell.x = x + (i*cell_size);
            cell.y = y + (j*cell_size);
            SDL_RenderDrawRect(renderer,&cell);
        }


    }
}


int main(){
    
    SDL_Window *window;
    SDL_Renderer *renderer;

    if (SDL_INIT_VIDEO < 0){
        fprintf(stderr,"ERROR : SDL_INIT_VIDEO");
    }

    window = SDL_CreateWindow("Snake",WINDOWS_X,WINDOWS_Y,WINDOWS_WIDTH,WINDOWS_HEIGHT,SDL_WINDOW_BORDERLESS);

    if (!window){
        fprintf(stderr,"ERROR :  !window");
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    if(!renderer){
        fprintf(stderr,"ERROR :  !renderer");
    }
    

    int grid_x = (WINDOWS_WIDTH/2)-(GRID_DIM/2); 
    int grid_y = (WINDOWS_HEIGHT/2)-(GRID_DIM/2);


	bool quit = false;
	SDL_Event event;
	
	while(!quit){
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_KEYUP:
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym){
						case SDLK_ESCAPE:
							quit = true;
							break;
					}
			}
		}


	
    SDL_RenderClear(renderer);

    render_grid(renderer,grid_x,grid_y);
    SDL_SetRenderDrawColor(renderer,0x10,0x10,0x10,255);

   
    SDL_RenderPresent(renderer);

    }
 


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;
	
}
