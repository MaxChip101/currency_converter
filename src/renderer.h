#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL.h>

void RenderBackground(SDL_Renderer *renderer);
void RenderCurrencyLists(SDL_Renderer *renderer);
void RenderListBorders(SDL_Renderer *renderer);
void RenderNumberInput(SDL_Renderer *renderer);
void RenderNumberOutput(SDL_Renderer *renderer);
void RenderDetails(SDL_Renderer *renderer);

#endif