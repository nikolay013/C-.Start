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
			Amount1 = 0;		//��������� ����� ���������, ��� ���������� ����� ��������� 
			Amount2 = 0;		//������ �����.

			for (int b = 1; b < i; b++) //���������� ����� ��������� ������� �����
			{
				if (i % b == 0)
				{
					Amount1 += b;
				}
			}


			if (i < Amount1)			//�.1 �������� ���� ������������� �����, ����� �� ��
			{						//������ � �������� ������� (220 - 284 � 284 - 220)
				if (Amount1 <= N)		//�.2 �������� ������� ��. ����� (��� ������ ������ �������
				{						//������ �� �.1) � �������� ������

				for (int a = 1; a < Amount1; a++) //�.3 ���������� ������� ��.����� ��
				{								//��������, � �� ����� ������ ���� �����
					if (Amount1 % a == 0)			//������� �����
					{							//(������� ��������������� ���� �����)
						Amount2 += a;
					}
				}


				if (Amount2 == i && i != Amount1) //�������� �� ��������������� ���� �����
				{
					cout << "A pair of friendly numbers: " << i << ' ' << Amount1 << '\n';
				}

				}

			}


			}	   //���������� ������������� ���   //���������� ������������� ���
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