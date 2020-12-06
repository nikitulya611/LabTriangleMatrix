#include <iostream>
#include "UpTriangleMatrix.h"
#include <conio.h>
#include <ctime>
#include <random>
#include <chrono>
#include <string>
#include <fstream>

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
	ofstream fout;
	fout.open("log.txt");

	for (int i = 1;; i++)
	{
		string iteration = "";
		iteration += to_string(i) + " итерация";

		auto start = chrono::high_resolution_clock::now();

		UpTriangleMatrix<int> m1(i);
		UpTriangleMatrix<int> m2(i);
		m1 + m2;
		m1 * m2;

		auto end = chrono::high_resolution_clock::now();
		auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();

		iteration += "\t" + to_string(elapsed) + "ms\n";
		fout << iteration;
		cout << iteration;		
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