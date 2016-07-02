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



int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;

		vector<int> items;

		int optimal = 0;

		//buy,sell,skip
		vector< pair<int, int> > data;
		int marked[100001] = { 0 };

		for (auto i = 0; i < N; i++)
		{
			int input;
			cin >> input;
			items.push_back(input);

			data.push_back(make_pair(input, i));
		}

		sort(data.rbegin(), data.rend());

		long long int result = 0;
		int tot = 0;

		for (int i = 0; i < data.size(); i++) {
			long long int cnt = 0;
			bool done = false;

			for (int val = data[i].second - 1; val >= 0 && items[val] <= data[i].first; val--) {
				if (marked[val])break;
				int comp = data[i].first - items[val];
				cnt += comp;
				marked[val] = 1;
			}

			result += cnt;
		}
		cout << result << endl;
	}
	return 0;
}