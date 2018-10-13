#include <iostream>
using namespace std;

int main()
{

	 int N = 0;
	unsigned int Amount1 = 0;
	unsigned int Amount2 = 0;


	cout << "Enter value N: ";
	cin >> N;


	if (N > 0)
	{

		if (N > 283)
		{
			for (int i = 1; i < N; i++)
			{
			Amount1 = 0;		//Обнуление суммы делителей, для вычисления суммы делителей 
			Amount2 = 0;		//других чисел.

			for (int b = 1; b < i; b++) //Вычисление суммы делителей первого числа
			{
				if (i % b == 0)
				{
					Amount1 += b;
				}
			}


			if (i < Amount1)			//П.1 Проверка пары дружественных чисел, чтобы их не
			{						//вывело в обратном порядке (220 - 284 и 284 - 220)
				if (Amount1 <= N)		//П.2 Проверка второго др. числа (оно всегда больше первого
				{						//исходя из П.1) с условием задачи

				for (int a = 1; a < Amount1; a++) //П.3 Разложение второго др.числа на
				{								//делители, и их сумма должна быть равна
					if (Amount1 % a == 0)			//первому числу
					{							//(Принцип дружественности двух чисел)
						Amount2 += a;
					}
				}


				if (Amount2 == i && i != Amount1) //Проверка на дружественность двух чисел
				{
					cout << "A pair of friendly numbers: " << i << ' ' << Amount1 << '\n';
				}

				}

			}


			}	   //вычисление дружественных пар   //вычисление дружественных пар
		}
		else
		{
			if (N < 284)
			{
				cout << "For the number " << N << ' ' << "there are no friendly pairs\n";
			}
		}
	}
	else
	{
		cout << "Value N less then 0 \n";
	}


	system("pause");
	return 0;
}