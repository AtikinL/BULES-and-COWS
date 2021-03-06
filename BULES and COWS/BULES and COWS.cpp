// BULES and COWS.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "math.h"
#include "iostream"
#include "locale.h"

int num = 1347;

int nCount(int n, int k) {	
	return ((n / (int)pow(10, k)) % 10);
}

int nBulls(int player_step, int num) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (nCount(player_step, i) == nCount(num, i))
			sum++;
	}
	return sum;
}

int nCows(int player_step, int num) {
	int sum1 = 0;
	for (int i = 0; i < 4; i++) {
		for (int g = 0; g < 4; g++) {
			if (nCount(player_step, i) == nCount(num, g) && i != g)
				sum1++;
		}
	}
	return sum1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a = 0;
	int step = 1;
	std::cout << "ИГРА БЫКИ и КОРОВЫ";
	std::cout << "\n";
	std::cout << "Твоя задача угадать число заданное компьютером.(четырёхзначное число).";
	std::cout << "\n";
	std::cout << "Если ты угадал цифру и она стоит на своём месте - это БЫК.";
	std::cout << "\n";
	std::cout << "Если ты угадал цифру, но она НЕ стоит на своём метсе - это КОРОВА.";
	std::cout << "\n";
	std::cout << "Когда ты наберёшь 4 БЫКОВ - ТЫ ПОБЕДИЛ. Начнём? ";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "Введите число: ";
	std::cin >> a;

	while (nBulls(a, num) != 4) {
		std::cout << "Коров: ";
		std::cout << nCows(a, num);
		std::cout << "\n";
		std::cout << "Быков: ";
		std::cout << nBulls(a, num);
		std::cout << "\n";
		std::cout << "Введите число: ";
		std::cin >> a;
		step++;
	}
	std::cout << "Кол-во ходов: ";
	std::cout << step;
	std::cout << "\n";
	std::cout << "YOU WIN!";

	std::cin >> a;
    return 0;
}