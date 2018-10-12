
#include <iostream>
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
	cin >> x;															//���� �������� x
	cout << "Input epsilon (0 < epsilon < 0.01): ";
	cin >> epsilon;														//���� �������� epsilon


	if (epsilon <= 0 || epsilon >= pow(10, -k) || x >= 1 || x <= -1)	// �������� �������� ��������
	{																	// �psilon � � �� �������
		cout << "Epsilon does not satisfy condition \n";
		system("pause");
		return 0;
	}


	while (abs(previous_term) >= epsilon)				//��������� ��������� � ���������
	{
		previous_term *= -(2 * n - 1) * x / (2 * n);	//���������� ������� ���������� ����� ���� �������
		amount += previous_term;						//����� ������ ���� �������
		++n;
	}


	cout << "1/sqrt(1+x)=  " << 1 / sqrt(1 + x) << "\t Amount= " << amount << '\n';
	system("pause");				//��������� ����� ����� ������� � � ������ ������, �������������� � ����
	return 0;						//���� �������.
}
