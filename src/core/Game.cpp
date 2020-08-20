#include "./Game.hpp"
#include <GL/glew.h>

const unsigned int FPS = 60;
const unsigned int FRAME_TARGET_TIME = 1000 / FPS;

Game::Game() {
  this->isRunning = false;
}

Game::~Game() {}

void Game::initialize(int width, int height) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "Error initializing SDL." << std::endl;
    return;
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

  window = SDL_CreateWindow(
    NULL,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    width,
    height,
    SDL_WINDOW_OPENGL
  );

  if (!window) {
    std::cerr << "Error creating SDL window." << std::endl;
    return;
  }

  mContext = SDL_GL_CreateContext(window);

  renderer = SDL_CreateRenderer(window, -1, 0);
  if (!renderer) {
    std::cerr << "Error creating SDL renderer." << std::endl;
    return;
  }

  this->isRunning = true;
}

void Game::processInput() {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
    case SDL_QUIT: {
      isRunning = false;
      break;
    }
    case SDL_KEYDOWN: {
      if (event.key.keysym.sym == SDLK_ESCAPE) {
        isRunning = false;
      }
    }
    default: {
      break;
    }
  }
}

void Game::update() {
  int waitTime = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);
  if (waitTime > 0 && waitTime <= FRAME_TARGET_TIME) SDL_Delay(waitTime);
  float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;
  ticksLastFrame = SDL_GetTicks();

  // start your logics

  // end your logic
}

void Game::render() {
  glClearColor(0.86f, 0.86f, 0.86f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  SDL_GL_SwapWindow(window);

  /*
  SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
  SDL_RenderClear(this->renderer);

  // start your logic
  SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
  SDL_Rect wall {
    0,
    0,
    400,
    20
  };

  // end your logic

  SDL_RenderPresent(this->renderer);
  */
}

void Game::destroy() {
  SDL_GL_DeleteContext(mContext);
  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->window);
  SDL_Quit();
}
