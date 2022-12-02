#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>

// funkcja calkowana
double f(double x, int fun_no)
{
	if(fun_no == 1)
		return x * x; 
	else if (fun_no == 2)
		return sin(x);
}

int main(int argc, char* argv[])
{
	double xp = 0;
	double xk = 0;
	int N = 0;
	double xi = 0;
	double dx = 0;
	double pp1 = 0; // pole prostokata jednostkowego
	//double pt1 = 0; // pole trapezu jednostkowego
	int fun_no = 0; // numer funkcji (bedzie ich wiele)

	fflush(stdin);

	do
	{
		int error;
		printf("Podaj xp: ");
		error = scanf_s("%lf", &xp);
		if (error == 0)
			return -1;
		printf("\nPodaj xk: ");
		error = scanf_s("%lf", &xk);
		if (error == 0)
			return -1;
		printf("\nPodaj N: ");
		error = scanf_s("%d", &N);
		if (error == 0)
			return -1;
		printf("\n Podaj numer funkcji: 1-x^2, 2-sin(x)...");
		error = scanf_s("%d", &fun_no);
		if (error == 0)
			return -1;

		if (xp > xk)
		{
			return -1;
		}


		// Metoda
		dx = (xk - xp) / N; // szerokosc przedzialu

		for (int i = 1; i <= N; i++)
		{
			xi = xp + i * dx;
			pp1 += f(xi, fun_no) * dx;
		}
		printf("Dla N=%.2d, xp=%.2lf, xk=%.2lf -> wynik=%.4lf\n", N, xp, xk, pp1);

		printf("Jeszcze raz? Jeśli nie - naciśnij n \n");
		pp1 = 0;
	} while (_getch() != 'n');

	return 0;
}


// fajne linki: https://eduinf.waw.pl/inf/alg/004_int/0002.php
