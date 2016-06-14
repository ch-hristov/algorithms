#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;


int main()
{
	int n;
	cin >> n;


	vector < pair < string, int > > result;

	vector<int> data;

	make_heap(data.rbegin(), data.rend());

	for (int i = 0; i < n; i++) {
		string query;
		cin >> query;

		int num = -1;
		if (query != "removeMin") {
			num;
			cin >> num;
		}


		if (query == "insert") {
			data.push_back(num);
			result.push_back(make_pair(query, num));
		}
		if (query == "getMin") {

			int fr;
			if (data.size() == 0) {
				data.push_back(num);
				result.push_back(make_pair("insert", num));
				fr = data.front();
			}
			if (fr != num) {
				bool ad = false;
				while (data.size() > 0) {
					if (data.front() != num) {
						data.pop_back();
						result.push_back(make_pair("removeMin", -1));
					}
					else {
						ad = true;
						break;
					}
				}
				if (!ad) {
					result.push_back(make_pair("insert", num));
				}
			}

			result.push_back(make_pair(query, num));
		}
		if (query == "removeMin") {
			if (data.size() == 0) {
				data.push_back(1);
				result.push_back(make_pair("insert", 1));
			}
			data.pop_back();
			result.push_back(make_pair("removeMin", -1));
		}


	}

	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) {

		cout << result[i].first;

		if (result[i].second != -1) {
			cout << " " << result[i].second << endl;
		}
		else {
			cout << endl;
		}
	}


	return 0;
}