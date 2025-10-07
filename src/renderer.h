#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL.h>

#define CURRENCYLISTINPUTOFFSETX 20
#define CURRENCYLISTINPUTOFFSETY 150
#define CURRENCYLISTOUTPUTOFFSETX 200
#define CURRENCYLISTOUTPUTOFFSETY 150
#define INPUTOFFSETX 20
#define INPUTOFFSETY 50
#define OUTPUTOFFSETX 200
#define OUTPUTOFFSETY 50

void RenderBackground(SDL_Renderer *renderer);
void RenderCurrencyLists(SDL_Renderer *renderer);
void RenderListBorders(SDL_Renderer *renderer);
void RenderNumberInput(SDL_Renderer *renderer);
void RenderNumberOutput(SDL_Renderer *renderer);
void RenderDetails(SDL_Renderer *renderer);

#endif