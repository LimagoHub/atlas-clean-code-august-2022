#pragma once
#include <iostream>
#include "writer.h"

class console_writer: public writer
{
public:
	void write(std::string message) override
	{
		std::cout << message << std::endl;
	}
};
