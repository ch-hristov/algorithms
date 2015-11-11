#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    long long x1,x2;
    cin >> x1 >> x2;

    vector<pair <long long,long long> > pp1;

    for(int i = 0;i < n;i++){

        long long bi,ki;
        cin >> ki >> bi;
        pp1.push_back(make_pair(ki*x1+bi,ki*x2+bi));
    }

    sort(pp1.begin(),pp1.end());
    bool bad = false;

    for(int i = 1;i < n;i++){

        if(pp1[i].second < pp1[i - 1].second){
            bad = true;
            break;
        }

    }

    if(bad)cout<<"YES"<<endl;
    else cout << "NO"<<endl;
    return 0;
}
