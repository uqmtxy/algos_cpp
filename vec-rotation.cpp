//
// Created by Эрдэни Хатунов on 22.09.2022.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <set>
#include <queue>
#include <ctime>
#include <random>
#include <map>
#include <numeric>
#include <iomanip>

using namespace std;

int main()
{
	double x, y;
	double p;
	cin >> x >> y >> p;
	double _x = x*cos(p) + y * sin(p);
	double _y = -x*(sin(p)) + y * cos(p);
	cout << fixed << setprecision(9) << _x << " " << _y;
}