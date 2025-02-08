#pragma once
#include <Raytracing/Raytracing.h>

#define SDL_WHITE {255, 255, 255}
#define SDL_BLACK {0, 0, 0}
#define SDL_DARK_GRAY {64, 64, 64}
#define SDL_GRAY {128, 128, 128}
#define SDL_LIGHT_GRAY {192, 192, 192}

#define SDL_RED {255, 0, 0}
#define SDL_GREEN {0, 255, 0}
#define SDL_BLUE {0, 0, 255}

#define SDL_YELLOW {255, 255, 0}
#define SDL_PINK {255, 0, 255}
#define SDL_NAVY_BLUE {0, 255, 255}

#define DECOMPOSE_COLOR(color) color.r, color.g, color.b
