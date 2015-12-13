#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){

    int strc[] = {10,2,5,2,9593,34,321};
    vector<int> v(strc,strc + 7);
    make_heap(v.begin(),v.end());
    while(v.size() > 0){
        cout << v.front() << " " << " popping.." << endl;
        pop_heap(v.begin(),v.end());
        v.pop_back();
    }
    return 0;
}
