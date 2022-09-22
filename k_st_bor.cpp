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

struct br
{
	map <char, br*> m;
	int term;
	int sz = 0;

	br(){}
};

typedef br* Bor;

void add_str (Bor a, string s, int pos)
{
	a -> sz += 1;
	if (pos == s.size())
	{
		a -> term++;
		return;
	}
	if (a -> m[s[pos]] == nullptr)
	{
		Bor x = new br;
		x -> term = 0;
		a -> m[s[pos]] = x;
	}
	add_str(a -> m[s[pos]], s, pos+1);
}

void k_st (Bor a, int k, string &s)
{
	if (a -> term && k <= a -> term)
	{
		cout << s << endl;
		return;
	}
	else
	{
		k -= a -> term;
	}
	for (auto it : a -> m)
	{
		if (k - it.second -> sz <= 0)
		{
			s.push_back(it.first);
			k_st (it.second, k, s);
			break;
		}
		k -= it.second -> sz;
	}
}

void print (Bor a)
{
	for (auto it : a -> m)
	{
		cout << "{" << it.first << ", " << it.second -> sz << "} ";
	}
	cout << a->sz << endl;
	for (auto it : a -> m)
	{
		print(it.second);
	}
}

int main()
{
	Bor b = new br;
	b -> term = 0;
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int type; cin >> type;
		if (type == 1)
		{
			string s; cin >> s;
			add_str(b, s, 0);
		}
		else
		{
			string dd = "";
			int k; cin >> k;
			k_st(b, k, dd);
		}
	}
//    print(b);
}