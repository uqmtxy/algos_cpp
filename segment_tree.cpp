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

vector <int> p, d;
vector <char> used;
vector < vector <int> > g;

vector <int> ep, eg;

vector <int> fst;

vector < pair<int, int> > tr;

void build(int v, int vl, int vr)
{
	if (vl == vr)
	{
		tr[v].first = eg[vl];
		tr[v].second = ep[vl];
		return;
	}
	int vm = (vl + vr) / 2;
	build(2 * v + 1, vl, vm);
	build(2 * v + 2, vm + 1, vr);
	tr[v] = min(tr[2 * v + 1], tr[2 * v + 2]);
}

pair<int, int> query(int v, int vl, int vr, int l, int r)
{
	if (vr < l || r < vl)
		return {1000000, -1};
	if (l <= vl && vr <= r)
		return tr[v];
	int vm = (vl + vr) / 2;
	pair<int, int> ql = query(2 * v + 1, vl, vm, l, r);
	pair<int, int> qr = query(2 * v + 2, vm + 1, vr, l, r);
	return min(ql, qr);
}

void dfs(int v, int p = -1, int h = 0)
{
	fst[v] = eg.size();
	eg.push_back(h);
	ep.push_back(v);
	for (auto to : g[v])
	{
		if (to != p)
		{
			dfs(to, v, h + 1);
			ep.push_back(v);
			eg.push_back(h);
		}
	}
}

int lca (int a, int b)
{
	int l = min(fst[a], fst[b]);
	int r = max(fst[a], fst[b]);
	pair <int, int> lca = query(0, 0, ep.size() - 1, l, r);
	return lca.second;
}

int dist (int a, int b)
{
	return eg[fst[a]] + eg[fst[b]] - 2*eg[fst[lca(a, b)]];
}

int main()
{
	int n;
	scanf("%d", &n);
	g.resize(n);
	used.resize(n);
	p.resize(n, -1);
	d.resize(n, 0);
	fst.resize(n, 1e9);
	for (int i = 0; i < n-1; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	tr.resize(4*ep.size()+1);
	build(0, 0, ep.size()-1);

}