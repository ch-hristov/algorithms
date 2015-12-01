#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>

#define ll long long
#define lld long long double
#define pb(x) push_back(x)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pii pair < int,int >

using namespace std;


vector < pii > vect;

double dist(pii a,pii b){
    double ax = b.F - a.F;
    double ay = b.S - a.S;

    return sqrt(ax*ax+ay*ay);
}

double solve(){

}

int main() {

    while(1){

        int N;
        cin >> N;

        if(N==0)break;

        vect.clear();

        for(int i = 0;i < 2*N;i++){
            int x, y;
            cin >> x >> y;
            vect.pb(mp(x,y));
        }

        double ans = solve();
        cout << ans << endl;
    }

    return 0;
}
