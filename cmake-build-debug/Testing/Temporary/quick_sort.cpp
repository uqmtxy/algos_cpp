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


int f(vector<int>& a, int l, int r) {
	int k = a[rand() % (r - l + 1)];
	int i = l, j = r;
	while (i <= j) {
		while (a[i] < k) {
			i++;
		}
		while (a[j] > k) {
			j--;
		}
		if (i >= j) {
			break;
		}
		swap(a[i++], a[j--]);
	}
	return j;
}

void quick_sort(vector<int>&a, int l, int r) {
	if (l < r) {
		int q = f(a, l, r);
		quick_sort(a, l, q);
		quick_sort(a, q + 1, r);
	}
}

int main(){

}