#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int flats = 0;

    for(int i = 0;i < n;i++){

        int wi[2*m];
        for(int j = 0;j < 2*m;j++){
            cin >> wi[j];
        }
        for(int v = 1;v <= 2*m;v+=2){
            if(wi[v - 1] == 1 || wi[v] == 1){
                flats++;
            }
        }

    }

    cout << flats << endl;

    return 0;
}
