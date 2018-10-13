#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int main()

{
	const int array_size = 10;
	double arr[array_size] = {};
	double arr2[array_size] = {};
	int choice = 0;
	double left_border = 0;
	double right_border = 0;
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
		for (int i = 0; i < array_size; i++)
		{												//��������� ��������� ��������� �������
			arr[i] = rand()*(right_border - left_border) / RAND_MAX + left_border;
		}
		for (int i = 0; i < array_size; i++)
		{
			cout << arr[i] << '\n';
			arr2[i] = arr[i];
		}
		break;


	default:		//�� ������ ����� ������ ����, �������� �� 1 � 2.
	{
		cout << "Uncorrect choise\n";
		system("pause");
		return 0;
	}
	}

	for (int i = 0; i < array_size; i++)
	{
		arr2[i] = arr[i]; //������� �������� ��������� ������� �������
	}						//� ��������� ������� �������
	//--------------------------------------------------------------------------------------------------

	cout << "\tUnit one\n";
	int indexMax = 0;
	double max = arr[0];
	int indexMin = 0;
	double min = arr[0];
	for (int i = 0; i < array_size; i++)
	{
		if (arr[i] > max)	//���������� ������������� �������� �������
		{
			max = arr[i];
			indexMax = i;	//����������� ������������� ������� �������
		}
		if (arr[i] < min)
		{
			min = arr[i];	//���������� ������������ �������� �������
			indexMin = i;	//����������� ������� ������������ �������� �������
		}
	}
	cout << "max value is: " << max << ' ' << "\tindexMax is: " << indexMax << '\n';
	cout << "min value is: " << min << ' ' << "\tindexMin is: " << indexMin << '\n';

	if (abs(indexMin - indexMax) == 1 || indexMin - indexMax == 0)	//�������� �� ��������� ������������ � ������������� ���������
	{
		cout << "There are no onher elements between the minimum and maximum elements of the massive\n";
	}
	else
	{
		double proizvedenie = 1;
		if (indexMax > indexMin)	//������������ ����� ����. � ���. ���������� ������� � ��������
		{
			for (int r = indexMin; r < indexMax - 1; r++)
			{
				proizvedenie *= arr[r + 1];
			}
		}
		else
		{
			for (int c = indexMax; c < indexMin - 1; c++)
			{
				proizvedenie *= arr[c + 1];
			}
		}
		cout << "Proizvedenie ravno: " << proizvedenie << '\n';
	}

	//---------------------------------------------------------------------------------------------------
	cout << "\tUnit two\n";
	int N = 0;
	cout << "Enter N: ";
	cin >> N;


	if (N <= 0)
	{
		cout << "Uncorrected input N" << '\n';	//�������� �������� ����� N
	}


	int size_two = array_size;


	for (int i = 0; i < N; i++)
	{
		min = arr[0];
		for (int i = 0; i < size_two; i++)
		{
			if (arr[i] <= min)		//���� ��� ���������� ������������ �������� �������
			{
				min = arr[i];
				indexMin = i;
			}
		}
		for (int min_elem = indexMin; min_elem < size_two - 1; min_elem++)
		{
			arr[min_elem] = arr[min_elem + 1];	//�������� ��������� ������� �����.
		}						//������ 10-N ��������� ������� ����� �������������
		size_two--;
	}

	for (int i = 0; i < size_two; i++)
	{
		cout << arr[i] << '\n';
	}
	//-----------------------------------------------------------------------------------
	cout << "\tUnit three" << '\n';

	double temp = 0;

	for (int b = 0; b < array_size; b++)
	{
		for (int i = 0; i < array_size - b - 1; i++)	//���������� ���������
		{
			if (abs(arr2[i]) > abs(arr2[i + 1]))
			{
				temp = arr2[i + 1];
				arr2[i + 1] = arr2[i];
				arr2[i] = temp;
			}
		}
	}

	for (int i = 0; i < array_size; i++)
	{
		cout << arr2[i] << '\n';
	}

	system("pause");
	return 0;
}