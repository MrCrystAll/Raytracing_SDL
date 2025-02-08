#include <SDL3/SDL.h>
#include <iostream>
#include <Raytracing/Utils/Colors.h>

#include <Raytracing/Light/LightManager.h>

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

    std::vector<Ray> rays = {};
    std::vector<std::vector<Vector2D>> positions = {};


    Ray ray = Ray(
        Vector2D(10, 10),
        Vector2D(1, 0),
        1.0f
    );

    for (int i = 0; i < 10; i++) {
        rays.push_back(
            Ray(
                Vector2D(40, (i + 5) * 30),
                Vector2D(1, 0),
                1.0f
            )
        );
        positions.push_back({ rays[i].GetPosition() });
    }

    LightManager manager = LightManager(rays);


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

        std::vector<Vector2D> ray_pos = manager.Step(1);

        for (int i = 0; i < ray_pos.size(); i++) {
            positions[i].push_back(ray_pos[i]);

            for (int j = 0; j < positions[i].size() - 1; j++) {
                Vector2D currentPos = positions[i][j];
                Vector2D nextPos = positions[i][j + 1];

                SDL_RenderLine(renderer, currentPos.GetX(), currentPos.GetY(), nextPos.GetX(), nextPos.GetY());
            }
        }


        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}