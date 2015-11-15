#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    long long b[n];
    for(int i = 0;i < n;i++){
        cin >> b[i];
    }

    long long result = 0;

    long long pluses,minuses;
    pluses = minuses = 0;

    long long x = 0;

    for(int i = 0;i < n;i++){

        long long diff = b[i] - pluses + minuses;


        if(diff != 0) x += diff < 0 ? - diff : diff;

        if(diff < 0){
            minuses += -diff;
        }
        else{
            pluses += diff;
        }

    }

    cout << x << endl;
}
