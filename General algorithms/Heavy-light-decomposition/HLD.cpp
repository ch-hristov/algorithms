#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

const int N = 10e4;
std::vector< vector < int > > T(N, vector<int>(N,-1));
std::vector<int> subSize;

int chainNum=0;
int chainHead[N] = {-1};
int chainPos[N];
int chainInd[N];
int chainSize[N] = {0};

int V[N];

int setSubsize(int n){

    V[n] = 1;

    if(T[n].size()==0){
        subSize[n]=0;
        return 0;
    }


    int s = 0;

    for(int i = 0;i < T[n].size();i++){
        if(!V[T[n][i]]){
            s += setSubsize(T[n][i]) + 1;
        }
    }

    return s;
}


void solve(int cur){

    if(chainHead[ chainNum ]== -1)
        chainHead[chainNum]=cur;

    chainInd[cur] = chainNum;
    chainPos[cur] = chainSize[chainNum];
    chainSize[chainNum]++;

    int ind,mai = -1;

    for(int i = 0;i < T[cur].size();i++){
        if(subSize[T[cur][i]] > mai){
            mai = subSize[T[cur][i]];
            ind = i;
        }
    }

    if(ind >= 0) solve( T[cur][ind] );

    for(int i = 0;i < T[cur].size();i++){
        if(i != ind){
            chainNum++;
            solve( T[cur][i] );
        }
    }


}

std::vector<std::string> split(const std::string &text, char sep) {
      std::vector<std::string> tokens;
      int start = 0, end = 0;
      while ((end = text.find(sep, start)) != std::string::npos) {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
      }
      tokens.push_back(text.substr(start));
      return tokens;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        for(int i = 0;i < N - 1;i++){

            int si,ti,pi;
            cin >> si >> ti >> pi;

            T[si][ti]=pi;
            T[ti][si]=pi;

        }

        setSubsize(n);

        solve(0);

    }

    return 0;
}
