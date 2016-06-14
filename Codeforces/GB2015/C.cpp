#include <iostream>

using namespace std;

char g[501][501];

int main(){

    int height,width;
    cin >> height >> width;

    for(int i = 0;i < height;i++)
        for(int j = 0;j < width;j++)
            cin >> g[i][j];

    int queries;
    cin >> queries;

    for(int i = 0;i < queries;i++){
        int upX,upY,downX,downY;
        cin >> upX,upY,downX,downY;


    }


    return 0;
}
