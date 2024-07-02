#include "include/SDL2/SDL.h"
#include "include/SDL2/SDL_events.h"
#include <vector>

class Screen {
public:
  SDL_Event e;
  SDL_Window* window;
  SDL_Renderer *renderer;
  std::vector<SDL_FPoint> points;

  Screen() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(300 * 2, 300 * 2, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 2, 2);
  }

  void pixel(float x, float y) {
    points.push_back({x, y});
  }

  void show() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for(auto& point : points) {
      SDL_RenderDrawPointF(renderer, point.x, point.y);
    }
    SDL_RenderPresent(renderer);
  }

  void clear() {
    points.clear();
  }

  void input() {
    while(SDL_PollEvent(&e)) {
      if(e.type == SDL_QUIT) {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        window = nullptr;
        renderer = nullptr;
        SDL_Quit();
        exit(0);
      }
    }
  }
};
