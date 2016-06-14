
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<int> scores;
int result[100001];

void solve(int N, int item) {
	for (int j = -10; j <= 10; j++) {
		if (item + j >= 0 && item + j < N)
		{
			if (scores[item + j] > scores[item] && result[item] >= result[item + j]) {
				result[item + j] = result[item] + 1;
				solve(N, item + j);
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		scanf("%d", &x);
		scores.push_back(x);
	}
	for (int i = 0; i < N; i++)
	{
		int x;
		scanf("%d", &x);
		result[i] = x;
	}

	for (int i = 0; i < N; i++)
	{
		solve(N, i);
	}

	long long int ans = 0;

	for (int i = 0; i < N; i++) {
		ans += result[i];
	}

	printf("%lld", ans);
	return 0;
}
