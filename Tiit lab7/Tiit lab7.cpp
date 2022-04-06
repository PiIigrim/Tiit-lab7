#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <ctime>
#include "wdown.h"
#include "wup.h"
using namespace std;

double sum1(double vectorx1, double vectorx2, double vectorx3, double w1, double w2, double w3) {
	double sum = w1 * vectorx1 + w2 * vectorx2 + w3 * vectorx3;
	return sum;
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int i = 0, z = 0, a, n, ogr, z1 = 0, u = 0, d = 0, test = 0;
	string path = "x1.csv";
	fstream fs;
	fs.open(path, fstream::in);
	string text;
	double x1, x2, x3, y, y1, x, se, mse, ch = 0, summa = 0, ogr1 = 1.2e+08;
	double w0, w1, w2, w3, a0, a1;
	w0 = x = (double)((0 * pow(10, 4) + rand() % (int)(5 * pow(10, 4) - 0 * pow(10, 4))) / pow(10, 4));
	w1 = x = (double)((0 * pow(10, 4) + rand() % (int)(5 * pow(10, 4) - 0 * pow(10, 4))) / pow(10, 4));
	w2 = x = (double)((0 * pow(10, 4) + rand() % (int)(5 * pow(10, 4) - 0 * pow(10, 4))) / pow(10, 4));
	w3 = x = (double)((0 * pow(10, 4) + rand() % (int)(5 * pow(10, 4) - 0 * pow(10, 4))) / pow(10, 4));
	cout << "w0: " << w0 << " " << "w1: " << w1 << " " << "w2: " << w2 << " " << "w3: " << w3 << " " << endl;
	/*cout << "Сколько строк считаем?(0 для максимума)" << endl;
	cin >> n;
	if (n == 0) {
		n = 200;
	}*/
	n = 200;
	a0 = 2;
	/*cout << "Шаг: " << endl;
	cin >> a0;*/
	a1 = a0;
	ogr = n * 3;
	vector <double> vectorx1;
	vector <double> vectorx2;
	vector <double> vectorx3;
	vector <double> vectory;
	vector <double> vectorw0;
	vector <double> vectorw1;
	vector <double> vectorw2;
	vector <double> vectorw3;
	vector <double> vectormse;
	while (!fs.eof()) {
		a = i % 3;
		text = "";
		fs >> text;
		replace(text.begin(), text.end(), '.', ',');
		if (text == "") {
			break;
		}
		else {
			double numtext = stod(text);
			switch (a) {
			case 0: x1 = numtext;
				vectorx1.push_back(x1);
				break;
			case 1: x2 = numtext;
				vectorx2.push_back(x2);
				break;                                                          //вывод x из файла
			case 2: x3 = numtext;
				vectorx3.push_back(x3);
				break;
			}
		}
		i++;
	}
	i = 0;
	string path2 = "y1.csv";
	fstream fs2;
	fs2.open(path2, fstream::in);
	string text2;
	while (!fs2.eof()) {
		text2 = "";
		fs2 >> text2;
		replace(text2.begin(), text2.end(), '.', ',');
		if (text2 == "") {
			break;                                                  //вывод y из файла
		}
		double numtext = stod(text2);
		y = numtext;
		vectory.push_back(y);
		i++;
		if (i == n) {
			break;
		}
	}
	do {
		y1 = 0; se = 0, mse = 0;
		i = 0;
		for (i = 0; i < n; i++) {
			y1 = sum1(vectorx1[i], vectorx2[i], vectorx3[i], w1, w2, w3);      // высчитывание y^
			y1 += y1;
		}
		y1 = y1 + w0;
		for (i = 0; i < n; i++) {
			se = (pow((vectory[i] - y1), 2));
			se += se;
		}
		mse = se / n;
		cout << "Номер:" << z << " MSE: " << mse << endl;
		switch (z1) {
		case 0: {w0 = w0down(w0, a0);
			vectorw0.push_back(w0);
			w1 = w1down(w1, a0);
			vectorw1.push_back(w1);
			w2 = w2down(w2, a0);
			vectorw2.push_back(w2);
			w3 = w3down(w3, a0);
			vectorw3.push_back(w3); }
			  break;
		case 1: {w0 = w0up(w0, a1);
			vectorw0.push_back(w0);
			w1 = w1up(w1, a1);
			vectorw1.push_back(w1);
			w2 = w2up(w2, a1);
			vectorw2.push_back(w2);
			w3 = w3up(w3, a1);
			vectorw3.push_back(w3); }
			  break;
		}
		if (mse > ch) {
			z1 += 1;
			ogr1 = mse;
		}
		if (mse > ogr1) {
			z1 += 1;
		}
		z1 = z1 % 2;
		ch = mse;
		vectormse.push_back(mse);
		z++;
	} while (z < 150);
	int minpos = min_element(vectormse.begin(), vectormse.end()) - vectormse.begin();
	double msemin = *min_element(vectormse.begin(), vectormse.end());
	//cout << "Позиция: " << minpos << endl;
	cout << '\n' << "Минимальная ошибка: " << msemin << endl;
	cout << "Параметры: " << '\n' << "w0: " << vectorw0[minpos] << '\n' << "w1: " << vectorw1[minpos] << '\n' << "w2: " << vectorw2[minpos] << '\n' << "w3: " << vectorw3[minpos] << endl;
	/*cout << "Массив w0: " << endl;
	i = 0;
	for (double w0 : vectorw0) {
		cout << i << ": ";
		cout << w0 << endl;
		i++;
	}
	i = 0;
	cout << endl;
	cout << "Массив w1: " << endl;
	for (double w1 : vectorw1) {
		cout << i << ": ";
		cout << w1 << endl;
		i++;
	}
	i = 0;
	cout << endl;
	cout << "Массив w2: " << endl;
	for (double w2 : vectorw2) {
		cout << i << ": ";
		cout << w2 << endl;
		i++;
	}
	i = 0;
	cout << endl;
	cout << "Массив w3: " << endl;
	for (double w3 : vectorw3) {
		cout << i << ": ";
		cout << w3 << endl;
		i++;
	}*/
	fs.close();
}