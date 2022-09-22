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

#define mp make_pair

vector <int> cmop, ps;
vector <bool> used;
vector < vector <int> > gin, gout, gk;

void dfs (int v) {
	if (used[v]) return;
	used[v] = 1;
	for (int to : gin[v]) {
		dfs(to);
	}
	ps.push_back(v);
}

void dfsc (int v, int c) {
	cmop[v] = c;
	for (int to : gout[v]) {
		if (cmop[to] == -1) {
			dfsc(to, c);
		}
	}
}


int main() {
	int n, m;
	cin >> n >> m;
	gin.resize(n);
	gout.resize(n);
	used.resize(n, 0);
	cmop.resize(n, -1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		gin[a-1].push_back(b-1);
		gout[b-1].push_back(a-1);
	}
	for (int i = 0; i < n; i++) {
		dfs(i);
	}
	int c = 1;
	for (int i = n-1; i >= 0; i--) {
		int x = ps[i];
		if (cmop[x] == -1) {
			dfsc (x, c);
			c++;
		}
	}
	int nsz = c-1;
	gk.resize(nsz);
	for (int i = 0; i < n; i++) {
		for (int t : gin[i]) {
			int x = cmop[i];
			int y = cmop[t];
			if (x != y && !mp[{x, y}]) {
				gk[x-1].push_back(y-1);
			}
		}
	}

}