#pragma once
#include <iostream>
#include "calculator.h"

class calculator_secure : public calculator
{
	calculator& calc;


public:
	calculator_secure(calculator& calc)
		: calc(calc)
	{
	}

	auto add(double a, double b) -> double override
	{
		std::cout << "Du kommst hier rein" << std::endl;
		return calc.add(a, b);
	}
	auto sub(double a, double b) -> double override
	{
		return calc.sub(a, b);
	}
};