#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdio.h>
#include <iomanip>

using namespace std;


int popcount(int n){
    int c = 0;
    while(n > 0){
        if(n % 2)c++;
        n >>= 1;
    }
    return c;
}

double dist(pair<double,double> p1,pair<double,double> p2){
    double f = p2.first - p1.first;
    double s = p2.second - p2.second;

    return sqrt(f * f + s * s);
}


int main(){

    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;


    vector< pair<double,double> > p;

    for(int i = 0;i < 2*N;i++){
        double x,y;
        cin >> x >> y;
        p.push_back(make_pair(x,y));
    }


    double dp[2*N];

    dp[0] = 0;

    for(int i = 0;i < (1 << N);i++){
        if(popcount(i) % 2) continue;
        dp[i] = 2000000000;

        for(int j = 0;j < N;j++){
            if((i & ( 1 << j)) == 0) continue;
            for(int k = j + 1;k < N;k++){
                if((k & ( 1 << k)) == 0) continue;
                dp[i] = min(dp[i],dp[i - (1 << j) - (1 << k)] + dist(p[j],p[k]));
            }
        }
    }

    cout<<fixed;
	cout.precision(6);
	cout<<dp[(1<<N)-1]<<endl;

    return 0;
}
