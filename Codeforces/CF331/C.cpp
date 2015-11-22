#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int N;
    cin >> N;

    int wi[N];

    map<int, queue< pair<int,int> > > dp;

    vector< pair < int,int > > result;


    for(int i = 0;i < N;i++){
        int x,y;
        cin >> x >> y;
        dp[y-x].push(make_pair(x,y));
    }

    for(int i = 0;i < N;i++){
        int z;
        cin >> z;
        wi[i] = z;
    }

    bool ok = true;





    if(ok){
        cout << "YES"<<endl;
        for(int i = 0;i < N;i++){
            cout << result[i].first << " " << result[i].second << endl;
        }
    }
    else{
        cout << "NO"<<endl;
    }

    return 0;
}
