#pragma once

#include "calculator.h"


class calculatorImpl: public calculator
{
public:
	auto add(double a, double b) -> double override
	{
		
		return a + b;
	}

	auto sub(double a, double b) -> double override
	{
		return add(a, -b);
	}
};

