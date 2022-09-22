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

/// факторизация для множества чисел
/// \param ee
/// \return

vector<int> fact(int ee = 2 * 1e7) {
	vector<int> min_dev(ee, 1);
	int n = min_dev.size();
	for (ll i = 2; i * i <= n; i ++) {
		if (min_dev[i] == 1) {
			for (ll j = i * i; j <= n; j += i) {
				if (min_dev[j] == 1) {
					min_dev[j] = i;
				}
			}
			min_dev[i] = i;
		}
	}
	return min_dev;
}

int main(){

}