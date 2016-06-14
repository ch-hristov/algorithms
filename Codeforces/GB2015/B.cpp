#include <iostream>
#include <math.h>
#include "ConsoleApplication17.h"
#define ll long long

using namespace std;

int main() {
	ll a, b;
	cin >> a >> b;
	int ans = 0;

	int bits2 = (int)log2(b) + 1;
	int bits1 = (int)log2(a) + 1;

	for (int i = bits1; i <= bits2; i++) {
		ll num = (1LL << i) - 1;
		for (int j = 0; j < i - 1; j++) {
			ll cl = num & ~(1LL << j);
			if (cl >= a && cl <= b) ans++;
		}
	}

	cout << ans << endl;
	return 0;
}
