#include <iostream>
#include <cmath>
#include <assert.h>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    cout << "Please enter enclosing border" << endl;

    int border;
    cin >> border;

    cout << "Please enter speed" << endl;
    int speed;
    cin >> speed;

    int terrain[border][border];
    int maxim= -(int)10e6;

    map<int,pair< pair<int,int> ,pair<int,int> > > posMap;
    bool v[maxim];

    for(int i = 0;i<border;i++)
        for(int j = 0;j<border;j++){

            cin >> terrain[i][j];
            maxim = terrain[i][j] > maxim ? terrain[i][j] : maxim;
            if(!v[maxim]){
                v[maxim]=1;
                posMap[terrain[i][j]] = make_pair(make_pair(i,j),make_pair(-1,-1));
            }
        else{
            posMap[terrain[i][j]].second = make_pair(i,j);
        }
    }
    return 0;
}
