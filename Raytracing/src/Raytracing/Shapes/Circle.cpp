#include <Raytracing/Shapes/Circle.h>

Circle::Circle(float x, float y, float radius, bool fill): Shape(x, y), radius(radius), fill(fill)
{
}

void Circle::Draw(SDL_Renderer* renderer)
{
    if (this->fill) {
        for (int w = 0; w < radius * 2; w++)
        {
            for (int h = 0; h < radius * 2; h++)
            {
                int dx = (int)radius - w; // horizontal offset
                int dy = (int)radius - h; // vertical offset
                if ((dx * dx + dy * dy) < (radius * radius))
                {
                    SDL_RenderPoint(renderer, x + dx, y + dy);
                }
            }
        }
    }
    else {
        const int32_t diameter = ((int)this->radius * 2);

        int32_t x = ((int)this->radius - 1);
        int32_t y = 0;
        int32_t tx = 1;
        int32_t ty = 1;
        int32_t error = (tx - diameter);

        while (x >= y)
        {
            //  Each of the following renders an octant of the circle
            SDL_RenderPoint(renderer, this->x + x, this->y - y);
            SDL_RenderPoint(renderer, this->x + x, this->y + y);
            SDL_RenderPoint(renderer, this->x - x, this->y - y);
            SDL_RenderPoint(renderer, this->x - x, this->y + y);
            SDL_RenderPoint(renderer, this->x + y, this->y - x);
            SDL_RenderPoint(renderer, this->x + y, this->y + x);
            SDL_RenderPoint(renderer, this->x - y, this->y - x);
            SDL_RenderPoint(renderer, this->x - y, this->y + x);

            if (error <= 0)
            {
                ++y;
                error += ty;
                ty += 2;
            }

            if (error > 0)
            {
                --x;
                tx += 2;
                error += (tx - diameter);
            }
        }
    }
}
