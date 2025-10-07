#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>
#include <print>
#include <fstream>

#include "currency.h"
#include "renderer.h"

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

#define WINDOW_WIDTH 320
#define WINDOW_HEIGHT 260

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {

  std::ifstream token_file("token.txt");

  if (!token_file.is_open()) {
      SDL_Log("Failed to find token file");
      return SDL_APP_FAILURE;
  }

  std::string token;

  std::getline(token_file, token);

  token_file.close();

  InitCurrency(token);

  SDL_SetAppMetadata("Currency Converter", "0.0.1",
                     "github.com/MaxChip101/currency_converter");
  
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  if (!SDL_CreateWindowAndRenderer("Currency Converter", WINDOW_WIDTH, WINDOW_HEIGHT,
                                   0, &window, &renderer)) {
    SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  srand(time(NULL));

  return SDL_APP_CONTINUE;
}
// 1 + 1 = 11 (1 * 10 + 1)
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
  switch (event->type) {
    case SDL_EVENT_QUIT:
      return SDL_APP_SUCCESS;
      break;
    case SDL_EVENT_KEY_DOWN:
      switch (event->key.scancode) {
        case SDL_SCANCODE_RETURN:
          input_number = std::stod(input);
          output = input_number * (currency_rates[selected_output_index] / currency_rates[selected_input_index]);
          break;
        case SDL_SCANCODE_BACKSPACE:
          input.pop_back();
          if (input == "") {
            input = "0";
          }
          break;
        case SDL_SCANCODE_PERIOD:
          if (input.find('.') == std::string::npos) {
            input.push_back('.');
          }
          break;
        case SDL_SCANCODE_0:
          if (input.size() <= 1 && input[0] == '0') {
            input[0] = '0';
            break;
          }
          input.push_back('0');
          break;
        case SDL_SCANCODE_1:
          if (input.size() <= 1 && input[0] == '0') {
            input[0] = '1';
            break;
          }
          input.push_back('1');
          break;
        case SDL_SCANCODE_2:
          if (input.size() <= 1 && input[0] == '0') {
            input[0] = '2';
            break;
          }
          input.push_back('2');
          break;
        case SDL_SCANCODE_3:
          if (input.size() <= 1 && input[0] == '0') {
            input[0] = '3';
            break;
          }
          input.push_back('3');
          break;
        case SDL_SCANCODE_4:
          if (input.size() <= 1 && input[0] == '0') {
            input[0] = '4';
            break;
          }
          input.push_back('4');
          break;
        case SDL_SCANCODE_5:
          if (input.size() <= 1 && input[0] == '0') {
            input[0] = '5';
            break;
          }
          input.push_back('5');
          break;
        case SDL_SCANCODE_6:
          if (input.size() <= 1 && input[0] == '0') {
            input[0] = '6';
            break;
          }
          input.push_back('6');
          break;
        case SDL_SCANCODE_7:
          if (input.size() <= 1 && input[0] == '0') {
            input[0] = '7';
            break;
          }
          input.push_back('7');
          break;
        case SDL_SCANCODE_8:
          if (input.size() <= 1 && input[0] == '0') {
            input[0] = '8';
            break;
          }
          input.push_back('8');
          break;
        case SDL_SCANCODE_9:
          if (input.size() <= 1 && input[0] == '0') {
            input[0] = '9';
            break;
          }
          input.push_back('9');
          break;
        case SDL_SCANCODE_LEFT:
          left_right_selection = !left_right_selection;
          break;
        case SDL_SCANCODE_RIGHT:
          left_right_selection = !left_right_selection;
          break;
        case SDL_SCANCODE_UP:
          if (left_right_selection && selected_output_index + 1 < currency_codes.size()) {
            selected_output_index += 1;
          } else if (!left_right_selection && selected_input_index + 1 < currency_codes.size()) {
            selected_input_index += 1;
          }
          break;
        case SDL_SCANCODE_DOWN:
          if (left_right_selection && selected_output_index - 1 >= 0) {
            selected_output_index -= 1;
          } else if (!left_right_selection && selected_input_index - 1 >= 0) {
            selected_input_index -= 1;
          }
          break;
      }
      break;
    default:
      break;
  }

  return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
  // rendering
  RenderBackground(renderer);
  RenderCurrencyLists(renderer);
  RenderListBorders(renderer);
  RenderNumberInput(renderer);
  RenderNumberOutput(renderer);
  RenderDetails(renderer);
  SDL_RenderPresent(renderer);

  return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {}