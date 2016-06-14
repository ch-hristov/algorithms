#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    string f,s;
    scanf("%s",&f);
    scanf("%s",&s);
    int z = f.size();
    int k = s.size();
    for(int i = 0;i < f.size();i++)if(f[i]=='0')z--;
    for(int j = 0;j < s.size();j++)if(s[j]=='0')k--;
    if(z>k)cout<<">"<<endl;
    else if(z<k) cout <<"<"<<endl;
    else{
        if(f[f.size()-z-1] > s[s.size()-k-1]){
            cout << ">" << endl;
        }
        else{
            if(f[f.size()-z-1]<s[s.size() - k - 1]) cout <<"<"<<endl;
            else cout <<"-"<<endl;
        }
    }
    return 0;
}
