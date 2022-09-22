#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <set>
#include <queue>
#include <ctime>
#include <random>
#include <numeric>
#include <iomanip>


using namespace std;

int sqr(int a)
{
	return (a) * (a);
}

struct pt
{
	double x, y;

	pt(){}
	pt(double _x, double _y)
	{
		x = _x, y = _y;
	}

	double dis(pt &a)
	{
		return sqrt(sqr(a. x - x) + sqr(a.y - y));
	}
};

struct vt
{
	double a, b;

	vt(){}
	vt(double _a, double _b)
	{
		a = _a, b = _b;
	}

	double len()
	{
		return sqrt(sqr(a) + sqr(b));
	}

	vt ed ()
	{
		return vt(a / len(), b / len());
	}

	vt operator * (int k)
	{
		return vt(a * k, b * k);
	}
};

int tr(pt a, pt b, pt c)
{
	vt p1 = vt(b.x - a.x, b.y - a.y);
	vt p2 = vt(c.x - b.x, c.y - b.y);
	return p1.a*p2.b - p1.b*p2.a;
}

int main()
{
	int A1, B1, C1,
			A2, B2, C2;
	cin >> A1 >> B1 >> C1;
	cin >> A2 >> B2 >> C2;
	double z = A1 * B2 - A2 * B1;
	double x = (C1 * B2 - C2 * B1);
	double y = (A1 * C2 - A2 * C1);
	cout << fixed << setprecision(10) << (-x) / z << " " << (-y)/z;
}