#include <stdio.h>
#include <SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 340;

void event_loop() {
    int quit = 0;
    while(quit == 0) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                quit = 1;
            }
            if(event.type == SDL_KEYDOWN){
                // TODO
            }
            if(event.type == SDL_MOUSEMOTION){
                // TODO
            }
        }
    }
}

int main(int argc, char** argv) {
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow(
            "SDL2 Demo",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
    );
    if (NULL == window) {
        printf("Window Error");
    }
    surface = SDL_GetWindowSurface(window);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x00, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);

//    SDL_Delay(5000);
    event_loop();

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
