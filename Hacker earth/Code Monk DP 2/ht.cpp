#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;


long double dist(pair<long double, long double> f, pair<long double, long double> s) {
	long double x = s.first - f.first;
	long double y = s.second - f.second;
	long double xx = x*x;
	long double yy = y*y;
	return sqrt(xx + yy);
}


long double maximal(long double a,long double b){
    return a > b ? a : b;
}

int main() {

	int N;
	cin >> N;
	long double F[N];

	vector< pair <long double, long double> > d;

	for (int i = 0; i < N; i++) {
		long double x, y,f;
		cin >> x >> y >> f;
		d.push_back(make_pair(x, y));
		F[i] = f;
	}

    long double dp[N];

    dp[0] = F[0];

    for(int i = 1;i < N;i++){
        dp[i] = -9999999999999999999999999999999999;
        for(int j = 0;j < i;j++){
            long double dista = dp[j] - dist(d[i],d[j]);
            dp[i] = maximal(dp[i],dista);
        }
        dp[i] += F[i];
    }

    cout << fixed << setprecision(6) << dp[N - 1] << endl;


	return 0;
}
