#include <iostream>
#include "UpTriangleMatrix.h"
#include <conio.h>
#include <ctime>
#include <random>

using namespace std;

void inputMatrix(UpTriangleMatrix<double>& m)
{
	int size;
	cout << "Введите размер матрицы: ";
	cin >> size;
	m = UpTriangleMatrix<double>(size);
	cin >> m;
}

void Test()
{
	for (int i = 1;; i++)
	{
		cout << i << " итерация" << endl;
		UpTriangleMatrix<int> m1(i);
		UpTriangleMatrix<int> m2(i);
		
		m1 + m2;
		m1 * m2;
	}
}

void initMatrix(UpTriangleMatrix<int>& m, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
		{
			m[i][j] = rand() % 10 + 1;
		}
}

int main() {

	setlocale(LC_ALL, "RUS");
	
	Test();

	return 0;
}