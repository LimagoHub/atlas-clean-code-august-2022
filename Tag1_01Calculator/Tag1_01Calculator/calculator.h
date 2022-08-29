#pragma once
#include <stdexcept>
class calculator
{
public:
	virtual auto add(double a, double b) -> double = 0;
	
	virtual auto sub(double a, double b) -> double = 0;
};
 