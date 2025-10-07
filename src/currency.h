#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
#include <vector>

extern std::string input;
extern double input_number;
extern double output;

extern std::vector<std::string> currency_codes;
extern std::vector<double> currency_rates;
extern int selected_input_index;
extern int selected_output_index;

extern bool left_right_selection;

void InitCurrency(std::string token);

#endif