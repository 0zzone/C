#include "SDL.h"

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    

    int posX = 300, posY = 200, width = 1000, height = 600;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Mon super jeu vidéo", posX, posY, width, height, SDL_WINDOW_RESIZABLE);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int valide = 1;
    while (valide == 1) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch(event.type){
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym){
                        case SDLK_b:
                            printf("Vous avez appuyez sur B \n");
                            continue;
                        
                        default:
                            continue;
                    }
                
                case SDL_QUIT:
                    valide = 0;
                    break;
                
                
                case SDL_MOUSEBUTTONDOWN:
                    if(event.button.button == SDL_BUTTON_LEFT){
                        printf("Clic gauche ;) \n");
                        break;
                    }
                    break;
                
                default:
                    break;
            }
        }

        /* Image ----------------------------- */
            SDL_Surface *image = NULL;
            SDL_Texture *texture = NULL;

            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

            image = SDL_LoadBMP("imaget.bmp");

            if(image == NULL){
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                printf("L'image n'a pas pu être chargée");
            }

            texture = SDL_CreateTextureFromSurface(renderer, image);
            SDL_FreeSurface(image);

            if(texture == NULL){
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                printf("Impossible de créer la texture");
                valide = 0;
            }

            SDL_Rect rectangle = {};
                rectangle.x = 0;
                rectangle.y = 0;

            
            printf("%d", rectangle.w);
            if(SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) != 0){
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                printf("Impossible de charger la texture'");
                valide = 0;
            }


            if(SDL_RenderCopy(renderer, texture, NULL, &rectangle) != 0){
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                printf("Impossible d'afficher la texture'");
                valide = 0;
            }

        /* ----------------------------------------------- */
        
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }


    SDL_RenderClear(renderer);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}


// gcc main.c -o prog $(sdl2-config --cflags --libs)