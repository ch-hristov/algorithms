#include <queue>
#include <iostream>

#define ll long long
#define lld long long double
#define pb(x) push_back(x)
#define F first
#define S second
#define INFINITY 999999999

using namespace std;

const int MAXN = 401;
int G[MAXN][MAXN] = { 0 };


void bfs(int graph, int N) {

	queue < int > q;
	q.push(1);

	int C[MAXN];

	for (int i = 0; i <= N; i++) {
		C[i] = -1;
	}

	C[1] = 0;

	while (q.size() > 0) {

		int u = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (G[u][i] == graph && C[i] == -1) {
				C[i] = C[u] + 1;
				q.push(i);
			}
		}
	}


	cout << C[N] << endl;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		G[u][v] = 1;
		G[v][u] = 1;
	}

	if (G[1][n]) {
		bfs(0, n);
	}
	else bfs(1, n);

}
