#include <iostream>

using namespace std;

int dp[100005] = {0};

int main(){
    int n;
    cin >> n;
    int arr[n];


    for(int i = 0;i < n;i++){
        char c;
        cin >> c;
        arr[i] = c - 48;
    }



    return 0;
}
