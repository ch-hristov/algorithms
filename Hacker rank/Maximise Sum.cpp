#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>


#define F first;
#define S second;
#define ip pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ll long long
#define pb(x) push_back(x)

using namespace std;


ll maxim(ll a,ll b){
    return a > b ? a : b;
}
    
int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        ll M;

        cin >> N >> M;
        vector<ll> arr;
        ll dp[N];
        for(int i = 0; i < N;i++) dp[i] = 0;


        for(int i = 0;i<N;i++){
            ll j;
            cin >> j;
            arr.pb(j);
        }
        ll maxi = -10e9;
        ll DP[N][N];

        for(int i = 0;i < N;i++){
            for(int j = i + 1;j++){

            }
        }

    }
}
