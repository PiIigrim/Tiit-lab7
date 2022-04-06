#pragma once
#include <math.h>
#include <iostream>
#include <ctime>
double w0down(double w0, double a0) {
	double rnd = (double)((-1 * pow(10, 4) + rand() % (int)(0 * pow(10, 4) - -1 * pow(10, 4))) / pow(10, 4));
	w0 = w0 + a0 * rnd;
	double c = (double)((0.75 * pow(10, 4) + rand() % (int)(0.999 * pow(10, 4) - 0.75 * pow(10, 4))) / pow(10, 4));
	a0 = a0 * c;
	return w0;
}
double w1down(double w1, double a0) {
	double rnd = (double)((-1 * pow(10, 4) + rand() % (int)(0 * pow(10, 4) - -1 * pow(10, 4))) / pow(10, 4));
	w1 = w1 + a0 * rnd;
	double c = (double)((0.75 * pow(10, 4) + rand() % (int)(0.999 * pow(10, 4) - 0.75 * pow(10, 4))) / pow(10, 4));
	a0 = a0 * c;
	return w1;
}
double w2down(double w2, double a0) {
	double rnd = (double)((-1 * pow(10, 4) + rand() % (int)(0 * pow(10, 4) - -1 * pow(10, 4))) / pow(10, 4));
	w2 = w2 + a0 * rnd;
	double c = (double)((0.75 * pow(10, 4) + rand() % (int)(0.999 * pow(10, 4) - 0.75 * pow(10, 4))) / pow(10, 4));
	a0 = a0 * c;
	return w2;
}
double w3down(double w3, double a0) {
	double rnd = (double)((-1 * pow(10, 4) + rand() % (int)(0 * pow(10, 4) - -1 * pow(10, 4))) / pow(10, 4));
	w3 = w3 + a0 * rnd;
	double c = (double)((0.75 * pow(10, 4) + rand() % (int)(0.999 * pow(10, 4) - 0.75 * pow(10, 4))) / pow(10, 4));
	a0 = a0 * c;
	return w3;
}
