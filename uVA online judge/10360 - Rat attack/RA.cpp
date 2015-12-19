#include <iostream>

using namespace std;


const int MAXI = 1025;

int arr[MAXI][MAXI];


int dp[MAXI][MAXI];

int main(){
    int t;
    cin >> t;

    while(t--){
        int N,d;
        cin >> d >> N;

        for(int i = 0;i < 1024;i++)
            for(int j = 0;j < 1024;j++){
                arr[i][j]=0;
                dp[i][j] = 0;
            }

        for(int i = 0;i < N;i++){
            int x,y,p;
            cin >> x >> y >> p;

            arr[y][x]=p;

            for(int i = -d;i <= d;i++){
                for(int j = -d;j <= d;j++){
                    dp[y+i][x+j]+=p;
                }
            }
        }

        int tmax = -999999999;
        int l,a;

        for(int i = 0;i < MAXI;i++){
            for(int j = 0;j < MAXI;j++){
                if(arr[i][j]>tmax){
                    tmax=arr[i][j];
                    l=i;
                    a = j;
                }
            }
        }
        cout << a << " " << l << " ";
        cout << tmax <<endl;
    }
    return 0;
}
