#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
#include <vector>
#include <map>

extern float input;
extern float output;

extern std::string selected_input_currency;
extern std::string selected_output_currency;

std::string base;
std::map<std::string, float> rates;

#endif