#include <SDL3/SDL.h>
#include <iostream>

#define SDL_WHITE {255, 255, 255};
#define SDL_RED {255, 0, 0};

int main(int argc, char* argv[]) {

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Demo", 800, 600, SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool quit = false;

    SDL_Event event;
    SDL_Color color = SDL_RED;

    // Main loop
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}