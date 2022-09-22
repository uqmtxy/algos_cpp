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

struct tr
{
	int prior;
	int val;
	int sz;
	int sum;
	int mn;
	int mod;

	tr *l, *r;

	tr() : l(nullptr), r(nullptr){}
};

typedef tr* Tree;

int get_sz (Tree &t)
{
	if (t == nullptr) return 0;
	return t->sz;
}

int get_sum(Tree t)
{
	if (!t) return 0;
	return t -> sum;
}

int get_mn (Tree t)
{
	if (!t) return 1e9;
	return t -> mn;
}

void push (Tree t)
{
	if (t -> l)
	{
		t -> l -> mod ^= t -> mod;
	}
	if (t -> r)
	{
		t -> r -> mod ^= t -> mod;
	}
	if (t -> mod == 1)
	{
		swap(t -> l, t -> r);
	}
	t -> mod = 0;
	return;
}

void update (Tree &t)
{
	t -> sz = get_sz(t->l) + get_sz(t->r) + 1;
	t -> sum = get_sum(t -> l) + get_sum(t -> r) + t -> val;
	t -> mn = min(get_mn(t -> l), min(get_mn(t -> r), t -> val));
}

Tree create(int val)
{
	Tree t = new tr;

	int prior = (rand() << 15) + rand();

	t -> val = val;
	t -> l = t -> r = nullptr;
	t -> prior = prior;
	t -> sz = 1;
	t -> sum = val;
	t -> mn = val;
	t -> mod = 0;

	return t;
}

pair <Tree, Tree> split (Tree t, int sz)
{
	if (!t)
	{
		return {nullptr, nullptr};
	}

	push(t);

	if (get_sz (t->l) >= sz)
	{
		auto x = split(t->l, sz);
		t -> l = x.second;
		update(t);
		return {x.first, t};
	}
	else
	{
		auto x = split(t->r, sz - get_sz(t->l)-1);
		t -> r = x.first;
		update(t);
		return {t, x.second};
	}
}

Tree Merge (Tree a, Tree b)
{
	if (!a) return b;
	else if (!b) return a;

	push(a);
	push(b);

	if (a -> prior >= b -> prior)
	{
		a -> r = Merge(a -> r, b);
		update(a);
		return a;
	}
	else
	{
		b -> l = Merge(a, b->l);
		update(b);
		return b;
	}
}

void insert (Tree &t, int pos, int val)
{
	auto x = split(t, pos);
	t = Merge(Merge(x.first, create(val)), x.second);
}

void erase (Tree &t, int pos)
{
	auto x = split(t, pos);
	auto r = split(x.second, 1);
	t = Merge(x.first, r.second);
}

void erase (Tree &t, int l, int r)
{
	auto x = split(t, l);
	auto d = split(t, r-l+1);
	t = Merge(x.first, d.second);
}

int get (Tree t, int pos)
{
	if (get_sz(t -> l) == pos)
	{
		return t -> val;
	}
	if (get_sz(t -> l) > pos)
	{
		return get(t -> l, pos);
	}
	else
	{
		return get(t -> r, pos - get_sz(t->l) - 1);
	}
}

void print_tree (Tree t)
{
	if (!t)
	{
		return;
	}
	print_tree(t -> l);
	cout << t -> val << " ";
	print_tree(t -> r);
}

int query (Tree t, int l, int r)
{
	auto x = split(t, l);
	auto d = split(x.second, r-l+1);
	int ans = get_sum(d.first);
	t = Merge(x.first, Merge(d.first, d.second));
	return ans;
}

void modify (Tree &t, int pos, int val)
{
	if (!t) return;
	if (get_sz(t -> l) == pos)
	{
		t -> val = val;
		update(t);
	}
	else if (get_sz(t -> l) > pos)
	{
		modify(t -> l, pos, val);
		update(t);
	}
	else
	{
		modify (t -> r, pos - get_sz(t->l) - 1, val);
		update(t);
	}
}

int main()
{
	Tree t = nullptr;
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int a; cin >> a;
		insert(t, i, a);
	}
	for (int i = 0; i < m; ++i)
	{
		int type, l, r;
		cin >> type >> l >> r;
		--l, --r;
		if (type == 1)
		{
			pair <Tree, Tree> x = split(t, l);
			pair <Tree, Tree> p = split(x.second, r-l+1);
			p.first -> mod ^= 1;
			t = Merge(x.first, Merge(p.first, p.second));
		}
		else
		{
			auto x = split(t, l);
			auto p = split(x.second, r-l+1);
			cout << get_mn(p.first) << endl;
			t = Merge(x.first, Merge(p.first, p.second));
		}
	}
}