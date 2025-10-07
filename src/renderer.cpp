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

    SDL_FRect left_list;
    left_list.x = 31;
    left_list.y = 70;
    left_list.w = 41;
    left_list.h = 170;

    SDL_FRect right_list;
    right_list.x = 211;
    right_list.y = 70;
    right_list.w = 41;
    right_list.h = 170;
    
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, SDL_ALPHA_OPAQUE);

    SDL_RenderFillRect(renderer, &left_list);
    SDL_RenderFillRect(renderer, &right_list);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    SDL_RenderRect(renderer, &left_list);
    SDL_RenderRect(renderer, &right_list);

    SDL_FRect left_selector;
    left_selector.x = 37;
    left_selector.y = 148;
    left_selector.w = 29;
    left_selector.h = 12;

    SDL_FRect right_selector;
    right_selector.x = 217;
    right_selector.y = 148;
    right_selector.w = 29;
    right_selector.h = 12;

    SDL_SetRenderDrawColor(renderer, 0, 115, 255, SDL_ALPHA_OPAQUE);

    SDL_RenderFillRect(renderer, &left_selector);
    SDL_RenderFillRect(renderer, &right_selector);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    SDL_RenderRect(renderer, &left_selector);
    SDL_RenderRect(renderer, &right_selector);

    for(int i = 0; i < currency_codes.size(); i++) {
        SDL_RenderDebugText(renderer, 40, 150 + (selected_input_index * 10) - (i * 10), currency_codes[i].c_str());
    }

    for(int i = 0; i < currency_codes.size(); i++) {
        SDL_RenderDebugText(renderer, 220, 150 + (selected_output_index * 10) - (i * 10), currency_codes[i].c_str());
    }

    SDL_FRect list_selector;
    if (left_right_selection) {
        list_selector.x = 206;
    } else {
        list_selector.x = 26;
    }
    list_selector.y = 70;
    list_selector.w = 2;
    list_selector.h = 170;

    SDL_SetRenderDrawColor(renderer, 60, 160, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &list_selector);
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
    bottom.h = 20;

    SDL_RenderFillRect(renderer, &top);
    SDL_RenderFillRect(renderer, &bottom);
}

void RenderNumberInput(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDebugTextFormat(renderer, 10, 50, "%s %s", input.c_str(), currency_codes[selected_input_index].c_str());
}

void RenderNumberOutput(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDebugTextFormat(renderer, 190, 50, "%.2lf %s", output, currency_codes[selected_output_index].c_str());
}

void RenderDetails(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDebugText(renderer, 80, 10, "CURRENCY CONVERTER");
    SDL_RenderDebugText(renderer, 107, 120, ">>>>>>>>>");
}