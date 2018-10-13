#include <iostream>
#include <ctime>
using namespace std;

int main() {
	const int array_size = 10;
	double arr[array_size] = {};
	int choice = 0;
	double left_border = 0;
	double right_border = 0;
	double P = 0;
	cout << "1-Manual input of massive elements, 2 - Automatic filling of massive elements\n";
	cin >> choice; //����� ������� ����� ��������� �������



	switch (choice)
	{
	case 1:
		for (int i = 0; i < array_size; i++)
		{
			cout << "arr[" << i << "]: ";
			cin >> arr[i];
		}
		break;


	case 2:
		cout << "Enter the left border a: ";			//���� ��������� ��� ��������� ��������� �������
		cin >> left_border;
		cout << "Enter the right border b: ";
		cin >> right_border;

		if (left_border >= right_border)				//�������� �� ��, ����� ����� ������� �������
		{												//���� ������ ������ ������� �������
			cout << "The left border of the massive is greater than the right boundary. \n";
			system("pause");
			return 0;
		}
		srand(time(NULL));
		for (int i = 0; i < array_size; i++)	//��������� ��������� ��������� �������
		{
			arr[i] = rand()*(right_border - left_border) / RAND_MAX + left_border;
		}
		for (int i = 0; i < array_size; i++)
		{
			cout << arr[i] << '\n';
		}
		break;


	default:		//�� ������ ����� �����, �������� �� 1 � 2.
	{
		cout << "Uncorrect choise\n";
		system("pause");
		return 0;
	}
	}

	//---------------------------------------------------------------------------------------------------

	cout << "\tUnit 1\n";
	cout << "Enter P: ";
	cin >> P;
	int count = 0;
	for (int i = 0; i < array_size; i++)
	{
		if (arr[i] < P) //������� count ���-�� ��������� �������, ������� ��� P.
		{
			count++;
		}
	}
	cout << "The number of elements in the massive that are less than the number " << P << ' ' << count << '\n';

	//---------------------------------------------------------------------------------------------------

	cout << "\tUnit 2\n";
	int index = array_size;		//(0=array_size)
	int amount = 0;


	for (int i = 0; i < array_size; i++)
	{
		if (arr[i] < 0) //���������� ���������� �������������� ��������
		{
			index = i;
		}
	}


	if (index == array_size) //�������� �� ���������� ������������� ��������� �������
	{
		cout << "There are no negative elements of the massive \n";
	}
	else
	{
		for (int i = index + 1; i < array_size; i++)
		{
			amount += (int)arr[i];				//���������� ����� ����� ������ ��������� �������,
		}										//����� ���������� �������������� �����
		cout << "The sum of the whole parts of the massive elements after the last negative number: " << amount << '\n';
	}


	if (count != 0)
	{
		int newIndex = 0;
		double value = 0;
		for (int i = 0; i < array_size; i++)
		{
			if (arr[i] < P)		//������������ ���������, ������� ��� P, � ������ ������
			{					//��� ��������� ������� ���������� ��������� �����
				value = arr[i];
				for (int g = i; g >= newIndex; g--)
				{
					arr[g] = arr[g - 1];
				}
				arr[newIndex] = value;
				newIndex++;
			}
		}

		for (int i = 0; i < array_size; i++)
		{
			cout << arr[i] << '\n';
		}
	}
	else
	{
		cout << "There are no numbers less than the number P.\n";
	}

	system("pause");
	return 0;
}