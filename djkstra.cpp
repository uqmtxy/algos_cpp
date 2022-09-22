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

const int inf = 1e9;

vector<vector<pair<int, int> > >g;
vector<int>d;

void djkstra(int s){
	priority_queue<pair<int, int> >q;
	q.push({0, s});
	d[s] = 0;
	while(!q.empty()){
		int v = q.top().second, cur_d = -q.top().first;
		q.pop();
		if(cur_d > d[v]){
			continue;
		}
		for(auto to : g[v]){
			if(d[to.first] > d[v] + to.second){
				d[to.first] = d[v] + to.second;
				q.push({-to.second, to.first});
			}
		}
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	g.resize(n); d.resize(n, inf);
	for(int i = 0; i < m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		g[a - 1].push_back({b - 1, w});
		g[b - 1].push_back({a - 1, w});
	}
	int s;
	cin >> s;
	s--;
	djkstra(s);
	for(int i = 0; i < n; i++){
		cout << d[i] << ' ';
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	while(t--){
		solve();
	}
	return 0;
}