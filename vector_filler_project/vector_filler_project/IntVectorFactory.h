#pragma once
#include <vector>

class IntVectorFactory
{

public:
	virtual auto create() const -> std::vector<int> = 0;
};

