#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
#include <map>
#include <stdio.h>

#define pii pair <int,int>
#define vpii vector < pair < int,int > >
#define INF 999999999
#define vvi vector< vector < int > >
#define forall(i,a,b) for(int i = a;i < b;i++)
#define pb(x) push_back(x)
#define bitcount __builtin_popcount
#define gcd __gcd
#define mp(x,y) make_pair(x,y)

using namespace std;

vvi G1;
vvi G2;
int j;
vpii ans;

void solve(int c1,int c2,vpii v,int bm1,int bm2){
    if(v.size()>ans.size())
        ans=v;

    int k,m;

    forall(k,0,G1[c1].size()){
        if(!(bm1 & (1 << G1[c1][k]))){
            forall(m,0,G2[c2].size()){
                if(!(bm2 & ( 1 << G2[c2][m]))){
                    if(G1[G1[c1][k]].size() == G2[G2[c2][m]].size() ){
                        v.pb(mp(k,m));
                        solve(G1[c1][k],G2[c2][m],v,bm1 | (1 << G1[c1][k]),bm2 | ( 1 << G2[c2][m]));
                    }
                }
            }
        }
    }
}


int main(){
    int V1, E1;
    cin >> V1 >> E1;
	G1 = vvi(V1);
	int i;

	forall(i, 0, E1) {
		int a, b;
		cin >> a >> b;
		G1[a - 1].pb(b - 1);
		G1[b - 1].pb(a - 1);
	}

	int V2, E2;

	cin >> V2 >> E2;
	G2 = vvi(V2);

	forall(i, 0, E2) {
		int a, b;
		cin >> a >> b;
		G2[a - 1].pb(b);
		G2[b - 1].pb(a);
	}

	int j;
	forall(i,0,G1.size()){
        forall(j,0,G2.size()){
            if(G1[i].size()==G2[j].size()){
                vpii aj;
                aj.pb(mp(i,j));
                solve(i,j,aj,0,0);
            }
        }
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first + 1 << " matches with " << ans[i].second + 1 << endl;
	}
    return 0;
}
