#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>

#define ll long long
#define lld long long double
#define pb(x) push_back(x)
#define F first
#define S second

long long pow(int base, int power) {
    ll a = 1;
    for (int j = 0; j < power; j++) {
        a *= base;
    }
    return a;
}

using namespace std;

int main() {

    int n, bx;

    cin >> n >> bx;

    int* x = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int m, by;

    cin >> m >> by;

    int* y = new int[m];

    for (int i = 0; i < m; i++) {
        cin >> y[i];
    }

    ll x1, y1;

    x1 = y1 = 0;

    for (int j = 0; j < n; j++) {
        x1 += x[j] * pow(bx, n - j - 1);
    }

    for (int j = 0; j < m; j++) {
        y1 += y[j] * pow(by, m - j - 1);
    }

    if (x1 == y1) cout << '=';
    if (x1 < y1) cout << '<';
    if (x1 > y1) cout << '>';

    return 0;
}
