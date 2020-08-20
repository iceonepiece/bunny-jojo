#pragma once

#include <iostream>
#include <SDL2/SDL.h>

class Game {
private:
  SDL_Window *window;
  SDL_GLContext mContext;
  SDL_Renderer *renderer;
  int ticksLastFrame;

public:
  bool isRunning;

  Game();
  ~Game();

  void initialize(int width, int height);
  void processInput();
  void update();
  void render();
  void destroy();
};
