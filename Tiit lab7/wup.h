#pragma once
#include <math.h>
#include <iostream>
#include <ctime>
double w0up(double w0, double a1) {
	double rnd = (double)((1 * pow(10, 4) + rand() % (int)(2 * pow(10, 4) - 1 * pow(10, 4))) / pow(10, 4));
	w0 = w0 + a1 * rnd;
	double c = (double)((0.75 * pow(10, 4) + rand() % (int)(0.999 * pow(10, 4) - 0.75 * pow(10, 4))) / pow(10, 4));
	a1 = a1 * c;
	return w0;
}
double w1up(double w1, double a1){
	double rnd = (double)((1 * pow(10, 4) + rand() % (int)(2 * pow(10, 4) - 1 * pow(10, 4))) / pow(10, 4));
	w1 = w1 + a1 * rnd;
	double c = (double)((0.75 * pow(10, 4) + rand() % (int)(0.999 * pow(10, 4) - 0.75 * pow(10, 4))) / pow(10, 4));
	a1 = a1 * c;
	return w1;
}
double w2up(double w2, double a1) {
	double rnd = (double)((1 * pow(10, 4) + rand() % (int)(2 * pow(10, 4) - 1 * pow(10, 4))) / pow(10, 4));
	w2 = w2 + a1 * rnd;
	double c = (double)((0.75 * pow(10, 4) + rand() % (int)(0.999 * pow(10, 4) - 0.75 * pow(10, 4))) / pow(10, 4));
	a1 = a1 * c;
	return w2;
}
double w3up(double w3, double a1) {
	double rnd = (double)((1 * pow(10, 4) + rand() % (int)(2 * pow(10, 4) - 1 * pow(10, 4))) / pow(10, 4));
	w3 = w3 + a1 * rnd;
	double c = (double)((0.75 * pow(10, 4) + rand() % (int)(0.999 * pow(10, 4) - 0.75 * pow(10, 4))) / pow(10, 4));
	a1 = a1 * c;
	return w3;
}
