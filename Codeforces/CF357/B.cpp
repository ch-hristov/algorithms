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

//C 357
int main()
{
	cin.sync_with_stdio(false);
	int n;
	cin >> n;

	vector< pair < string, long long > > answer;

	priority_queue < long long, vector<long long>, std::greater<long long> > pq;

	for (int i = 0; i < n; i++) {
		string query;
		cin >> query;
		long long number =10000000000;

		if (query == "removeMin") {
			if (pq.empty()) {
				answer.push_back(make_pair("insert", 0));
			}
			else {
				pq.pop();
			}
		}
		else {
			cin >> number;

			if (query == "insert") {
				pq.push(number);
			}
			else {
				//getmin

				while (true) {
					if (pq.empty()) {
						pq.push(number);
						answer.push_back(make_pair("insert", number));
						break;
					}
					else {
						long top = pq.top();
						if (top < number) {
							pq.pop();
							answer.push_back(make_pair("removeMin", 10000000000));
						}
						else {
							if (top != number) {
								answer.push_back(make_pair("insert", number));
								pq.push(number);
							}
							break;
						}
					}
				}

			}
		}
		answer.push_back(make_pair(query, number));
	}


	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i].second == 10000000000) {
			cout << answer[i].first << endl;
		}
		else {
			cout << answer[i].first << " " << answer[i].second << endl;
		}
	}

	return 0;
}