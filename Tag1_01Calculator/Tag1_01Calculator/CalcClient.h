#pragma once
#include <iostream>
#include "calculator.h"

class calc_client
{
	calculator& calc;


public:
	calc_client(calculator& calc)
		: calc(calc)
	{
	}

	void go()
	{
		std::cout << calc.add(3, 7) << std::endl;
	}
};
