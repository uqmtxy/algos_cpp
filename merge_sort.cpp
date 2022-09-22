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


using namespace std;

long long cnt = 0;

void merg(vector <int> &a, int l, int m, int r)
{
	vector <int> b(r - l + 1);
	int p1 = l, p2 = m, p = 0;
	while(p1 < m || p2 < r)
	{
		if (p1 == m)
		{
			b[p++] = a[p2++];
		}
		else if (p2 == r)
		{
			b[p++] = a[p1++];
		}
		else if (a[p1] <= a[p2])
		{
			b[p++] = a[p1++];
		}
		else
		{
			b[p++] = a[p2++];
			cnt += m - p1;
		}
	}
	for (int i = l; i < r; ++i)
	{
		a[i] = b[i - l];
	}
}

void sot(vector <int> &a, int l, int r)
{
	if (r - l == 1)
	{
		return;
	}
	int m = (l + r) / 2;
	sot(a, l, m);
	sot(a, m, r);
	merg(a, l, m, r);
//    for (auto it:a) cout << it << " ";
//    cout << endl;
}

int main()
{
	int n; cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	sot(v, 0, v.size());
	cout << cnt;
}