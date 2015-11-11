//Solved

#include <iostream>

using namespace std;


int gcd(int a,int b){
    int r = a % b;
    if(r == 0) return b;
    else return gcd(b,r);
}

int main(){
    int tests;
    cin >> tests;

    while(tests-- > 0){
        int a,b;
        cin >> a >> b;
        int o = 0;
        int gCd = gcd(a,b);
        while(b % a != 0){
            a >>= 1;
            o++;
        }

        while(a != b){
            a <<= 1;
            o++;
        }

        cout << o << endl;
    }
    return 0;
}
