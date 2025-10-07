#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
#include <vector>
#include <map>

extern std::string input;
extern double input_number;
extern double output;

extern std::string selected_input_currency;
extern std::string selected_output_currency;

extern std::string base;
extern std::map<std::string, double> rates;

extern bool left_right_selection;

void InitCurrency(std::string token);

#endif