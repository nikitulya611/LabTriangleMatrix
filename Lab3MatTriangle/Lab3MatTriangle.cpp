#include <iostream>
#include "UpTriangleMatrix.h"
#include <conio.h>

using namespace std;

void inputMatrix(UpTriangleMatrix<double>& m)
{
	int size;
	cout << "Введите размер матрицы: ";
	cin >> size;
	m = UpTriangleMatrix<double>(size);
	cin >> m;
}

int main() {

	setlocale(LC_ALL, "RUS");
	int choose;

	UpTriangleMatrix<double> op1;
	UpTriangleMatrix<double> op2;

	while (true)
	{
		_getch();
		system("cls");
		cout << "1. Ввести 1-ю матрицу\n2. Ввести 2-ю матрицу\n3. Сложение матриц\n4. Вычитание матриц\n5. Умножение матрицы на число\n6. Умножение матриц\n0. Выход\n";
		cin >> choose;

		try {

			switch (choose)
			{
			case 1:
				inputMatrix(op1);
				system("cls");
				cout << op1;
				break;

			case 2:
				inputMatrix(op2);
				system("cls");
				cout << op2;
				break;

			case 3:
				cout << op1 << endl << "+" << endl << endl << op2 << endl << "=" << endl << endl << op1 + op2;
				break;

			case 4:
				cout << op1 << endl << "-" << endl << endl << op2 << endl << "=" << endl << endl << op1 - op2;
				break;

			case 5:
				cout << "Введите число: ";
				int value;
				cin >> value;
				cout << op1 << endl << "*" << endl << endl << value << endl << "=" << endl << endl << op1 * value;
				break;

			case 6:
				cout << op1 << endl << "*" << endl << endl << op2 << endl << "=" << endl << endl << op1 * op2;
				break;

			case 0:
				exit(0);

			default:
				cout << "Некоректный ввод, повторите\n";
				break;
			}
		}
		catch (exception e)
		{
			cout << e.what();
		}
	}

	return 0;
}