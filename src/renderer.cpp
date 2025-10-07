#include <SDL3/SDL.h>
#include <cmath>
#include <string>
#include <map>
#include "renderer.h"
#include "currency.h"

void RenderBackground(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

void RenderCurrencyLists(SDL_Renderer *renderer) {

    // make look pretty

    
    
    SDL_FRect left;
    left.x = 17;
    left.y = 148;
    left.w = 29;
    left.h = 12;

    SDL_FRect right;
    right.x = 197;
    right.y = 148;
    right.w = 29;
    right.h = 12;

    SDL_SetRenderDrawColor(renderer, 0, 115, 255, SDL_ALPHA_OPAQUE);

    SDL_RenderFillRect(renderer, &left);
    SDL_RenderFillRect(renderer, &right);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    SDL_RenderRect(renderer, &left);
    SDL_RenderRect(renderer, &right);

    for(int i = 0; i < currency_codes.size(); i++) {
        SDL_RenderDebugText(renderer, CURRENCYLISTINPUTOFFSETX, CURRENCYLISTINPUTOFFSETY + (selected_input_index * 10) - (i * 10), currency_codes[i].c_str());
    }

    for(int i = 0; i < currency_codes.size(); i++) {
        SDL_RenderDebugText(renderer, CURRENCYLISTOUTPUTOFFSETX, CURRENCYLISTOUTPUTOFFSETY + (selected_output_index * 10) - (i * 10), currency_codes[i].c_str());
    }
}

void RenderListBorders(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    SDL_FRect top;
    top.x = 0;
    top.y = 0;
    top.w = 380;
    top.h = 70;

    SDL_FRect bottom;
    bottom.x = 0;
    bottom.y = 240;
    bottom.w = 380;
    bottom.h = 140;

    SDL_RenderFillRect(renderer, &top);
    SDL_RenderFillRect(renderer, &bottom);
}

void RenderNumberInput(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDebugTextFormat(renderer, INPUTOFFSETX, INPUTOFFSETY, "%s %s", input.c_str(), currency_codes[selected_input_index].c_str());
}

void RenderNumberOutput(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDebugTextFormat(renderer, OUTPUTOFFSETX, OUTPUTOFFSETY, "%.2lf %s", output, currency_codes[selected_output_index].c_str());
}

void RenderDetails(SDL_Renderer *renderer) {
    
}