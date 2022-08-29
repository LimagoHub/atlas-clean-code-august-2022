// Tag1_01Calculator.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "calculatorImpl.h"
#include "calculator_logger.h"
#include "calculator_secure.h"
#include "CalcClient.h"

int main()
{
	calculatorImpl calc;
	calculator_logger logger{ calc };
	calculator_secure secure{ logger };
	calculator_logger logger2{ secure };
	calc_client client{ logger2 };

	client.go();

	return 0;
}

