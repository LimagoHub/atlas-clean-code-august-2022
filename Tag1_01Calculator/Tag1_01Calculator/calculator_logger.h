#pragma once
#include <iostream>
#include "calculator.h"

class calculator_logger : public calculator
{
	calculator &calc;


public:
	calculator_logger(calculator& calc)
		: calc(calc)
	{
	}

	auto add(double a, double b) -> double override
	{
		std::cout << "Add wurde gerufen" << std::endl;
		return calc.add(a, b);
	}
	auto sub(double a, double b) -> double override
	{
		return calc.sub(a, b);
	}
};
