#include <SDL3/SDL.h>
#include <iostream>
#include <Raytracing/Utils/Colors.h>
#include <Raytracing/Shapes/Rectangle.h>
#include <Raytracing/Shapes/Circle.h>

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
    SDL_Color bg = SDL_BLACK;
    SDL_Color rectColor = SDL_WHITE;

    Rectangle rectangle = Rectangle(500, 300, 200, 50, true);
    Circle circleFill = Circle(200, 200, 180, true);
    Circle circle = Circle(200, 200, 200, false);


    // Main loop
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, DECOMPOSE_COLOR(bg), 255);
        
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, DECOMPOSE_COLOR(rectColor), 255);
        rectangle.Draw(renderer);
        circle.Draw(renderer);
        circleFill.Draw(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}