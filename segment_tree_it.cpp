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
int n, ff;
vector<int>v, tr;

void build() {
	for (int i = 0; i < n; i++) {
		tr[(1 << ff) + i] = v[i];
	}
	for (int i = (1 << ff) - 1; i > 0; i--) {
		tr[i] = tr[2 * i] + tr[2 * i + 1];
	}
}

void modify(int x, int a) {
	x--;
	tr[x] = a;
	x /= 2;
	while (x) {
		tr[x] = tr[2 * x] + tr[2 * x + 1];
		x /= 2;
	}
}

int query(int l, int r) {
	l--;
	r--;
	int res = 0;
	l += (1 << ff), r += (1 << ff) + 1;
	while (l < r) {
		if (l & 1)
			res += tr[l++];
		if (r & 1)
			res += tr[--r];
		l /= 2;
		r /= 2;
	}
	return res;
}

int main(){

}

