#pragma once
#include "frac.h"
/// <summary>
/// Класс калькулятора. Работает с внутренними значениями.
/// </summary>
class Calc
{
private:
	/// <summary>
	/// Значение слева оператора
	/// </summary>
	Frac value1;
	/// <summary>
	/// Значение справа оператора
	/// </summary>
	Frac value2;
	/// <summary>
	/// Операция
	/// </summary>
	char operation;

public:
	/// <summary>
	/// Устанавливает операцию в калькуляторе
	/// </summary>
	/// <param name="op">Одна из операций: '+', '-', '*', '/'</param>
	/// <returns>Установлена ли операция (true/false)</returns>
	bool setOperation(const char op);

	/// <summary>
	/// Устанавливает первое значение в калькуляторе
	/// </summary>
	/// <param name="value">Дробное значение</param>
	void setValue1(const Frac value);
	/// <summary>
	/// Устанавливает второе значение в калькуляторе
	/// </summary>
	/// <param name="value">Дробное значение</param>
	void setValue2(const Frac value);

	/// <summary>
	/// Вычисляет заданную операцию
	/// </summary>
	/// <returns>Дробь с результатом вычислений</returns>
	Frac execute() const;
};

