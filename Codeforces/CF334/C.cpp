#include <iostream>

using namespace std;


const int maximum = 10e5 + 1;
int arr[maximum];

void solve(int N){

    bool add = false;

    int total = 1;
    int next = arr[0] == 0 ? 1 : 0;

    for(int i = 1;i < N;i++){
        if(arr[i]==arr[i-1])
            add=true;
        if(arr[i]==next){
            next = next == 0 ? 1 : 0;
            total++;
        }
    }

    if(add)total+=2;

    cout << min(N,total)<<endl;
}

int main(){

    int N;

    cin >> N;

    for(int i = 0;i < N;i++){
        char c;
        cin >> c;
        arr[i] = c - 48;
    }

    solve(N);

    return 0;
}
