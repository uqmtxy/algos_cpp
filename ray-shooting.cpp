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

int get (int i, int n)
{
	if (i < 0) return n-i;
	else if (i >= n) return i-n;
	else return i;
}

bool per (pt a, pt b, pt c, pt d)
{
	pt p = b - a;
	lld A = p.y, B = -p.x, C = p.x * a.y - p.y * a.x;
	lld cc = A*c.x + B*c.y + C, dd = A*d.x + B*d.y + C;
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
	pt a;
	int n;
	cin >> n >> a.x >> a.y;
	vector < pt > v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].x >> v[i].y;
	}
	for (int i = 0; i < n; ++i)
	{
		int p = get(i+1, n);
		if (v_pr(a - v[i], v[p] - v[i]) == 0)
		{
			if ((min(v[i].x, v[p].x) <= a.x && a.x <= max(v[i].x, v[p].x)) && (min(v[i].y, v[p].y) <= a.y && a.y <= max(v[i].y, v[p].y)))
			{
				cout << "YES";
				return 0;
			}
		}
	}
	int cnt = 0;
	pt d = pt(-2*1e7, 3*1e7+10);
	vector <char> used (n, 0);
	for (int i = 0; i < n; ++i)
	{
		if (v_pr(v[i] - a, d - a) == 0)
		{
			used[i] = 1;
			int p1 = get(i+1, n), p2 = get(i-1, n);
			if (v_pr(v[i] - a, v[p1] - a) * v_pr(v[i] - a, v[p2] - a) <= 0)
			{
				++cnt;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		int p = get(i+1, n);
		if (used[i] || used[p]) continue;
		if (v_pr(v[i] - a, v[i+1] - a) == 0 && v_pr(v[i+1] - v[i], d - v[i]) == 0 && per(a, d, v[i], v[i+1]))
		{
			used[i] = used[p] = 1;
			int p1 = get(i-1, n), p2 = get(i+2, n);
			if (v_pr(v[i] - a, v[p1] - a) * v_pr(v[i] - a, v[p2] - a) <= 0)
			{
				++cnt;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		int p = get(i+1, n);
		if (used[i] || used[p]) continue;
		cnt += per(a, d, v[i], v[p]);
	}
	cout << ((cnt & 1) ? "YES" : "NO");
}