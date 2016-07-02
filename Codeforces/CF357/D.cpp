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

using namespace std;

vector < vector < int > > tree;

bool isParent(int item, int item2) {
	if (item == item2) return true;
	for (int x = 0; x < tree[item].size(); x++) if (tree[item][x] == item2)return true;
	return false;
}

int main()
{
	int N, m;
	cin >> N >> m;

	vector<int> curr;
	map<int, int> swapped;

	for (int i = 0; i <= N; i++) {
		tree.push_back(vector<int>());
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		tree[x].push_back(y);
	}

	vector<int> targets;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		targets.push_back(t);
	}

	bool possible = true;

	for (int i = 0; i < targets.size(); i++) {
		bool found = false;
		for (int j = 0; j < curr.size(); j++) {
			if (isParent(curr[j], targets[i])) {
				if (swapped[j]) {
					possible = false;
					break;
				}
				else {
					//insert targets[i] before curr[j]
					curr.insert(curr.begin() + j - 1, targets[i]);
					found = true;
				}
			}
		}
		if (!possible) break;
		if (!found) {
			curr.push_back(targets[i]);
		}
	}

	if (possible) {
		for (int i = 0; i < curr.size(); i++) {
			cout << curr[i] << " ";
		}
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}