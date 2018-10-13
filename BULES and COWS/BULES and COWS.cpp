// BULES and COWS.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "math.h"
#include "iostream"
#include "locale.h"

int num = 1347;

int nCount(int n, int k) {	
	return (n / (int)pow(10, k) % 10);
}

int nBulles(int player_step) {
	int sum = 0;
	int i = 0;
	for (i = 0; i < 4; i++) {
		if (nCount(player_step, i) == nCount(num, i))
			sum++;
	}
	return sum;
}

int nCows(int player_step) {
	int cows = 0;
	int i;
	int g;
	for (i = 0; i < 4; i++) {
		for (g = 0; g < 4; g++); {
			if (nCount(player_step, i) == nCount(num, g) && i != g)
				cows++;
		}
	}
	return cows;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a = 0;
	std::cin >> a;

	std::cout << "Коров: ";
	std::cout << nCows(a);
	std::cout << "\n";
	std::cout << "Быков: ";
	std::cout << nBulles(a);
	std::cout << "\n";
	


	std::cin >> a;
    return 0;
}

