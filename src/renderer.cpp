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
    std::map<std::string, double>::iterator it;
    int pos = 0;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    for(it = rates.begin(); it != rates.end(); it++) {
        SDL_RenderDebugText(renderer, CURRENCYLISTINPUTOFFSETX, CURRENCYLISTINPUTOFFSETY + pos, it->first.c_str());
        pos += 10;
    }
}

void RenderNumberInput(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDebugTextFormat(renderer, INPUTOFFSETX, INPUTOFFSETY, "INPUT: %s %s", input.c_str(), selected_input_currency.c_str());
}

void RenderNumberOutput(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDebugTextFormat(renderer, OUTPUTOFFSETX, OUTPUTOFFSETY, "OUTPUT: %.2lf %s", output, selected_output_currency.c_str());
}