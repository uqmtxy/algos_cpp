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

typedef long long ll;
typedef long double lld;

struct pt
{
	lld x, y;

	pt(){}
	pt(lld x1, lld y1) {x = x1, y = y1;}

	pt operator+ (pt vt) { return pt (x + vt.x, y + vt.y);}
	pt operator- (pt b) { return pt (b.x - x, b.y - y);}
	bool operator> (pt a) {return (x > a.x || (x == a.x && y > a.y));}
	bool operator< (pt a) {return (x < a.x || (x == a.x && y < a.y));}
};

lld v_pr (pt a, pt b)
{
	return a.x * b.y - a.y * b.x;
}

lld s_pr (pt a, pt b)
{
	return a.x * b.x + a.y * b.y;
}

pt r2d2 = pt(1e9, 1e9);

bool cmp (pt a, pt b)
{
	pt va = a - r2d2;
	pt vb = b - r2d2;
	return (v_pr(va, vb) < 0*1ll);
}

bool per (pt a, pt b, pt c, pt d)
{
	pt p = b - a;
	int A = p.y, B = -p.x, C = p.x * a.y - p.y * a.x;
	int cc = A*c.x + B*c.y + C, dd = A*d.x + B*d.y + C;
	if (cc != 0 || dd != 0)
	{
//        cout << "t";
		bool x = ((v_pr(a-c, d-c) * v_pr(b-c, d-c) <= 0) && (v_pr(c-b, a-b) * v_pr(d-b, a-b) <= 0));
		return x;
	}
	else
	{
		if (a.x != b.x)
		{
			if (c.x > d.x) swap(c, d);
			if (a.x > b.x) swap(a, b);
			return !(a.x > d.x || c.x > b.x);
		}
		else
		{
			if (c.y > d.y) swap(c, d);
			if (a.y > b.y) swap(a, b);
			return !(a.y > d.y || c.y > b.y);
		}
	}
}

int main()
{
	pt a, b, c, d;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	cin >> d.x >> d.y;
	cout << ((per(a, b, c, d)) ? "Yes" : "No");
}