#pragma once
class Stopwatch
{
public:
	virtual void start() = 0;
	virtual void stop() = 0;

	virtual unsigned long durationInMillis();
};

