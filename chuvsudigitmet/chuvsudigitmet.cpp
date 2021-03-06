// chuvsudigitmet.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

inline double func(double x)
{
	return x * x * x * x * x - x - 2;
}

inline double pfunc(double x)
{
	return 5 * x * x * x * x - 1;
}

void half(double *a, double *arh, double *b, double *brh, double e, int n)
{
	for (int i = 0; i < n; i++)
	{
		double ax, bx, cx, aa, cc;
		ax = a[i];
		bx = b[i];
		while (abs(ax - bx) >= 2 * e)
		{
			cx = (ax + bx) / 2;
			aa = func(ax);
			cc = func(cx);
			if (aa > 0 && cc > 0 || aa < 0 && cc < 0) ax = cx;
			else bx = cx;
		}
		arh[i] = ax;
		brh[i] = bx;
	}
}

void neuton(double *x, double *xrn, double e, int n)
{
	for (int i = 0; i < n; i++)
	{
		double x0;
		do
		{
			x0 = x[i];
			x[i] = x[i] - (func(x[i]) / pfunc(x[i]));
		} while (abs(x[i] - x0) >= e);
		xrn[i] = x[i];
	}
}

void sek(double *x0, double *x1, double *xrs, double e, int n)
{
	for (int i = 0; i < n; i++)
	{
		do
		{
			xrs[i] = x1[i] - (func(x1[i]) * (x1[i] - x0[i]) / (func(x1[i]) - func(x0[i])));
			x0[i] = x1[i];
			x1[i] = xrs[i];
		} while (abs(xrs[i] - x0[i]) >= e);
	}
}

int main()
{
	int start = clock();
	int n;
	double *a, *b, *x, *x0, *x1, *arh, *brh, *xrn, *xrs, e;
	/*cout << "pogreshnost'" << endl;
	cin >> e;
	cout << "kol-vo otrezkov" << endl;
	cin >> n;*/
	e = 0.00001;
	n = 1;
	a = new double[n];
	b = new double[n];
	x = new double[n];
	x0 = new double[n];
	x1 = new double[n];
	arh = new double[n];
	brh = new double[n];
	xrn = new double[n];
	xrs = new double[n];
	/*for (int i = 0; i < n; i++)
	{
		cout << "koord nachala i konca" << endl;
		cin >> a[i];
		cin >> b[i];
	}*/
	a[0] = -10;
	b[0] = 10;
	x[0] = 2;
	x0[0] = 1;
	x1[0] = 2;
	half(a, arh, b, brh, e, n);
	neuton(x, xrn, e, n);
	sek(x0, x1, xrs, e, n);
	for (int i = 0; i < n; i++)
	{
		cout << "koren' v promezhutke" << endl;
		cout << arh[i] << endl;
		cout << brh[i] << endl;
		cout << "priblizh koren'" << endl;
		cout << xrn[i] << endl;
		cout << "priblizh koren' (sek)" << endl;
		cout << xrs[i] << endl;
	}
	int end = clock();
	cout << "zatracheno " << end - start << endl;
	system("pause");
	return 0;
}

