#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <queue>
#include <functional>
#include <stack>
#include <string>
#include <tuple>


using namespace std;

int INF = 999999999;

int NA = -1;

int mini(int a, int b) {
	return a < b ? a : b;
}

vector < vector < int > > G;

int djikstra(int source, int target) {
	int visited[10000] = { 0 };

	priority_queue < pair<int, int>, vector<pair<int, int> >, std::greater<pair<int, int> > > pq;

	pq.push(make_pair(0, source));

	int optimal[10000];

	for (int i = 0; i < 10000; i++) {
		optimal[i] = INF;
	}

	optimal[source] = 0;

	while (!pq.empty()) {

		pair<int, int> next = pq.top(); pq.pop();

		visited[next.second] = 1;

		if (next.second == target) {
			break;
		}

		for (int i = 0; i < G[next.second].size(); i++) {
			if (G[next.second][i] != -1 && !visited[i]) {
				optimal[i] = mini(optimal[i], optimal[next.second] + G[next.second][i]);
				pq.push(make_pair(G[next.second][i], i));
			}
		}
	}

	return optimal[target];
}

int main() {
	//Nodes
	int N; cin >> N;
	for (int i = 0; i <= N; i++) {
		G.push_back(vector<int>());
		for (int j = 0; j <= N; j++) {
			G[i].push_back(NA);
		}
	}
	//Edges
	int S; cin >> S;
	for (int i = 0; i < S; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		G[a][b] = d;
		G[b][a] = d;
	}
	//Queries
	int Z; cin >> Z;
	for (int i = 0; i < Z; i++) {
		int a, b;
		cin >> a >> b;
		int r = djikstra(a, b);
		cout << r << endl;
	}

	return 0;
}