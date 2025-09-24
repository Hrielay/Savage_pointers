#include <iostream>
#include <fstream>

using namespace std;

/*******************************************************************/
/*                П Р О Т О Т И П Ы    Ф У Н К Ц И Й               */
/*******************************************************************/

// запись матрицы из файла с проверками на коррек-сть
void inpMatr(const char* FNAME // имя файла
	, int Matr[N_MAX][M_MAX]
	, int& n
	, int& m);

//вывод эл-тов массива в виде матрицы
void PrintMatr(int Matr[N_MAX][M_MAX]
	, int n
	, int m);

//
void CreateBoolMatr(int Matr[N_MAX][M_MAX]
	, bool BoolMatr[N_MAX][M_MAX]
	, int n
	, int m);
//
void PrintBoolMatr(bool Matr[N_MAX][M_MAX]
	, int n
	, int m);

/*******************************************************************/
/*               О С Н О В Н А Я     П Р О Г Р А М М А             */
/*******************************************************************/

int main() {
	setlocale(LC_ALL, "RUSSIAN");

	int Matr[N_MAX][M_MAX];
	bool BoolMatr[N_MAX][M_MAX];

	int N = 5;
	int M = 6;

	inpMatr("file.txt", Matr, N, M);

	cout << "Исходная матрица 5х6: \n";
	PrintMatr(Matr, N, M);

	CreateBoolMatr(Matr, BoolMatr, N, M);

	cout << "\n Логическая матрица (true or false): \n";
	PrintBoolMatr(BoolMatr, N, M);

	return 0;
}

/**************************************************************/
/*           Р Е А Л И З А Ц И Я   Ф У Н К Ц И Й              */
/**************************************************************/
const int N_MAX = 5;//
const int M_MAX = 6;//константы для второй матрицы
//(их можно опустить и просто брать N и M считанные из файла)

void inpMatr(const char* FNAME,
	int Matr[N_MAX][M_MAX],
	int& n,
	int& m)
{

	ifstream fin(FNAME);
	if (!fin.is_open())
	{
		cout << "Ошибка открытия матрицы" << FNAME << endl;
		exit(1);//выход когда все нормально завершилось
	}
	fin >> n;								// считываем размер строки
	fin >> m;								// считываем размер столбца
	if (n > N_MAX || m > M_MAX || n <= 0 || m <= 0)// проверяем корректность размеров (чтобы было по задаче)
	{
		cout << "Неверные размеры матрицы n = " << n << "m = " << m << endl;
		exit(1);
	}

	for (int i = 0; i < n; i++)            // запись матрицы из файла
	{
		for (int j = 0; j < m; j++)
		{
			fin >> Matr[i][j];
		}
	}
	fin.close();

}

void PrintMatr(int Matr[N_MAX][M_MAX], int n, int m)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "  " << Matr[i][j];
		}
		cout << endl;
	}
}

void CreateBoolMatr(int Matr[N_MAX][M_MAX], bool BoolMatr[N_MAX][M_MAX], int n, int m)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			BoolMatr[i][j] = (Matr[i][j] >= 0); //true для положительных false для отрицательных
		}
	}
}

void PrintBoolMatr(bool Matr[N_MAX][M_MAX], int n, int m)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "  " << (Matr[i][j] ? "true" : "false"); // сокр. версия тернарного оператора
															//условие-если да-иначе
		}
		cout << endl;
	}
}

