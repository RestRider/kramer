#include<iostream>
#include<Windows.h>
#include<vector>

double opred(double** masiv, double pov, double numb);
double f_neropred(double** nerav);
double f_oprX(double** nerav, int i);
void nahod(double** nerav);

int colstroc = 0;
int colstolb = 0;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	

	while (true)
	{
		std::cout << "\nвведите количкство уровнений в неравенстве:";
		std::cin >> colstroc;
		if (colstroc > 0)
		{
			break;
		}
		else
		{
			std::cout << "ERROR";
		}
	}
	while (true)
	{
		std::cout << "\nвведите максимальное количество x в уровнении:";
		std::cin >> colstolb;
		if (colstolb > 0)
		{
			break;
		}
		else
		{
			std::cout << "ERROR";
		}
	}
	double** nerav = new double* [colstroc];
	for (size_t c = 0; c < colstroc; c++)
	{
		nerav[c] = new double[colstolb+1];
	}


	for (size_t i = 0; i < colstroc; i++)
	{
		for (size_t x = 0; x < colstolb+1; x++)
		{
			if (x < colstolb)
			{
				std::cout << "\nввод " << i + 1 << " уровнения\n";
				std::cout << "\nвведите x" << x + 1 <<" вместе со знаком перед ним:";
				std::cin >> nerav[i][x];
			}
			else
			{
				std::cout << "\nвведите чиму равно это выражение если число отрецательное писать с минусом:";
				std::cin >> nerav[i][x];
			}
		}
	}
	nahod(nerav);

	for (size_t c = 0; c < colstroc; c++)
	{
		delete[] nerav[c];
	}
	delete[] nerav;
}
double opred(double** masiv,double pov,double numb)
{
	if (numb == 3)numb--;
	double scop1=1, scop2=1, scop3;
	if (pov > 1)
	{
		for (size_t i = 0; i < colstroc; i++)
		{
			if (numb == colstolb)numb = 0;
			for (size_t c = 0; c < colstolb; c++)
			{
				if (c = numb)
				{
					scop1 = scop1 * masiv[i][c];
					numb++;

				}
			}
		} 
		if (numb == 1)numb = 2;
		for (size_t i = 0; i < colstroc; i++)
		{
			if (numb - 1 == -1)numb = colstolb;
			for (size_t c = 0; c < colstolb; c++)
			{
				if (c = numb-1)
				{
					scop2 = scop2 * masiv[i][c];
					numb--;

				}
			}
		}
		pov--;
		scop3 = (scop1 - scop2) + opred(masiv, pov,numb+1);
		return scop3;
	}
	else
	{
		for (size_t i = 0; i < colstroc; i++)
		{
			if (numb == colstolb)numb=0;
			for (size_t c = 0; c < colstolb; c++)
			{
				if (c = numb)
				{
					scop1 = scop1 * masiv[i][c];
					numb++;

				}
			}
		}
		if (numb == 1)numb = 2;
		else if (numb == 2)numb = 1;
		for (size_t i = 0; i < colstroc; i++)
		{
			if (numb - 1 == -1)numb = colstolb;
			for (size_t c = 0; c < colstolb; c++)
			{
				if (c = numb - 1)
				{
					scop2 = scop2 * masiv[i][c];
					numb--;

				}
			}
		}
		scop3 = (scop1 - scop2);
		return scop3;
	}

}


double f_neropred(double** nerav)
{
	double** neropred = new double* [colstroc];
	for (size_t c = 0; c < colstroc; c++)
	{
		neropred[c] = new double[colstolb];
	}
	for (size_t i = 0; i < colstroc; i++)
	{
		for (size_t x = 0; x < colstolb; x++)
		{
			neropred[i][x] = nerav[i][x];
		}
	}

	return opred(neropred, colstroc, 0);

	for (size_t c = 0; c < colstroc; c++)
	{
		delete[] neropred[c];
	}
	delete[] neropred;
}
double f_oprX(double** nerav,int i)
{
	double** opredX = new double* [colstroc];
	for (size_t c = 0; c < colstroc; c++)
	{
		opredX[c] = new double[colstolb];
	}
	for (size_t n = 0; n < colstroc; n++)
	{
		for (size_t x = 0; x < colstolb; x++)
		{
			if (x == i)
			{
				opredX[n][x] = nerav[n][colstolb];
			}
			else
			{
				opredX[n][x] = nerav[n][x];
			}
		}
	}

	return opred(opredX, colstroc, 0);

	for (size_t c = 0; c < colstroc; c++)
	{
		delete[] opredX[c];
	}
	delete[] opredX;

}

void nahod(double** nerav)
{
	int i;
	for (i = 0; i < colstroc; i++)
	{
		int a = i;
		std::cout << "X" << i + 1 << " = " << f_oprX(nerav,a) / f_neropred(nerav) ;
	}
}






