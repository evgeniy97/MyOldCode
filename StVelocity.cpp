// StVelocity.cpp: определяет точку входа для консольного приложения.
//

// 31/01/2018

#include "stdafx.h"
#include "fstream"
#include "numeric"
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector> // <--- Теперь будем использовать вектор. Потому что вектор всегда поможет
//#include "iostream" // <--- Убрать
#include "thread" // <-- Чтобы распараллелить 
#include "string"
#include <direct.h> // <-- mkdir(("Result width p = " + P).c_str());


template <class T>
double Mean(const std::vector<T> data) {
	return std::accumulate(data.begin(), data.end(), 0.0f) / data.size();
}

template <class T>
double StandartDevesition(std::vector<T> data, double mean)
{
	std::transform(data.begin(), data.end(), data.begin(), std::bind2nd(std::minus<float>(), mean)); // <--- Вычитаем из каждого элемента среднее
	float deviation = std::inner_product(data.begin(), data.end(), data.begin(), 0.0f); // <-- Предтсавляем числитель нашей формулы как скалярное произведение
	return std::sqrt(deviation / (data.size() - 1)); // <-- Берем корень
}

struct Step {
	size_t StepNumber = 0;
	double Minimum = 0;
	double ErrorMinimum = 0;
	double Max = 0;
	double ErrorMax = 0;
	double Average = 0;
	double ErrorAverage = 0;
	double Width = 0;
	double ErrorWidth = 0;
	double Utilization = 0;
	double ErrorUtilization = 0;
public:
	friend std::istream& operator >> (std::istream& os, Step& oqject);
};

std::istream & operator >> (std::istream & os, Step & step)
{
	os >> step.StepNumber >> step.Minimum >> step.ErrorMinimum >>
		step.Max >> step.ErrorMax >> step.Average >> step.ErrorAverage >>
		step.Width >> step.ErrorWidth >> step.Utilization >> step.ErrorUtilization;
	return os;
}


const std::string p[] = {"0","0.001","0.01","0.05","0.1","0.2"}; // <-- Каие значения p у нас использовались
const size_t StepsNumber = 100000;

int Function(std::string p)
{
	_mkdir(("Min(t)/p = " + p).c_str());
	_mkdir(("Max(t)/p = " + p).c_str());
	_mkdir(("Average(t)/p = " + p).c_str());
	_mkdir(("Width(t)/p = " + p).c_str());
	_mkdir(("Utilization(t)/p = " + p).c_str());

	std::ofstream info("info/" + p + ".txt");

	std::ofstream VelocityMinOut("Min(q)/p =" + p + " Velocity(q) MIN.txt");
	std::ofstream VelocityMaxOut("Max(q)/p =" + p + " Velocity(q) MAX.txt");
	std::ofstream VelocityAverageOut("Average(q)/p =" + p + " Velocity(q) AVERAGE.txt");
	std::ofstream WidthOut("Width(q)/p =" + p + " Width(q).txt");
	std::ofstream UtilizationOut("Utilization(q)/p =" + p + "Utilization.txt");

	for (double q = 0.1; q < 1.0; q += 0.01) {
		std::ifstream from("p = " + p + "/result" + std::to_string(q) + ".txt");
		info << ("result" + std::to_string(q) + ".txt") << std::endl;
		if (from.is_open()) {
			// Инициализация необходимых массивов
			std::vector <double> Minimum;
			std::vector <double> Max;
			std::vector <double> Average;
			std::vector <double> Width;
			std::vector <double> Utilization;
			//
			// Чтение
			{
				Step step;
				// Тут инициализовать куда записать зависимости от t
				std::ofstream toMinimum("Min(t)/p = " + p + "/q = " + std::to_string(q) + ".txt");
				std::ofstream toMax("Max(t)/p = " + p + "/q = " + std::to_string(q) + ".txt");
				std::ofstream toAverage("Average(t)/p = " + p + "/q = " + std::to_string(q) + ".txt");
				std::ofstream ToWidth("Width(t)/p = " + p + "/q = " + std::to_string(q) + ".txt");
				std::ofstream ToUtilization("Utilization(t)/p = " + p + "/q = " + std::to_string(q) + ".txt");
				//
				for (size_t j = 0; j < StepsNumber; j++) {
					from >> step;
					// Тут выписываем зависимотси от t
					toMinimum << step.StepNumber << " " << step.Minimum << " " << step.ErrorMinimum << std::endl;
					toMax << step.StepNumber << " " << step.Max << " " << step.ErrorMax << std::endl;
					toAverage << step.StepNumber << " " << step.Average << " " << step.ErrorAverage << std::endl;
					ToWidth << step.StepNumber << " " << step.Width << " " << step.ErrorWidth << std::endl;
					ToUtilization << step.StepNumber << " " << step.Utilization << " " << step.ErrorUtilization << std::endl;

					Minimum.push_back(step.Minimum);
					Max.push_back(step.Max);
					Average.push_back(step.Average);
					Width.push_back(step.Width);
					Utilization.push_back(step.Utilization);
				}

				toMinimum.close();
				toMax.close();
				toAverage.close();
				ToWidth.close();
				ToUtilization.close();
			}
			from.close();
			//
			// Обрабатываем массивы c тау, чтобы получить скорость
			std::adjacent_difference(Minimum.begin(), Minimum.end(), Minimum.begin()); // Получаем разность между элементами t + 1 и t
			std::adjacent_difference(Max.begin(), Max.end(), Max.begin());
			std::adjacent_difference(Average.begin(), Average.end(), Average.begin());
			// 
			// Надо убрать первые 500 значений
			Minimum.erase(Minimum.begin(), Minimum.begin() + 500);
			Max.erase(Max.begin(), Max.begin() + 500);
			Average.erase(Average.begin(), Average.begin() + 500);
			// Поменять стандартный вывод на свой 
			{
				double MeanMinimum = Mean(Minimum);
				VelocityMinOut << q << " " << MeanMinimum << " " << StandartDevesition(Minimum, MeanMinimum) << std::endl;

				double MeanMax = Mean(Max);
				VelocityMaxOut << q << " " << MeanMax << " " << StandartDevesition(Max, MeanMax) << std::endl;

				double MeanAverage = Mean(Average);
				VelocityAverageOut << q << " " << MeanAverage << " " << StandartDevesition(Average, MeanAverage) << std::endl;

				double MeanWidth = Mean(Width);
				WidthOut << q << " " << MeanWidth << " " << StandartDevesition(Width, MeanWidth) << std::endl;

				double MeanUtilization = Mean(Utilization);
				UtilizationOut << q << " " << MeanUtilization << " " << StandartDevesition(Utilization, MeanUtilization) << std::endl;

			}
		}
	}
	info.close();
	VelocityMinOut.close();
	VelocityMaxOut.close();
	VelocityAverageOut.close();
	WidthOut.close();
	UtilizationOut.close();
	return 0;
}

int main() {
	std::ios_base::sync_with_stdio(false); // <-- Для ускорения работы программы

	_mkdir("info");

	_mkdir("Min(t)");
	_mkdir("Max(t)");
	_mkdir("Average(t)");
	_mkdir("Width(t)");
	_mkdir("Utilization(t)");
	_mkdir("Min(q)");
	_mkdir("Max(q)");
	_mkdir("Average(q)");
	_mkdir("Width(q)");
	_mkdir("Utilization(q)");

	std::thread P0(Function, p[0]);
	std::thread P1(Function, p[1]);
	std::thread P2(Function, p[2]);
	std::thread P3(Function, p[3]);
	std::thread P4(Function, p[4]);
	std::thread P5(Function, p[5]);

	P0.join();
	P1.join();
	P2.join();
	P3.join();
	P4.join();
	P5.join();
}