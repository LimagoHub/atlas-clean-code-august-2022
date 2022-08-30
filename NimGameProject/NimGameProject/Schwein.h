#pragma once
#include <string>
class Schwein
{

	std::string name;
	int gewicht;
	void set_gewicht(const int gewicht)
	{
		this->gewicht = gewicht;
	}

public:


	Schwein(const std::string& name = "nobody")
		: name(name), gewicht(10)
	{
	}

	std::string get_name() const
	{
		return name;
	}

	void set_name(const std::string& name)
	{
		this->name = name;
	}

	int get_gewicht() const
	{
		return gewicht;
	}

	void fuettern()
	{
		set_gewicht(get_gewicht() + 1);
	}
};

