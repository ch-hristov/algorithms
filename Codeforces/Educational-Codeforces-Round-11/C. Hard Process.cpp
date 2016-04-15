
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>

using namespace std;

#define ll long long
#define pll pair<long,long>
#define pdd pair<double,double>
#define pb(x) push_back(x)
#define pii pair<int,int>

int maxi(int a, int b){
	return a > b ? a : b;
}

int mini(int a, int b){
	return a < b ? a : b;
}



vector<int> all;
vector<int> changes;

void print(){
	for (int i = 0; i < changes.size(); i++)
		all[changes[i]] = 1;

	for (int i = 0; i < all.size(); i++)
		printf("%d%c", all[i], ' ');
}


int main()
{

	int n, k;
	scanf("%d%d", &n, &k);


	for (int i = 0; i < n; i++){

		int xi;
		scanf("%d", &xi);

		all.pb(xi);
	}

	int maxscore = 0;

	for (int i = 0; i < all.size(); i++){

		int cnt = k;
		int sc = 0;

		vector<int> ch;

		for (int j = i; j < all.size(); j++){

			if (all[j] == 0){
				if (cnt == 0)
					break;
				cnt--;
				ch.pb(j);
			}

			sc++;
		}

		if (sc > maxscore){
			maxscore = sc;
			changes = ch;
		}
	}

	printf("%d\n", maxscore);

	print();

	return 0;
}
