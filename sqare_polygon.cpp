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

auto sqr(auto a){
	return a * a;
}

struct pt
{
	double x, y;

	pt(){}
};

struct vt
{
	double x, y;

	vt(){}

	vt(pt a, pt b)
	{
		x = b.x - a.x, y = b.y - a.y;
	}
};

vector <pt> v;

pt get(int i)
{
	return ((i >= 0) ? v[i] : v[v.size()+i]);
}

int main()
{
	int n;
	cin >> n;
	v.resize(n);
	for (pt &it:v) cin >> it.x >> it.y;
	long double s = 0;
	for (int i = 0; i < n; ++i)
	{
		pt a = get(i-2), b = get(i-1), c = get(i);
		vt x = vt(a, b), y = vt(b, c);
		s += a.x * b.y - a.y * b.x;
	}
	cout << fixed << setprecision(9) << fabs(s) / 2;
}