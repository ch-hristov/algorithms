#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>

using namespace std;


#define ll long long
#define mp(x,y) make_pair(x,y)


int main() {

    int n;
    cin >> n;
    string ans = "";
    string ss = "";
    bool zero = false;
    for (int i = 0; i < n; i++) {
        string next;
        cin >> next;
        if (next == "0") {
            zero = true;
        }
        else {
            bool invalid = false;
            int ones = 0;
            for (int j = 0; j < next.length(); j++) {
                if (next[j] == '1'){
                    ones++;
                    if (ones > 1)invalid=true;
                }
                else if (next[j] != '1' && next[j] != '0')invalid = true;
            }

            if (invalid)ss = next;
            else {
                for (int x = 0; x < next.length() - 1; x++) {
                    ans += '0';
                }
            }
        }

    }
    if (zero) {
        cout << "0" << endl;
    }
    else{
        string x = ss + ans;
        cout << x << endl;
    }
    return 0;
}
