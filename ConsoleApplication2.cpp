// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Array
{
private:
	int** _array;
	int row;
	int col;

public:
	Array(int** matr = {}, int rowCount = 0, int colCount = 0) : //конструктр с параметрами
		_array(matr), row(rowCount), col(colCount)
	{

	}
	Array(const Array& obj) : _array(obj._array), row(obj.row), col(obj.col) // конструктр копирование
	{

	}
	~Array() // деструктр
	{
		delete[] _array;
	}

	Array* Multiplication(Array m) //умножнение матриц
	{
		int** result = new int* [row];
		for (int i = 0; i < row; i++)
		{
			result[i] = new int[row];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < row; j++)
			{
				result[i][j] = 0;
				for (int k = 0; k < row; k++)
				{
					result[i][j] += _array[i][k] * m._array[k][j];
				}
			}

		}
		return new Array(result, row, col);
	}

	Array* Summation(Array* m) //сложение матриц
	{
		int** result = new int* [row];
		for (int i = 0; i < row; i++)
		{
			result[i] = new int[col];
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				result[i][j] = _array[i][j] + m->_array[i][j];
			}
		}

		return new Array(result, row, col);
	}
	void Print()
	{
		cout << endl << "" << endl;
		for (int r = 0; r < row; r++)
		{
			for (int c = 0; c < col; c++)
			{
				auto temp = _array[r][c];
				cout << temp << " ";
			}
			cout << endl;
		}
	}
};

//вывод мартрицы на экран
void PrintArray(int** matr, int* rowCount, int* colCount)
{
	cout << endl << "" << endl;
	for (int r = 0; r < *rowCount; r++)
	{
		for (int c = 0; c < *colCount; c++)
		{
			auto temp = matr[r][c];
			cout << temp << " ";
		}
		cout << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");

	//выделение памяти под указатели
	int* colCount = new int(0);
	int* rowCount = new int(0);
	//размер матрицы
	cout << "Введите количество строк матрицы:" << endl;
	cin >>* rowCount;
	cout << "Введите количество столбцов матрицы:" << endl;
	cin >>* colCount;
	//выделение памяти под массив
	int** arr = new int* [*rowCount];

	for (int i = 0; i < *rowCount; i++)
	{
		arr[i] = new int[*colCount];
	}
	// ввод массива
	for (int r = 0; r < *rowCount; r++)
	{
		cout << "Введите элементы " << r + 1 << "строки :" << endl;
		for (int c = 0; c < *colCount; c++)
		{
			cin >> arr[r][c];
		}
	}
	// исходный массив
	PrintArray(arr, rowCount, colCount);

	//выделение памяти под указатели
	int* col2Count = new int(0);
	int* row2Count = new int(0);
	//ввод размера матрицы
	cout << "Введите количество строк матрицы:" << endl;
	cin >>* row2Count;
	cout << "Введите количество столбцов матрицы:" << endl;
	cin >>* col2Count;
	//выделение памяти под массив
	int** arr2 = new int* [*row2Count];
	for (int i = 0; i < *row2Count; i++)
	{
		arr2[i] = new int[*col2Count];
	}
	// ввод массива
	for (int r = 0; r < *row2Count; r++)
	{
		cout << "Введите элементы " << r + 1 << "строки:" << endl;
		for (int c = 0; c < *col2Count; c++)
		{
			cin >> arr2[r][c];
		}
	}
	PrintArray(arr2, row2Count, col2Count);

	Array* m1 = new Array(arr, *rowCount, *colCount);
	Array* m2 = new Array(arr2, *row2Count, *col2Count);
	Array* res = new Array();

	if (*rowCount == *row2Count && *colCount == *col2Count) //проверка на одинаковое количество строк и столбцов в матрицах
	{
		cout << "Матрица полученная в результате сложения:" << endl;
		res = m1->Summation(m2);
		res->Print();
		delete res;
	}
	else
	{
		cout << "Сложение выполнить нельзя" << endl;
	}
	if (*rowCount == *col2Count && *colCount == *colCount)
	{
		cout << "Матрица полученная в результате умножения:" << endl;
		res = m1->Multiplication(*m2);
		res->Print();
		delete res;
	}
	else
	{
		cout << "Умножение выполнить нельзя" << endl;
	}
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
