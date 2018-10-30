#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;				//9_variant



double function1(double);
double function2(double);
double function3(double);


int methodChoice();

double left_rect(double (*ptr)(double),float leftbord, float rightbord,double eps);
double method_simpson(double(*ptr)(double), float leftbord, float rightbord, double eps);

void line(char, short);

int n = 4;
const double PI = M_PI;


int main()
{
	while (true)
	{
		line('*', 40);
		int choice = 0;
		cout << "\nEnter your function:\n";
		cout << "1 - sqrt(2^x-1)\n";
		cout << "2 - (x^2-1)*10^(-2x)\n";
		cout << "3 - tan^3(x/2 + Pi/4)\n";
		cout << "4 - exit\n";
		cout << "Your choice: "; 
		cin >> choice;
		if (choice == 4)
		{
			break;
		}
		else
		{
			if(choice < = 0 || choice > 4)
			{
				cout << "\nIncorrected choice\n";
				system("pause");
				return 0;
			}
		}

		short k = 0;
		double epsilon = 0;
		cout << "Enter your k for epsilon (10^(-k)) : ";
		cin >> k; k++;
		epsilon = pow(10, -k);


		float left_border = 0;
		float right_border = 0;

		if (k <= 0)
		{
			cout << "\nIncorrected k.\n";
			system("pause");
			break;
		}
		


		switch (choice)
		{


			case 1:
			{
				left_border = 0.3;
				right_border = 1;
					
				int method = methodChoice();
				switch (method)
				{
					case 1:
					{
					double(*ptr)(double) = NULL;
					ptr = &function1;
					double inthegral = left_rect(ptr, left_border, right_border, epsilon);
					cout << "Inthegral is: " << inthegral << " = " << 0.52507329 << '\n';
					break;
					}	
	
					case 2:
					{
					double(*ptr)(double) = NULL;
					ptr = &function1;
					double inthegral = method_simpson(ptr, left_border, right_border, epsilon);
					cout << "Inthegral is: " << inthegral << " = " << 0.52507329 << '\n';
					break;
					}

					default:
					{
					cout << "Incorrected input, try again.\n";
					break;
					}
				}
			break;
			}



			case 2:
			{
				left_border = 0;
				right_border = 0.4;
	
				int method = methodChoice();
				switch (method)
				{
					case 1:
					{
					double(*ptr)(double) = NULL;
					ptr = &function2;
					double inthegral = left_rect(ptr, left_border, right_border, epsilon);
					cout << "Inthegral is: " << inthegral << " = " << -0.17698412 << '\n';
					break;
					}

					case 2:
					{
					double(*ptr)(double) = NULL;
					ptr = &function2;
					double inthegral = method_simpson(ptr, left_border, right_border, epsilon);
					cout << "Inthegral is: " << inthegral << " = " << -0.17698412 << '\n';
					break;
					}

					default:
					{
					cout << "Incorrected input, try again.\n";
					break;
					}
				}
			break;
			}


			case 3:
			{
				left_border = 0;
				right_border = PI / 4;
			
				int method = methodChoice();
				switch (method)
				{
					case 1: 
					{
					double(*ptr)(double) = NULL;
					ptr = &function3;
					double inthegral = left_rect(ptr, left_border, right_border, epsilon);
					cout << "Inthegral is: " << inthegral << " = " << 3.6004799 << '\n';
					break;
					}

					case 2:
					{
					double(*ptr)(double) = NULL;
					ptr = &function3;
					double inthegral = method_simpson(ptr, left_border, right_border, epsilon);
					cout << "Inthegral is: " << inthegral << " = " << 3.6004799 << '\n';
					break;
					}

					default:
					{
					cout << "Incorrected input, try again.\n";
					break;
					}
				}
			break;
			}

			default:
			{
			cout << "\nIncorrected input, try again.\n";
			break;
			}
		}
	}
}

void line(char star, short n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << star;
	}
	cout << endl;
}

double function3(double x)
{
	return pow(tan(x/2 +PI/4),3);
}
double function2(double x)
{
	return (pow(x, 2) - 1)*(pow(10, -2 * x));
}
double function1(double x)
{
	return sqrt(pow(2, x) - 1);
}

int methodChoice()
{
	int method = 0;
	cout << "\n\tChoice method: \n";
	cout << "1 - Left Rectangle Method\n";
	cout << "2 - Simpson Method (Parabolic Trapezium)\n";
	cout << "Your choice: ";
	cin >> method;
	cout << endl;
	return method;
}

double left_rect(double(*ptr)(double), float leftbord, float rightbord, double eps)
{
	double inthegral = 0;
	double inthegral2 = 0;
	double h = (rightbord - leftbord) / n;

	while (true)
	{
		for (double i = leftbord; i < rightbord; i += h)
		{
			inthegral += ptr(i);
		}


		inthegral *= h;
		printf("%.10f\n", inthegral);
		

		if (abs(inthegral - inthegral2) <= eps || inthegral == inthegral2)
		{
			break;
		}
		else
		{
			n *= 2;
			h = (rightbord - leftbord) / n;
			inthegral2 = inthegral;					//save value of the inthegral in inthegral2
		}
	}

	cout << "\nNumber of divisions: " << n << '\n';
	return inthegral2;
}
double method_simpson(double(*ptr)(double), float leftbord, float rightbord, double eps)
{
	double inthegral = 0;
	double inthegral2 = 0;
	double h = (rightbord - leftbord) / n;

	while (true)
	{
		for (double i = leftbord; i < rightbord; i += h)
		{
			inthegral +=(ptr(i) + 4 * ptr((i+i+h) / 2) + ptr(i + h));
		}

		inthegral *= (h/6);
		printf("%.10f\n", inthegral);

		if (abs(inthegral - inthegral2) <= eps || inthegral == inthegral2)
		{
			break;
		}
		else
		{
			n *= 2;
			h = (rightbord - leftbord) / n;
			inthegral2 = inthegral;					//save value of the inthegral in inthegral2
		}
	}


	cout << "\nNumber of divisions: " << n << '\n';
	return inthegral2;
}
