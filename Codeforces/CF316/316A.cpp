#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class node{


public:
    char* value;
    int innerCount = 0;
    int length =0;
    node(){

    }
    node(char* data){
        this->value = data;
    }
};

class segTr {

private:
    node* structure;

public:
    segTr(){

    }

    node construct(char* data,int left,int right){
        if(left==right){
            char d[1];
            d[0]=data[left];
            structure[left] = node(d);
            structure[left].length = 1;
            return structure[left];
        }
        else{
            int mid = (left + right) >> 1;
            node l = construct(data,left,mid);
            node r = construct(data,mid+1,right);
            int counter = l.innerCount + r.innerCount;
            if(l.value[l.length - 1] == r.value[0] && r.value[0]=='.')
                counter++;
            char* d = new char[l.length + r.length];
            int rg = l.length;
            for(int i = 0;i<l.length;i++)
                d[i] = l.value[i];
            for(int i = 0 ;i< r.length;i++)
                d[rg++]= r.value[i];
            node newn = node();
            newn.value = d;
            newn.length = rg;
            structure[mid]=newn;
            return newn;
        }
    }

    int calculate(){

    }

    int query(int index,char value){

    }
};

int main(){
    int n,m;
    cin >> n >> m;
    char s[n];
    cin >> s;

    segTr* st = new segTr();
    st->construct(s,0,n-1);

    for(int i = 0;i < m;i++){
        int xi;
        char ci;
        cin >> xi >> ci;
        st->query(xi,ci);
        int a = st->calculate();
        cout << a << endl;

    }
    return 0;
}
