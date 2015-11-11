#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector< pair<double,double> > arr;

    for(int i = 0;i < 2 * N;i++){
        double x,y;
        cin >> x >> y;
        arr.push_back(make_pair(x,y));
    }

    double length = 0;





    cout << fixed << setprecision(6) << length << endl;


    return 0;
}
