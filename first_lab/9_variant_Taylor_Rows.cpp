#include <iostream>			//Taylor_Rows
#include <cmath>
using namespace std;


int main()
{
	double epsilon = 0;
	double	previous_term = 1;
	double	amount = 1;
	double	x = 0;
	short int n = 1;
	short int k = 2;


	cout << "Input x (-1 < x < 1): ";
	cin >> x;															//Ââîä çíà÷åíèÿ x
	cout << "Input epsilon (0 < epsilon < 0.01): ";
	cin >> epsilon;														//Ââîä çíà÷åíèÿ epsilon


	if (epsilon <= 0 || epsilon >= pow(10, -k) || x >= 1 || x <= -1)	// Ïðîâåðêà ââåä¸ííûõ çíà÷åíèé
	{																	// åpsilon è õ ïî óñëîâèþ
		cout << "Epsilon does not satisfy condition \n";
		system("pause");
		return 0;
	}


	while (abs(previous_term) >= epsilon)				//Ñðàâíåíèå ñëàãàåìûõ ñ ýïñèëîíîì
	{
		previous_term *= -(2 * n - 1) * x / (2 * n);	//Âû÷èñëåíèå êàæäîãî ñëåäóþùåãî ÷ëåíà ðÿäà Òåéëîðà
		amount += previous_term;						//Ñóììà ÷ëåíîâ ðÿäà Òåéëîðà
		++n;
	}


	cout << "1/sqrt(1+x)=  " << 1 / sqrt(1 + x) << "\t Amount= " << amount << '\n';
	system("pause");				//Ñðàâíåíèå ëåâîé ÷àñòè ôóíêöèè ñ å¸ ïðàâîé ÷àñòüþ, ïðåäñòàâëåííîé â âèäå
	return 0;						//ðÿäà Òåéëîðà.
}
