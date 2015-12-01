#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <iomanip>

#define ll long long
#define lld long long double
#define pb(x) push_back(x)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pii pair < int,int >

using namespace std;

int target;
double dist[20][20];
double memo[1 << 16];

double solve(int bitmask,int N){
    if(memo[bitmask] > -0.5){
        return memo[bitmask];
    }
    if(bitmask==target){
        return memo[bitmask]=0;
    }
    double ans = 2000000000.0; // initialize with a large value
    int p1, p2;
    for (p1 = 0; p1 < 2 * N; p1++)
    if (!(bitmask & (1 << p1)))
    break; // find the first bit that is off
    for (p2 = p1 + 1; p2 < 2 * N; p2++) // then, try to match p1
    if (!(bitmask & (1 << p2))) // with another bit p2 that is also off
    ans = min(ans, // pick the minimum
        dist[p1][p2] + solve(bitmask | (1 << p1) | (1 << p2),N));
    return memo[bitmask] = ans; // store result in a memo table and return
}

int main() {

    while(1){

        int N;
        cin >> N;

        if(N==0)break;

        int x[20],y[20];

        for(int i = 0;i < 2*N;i++){
            string s;
            cin >> s;
            cin >> x[i] >> y[i];
        }

        int i,j;
        for (i = 0; i < 2 * N - 1; i++) // build pairwise distance table
            for (j = i + 1; j < 2 * N; j++) // have you used ‘hypot’ before?
                dist[i][j] = dist[j][i] = hypot(x[i] - x[j], y[i] - y[j]);

        for(int j = 0;j < (1 << 16);j++){
            memo[j]=-1.0;
        }

        target = (1 << ( 2 * N )) - 1;

        double ans = solve(0,N);
        cout << fixed << setprecision(2) << ans << endl;
    }

    return 0;
}
