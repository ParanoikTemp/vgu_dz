#include "calc.h"

bool Calc::setOperation(const char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/') {
		operation = op;
		return true;
	}
	return false;
}

void Calc::setValue1(const Frac value)
{
	value1 = value;
}

void Calc::setValue2(const Frac value)
{
	value2 = value;
}

Frac Calc::execute() const
{
	if (operation == '+') return value1 + value2;
	if (operation == '-') return value1 - value2;
	if (operation == '*') return value1 * value2;
	if (operation == '/') return value1 / value2;
	return Frac();
}
