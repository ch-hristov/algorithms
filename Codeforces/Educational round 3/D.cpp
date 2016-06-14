    #include <iostream>
    #include <algorithm>
    #include <vector>

    using namespace std;

    const int maxi = 10e5 * 2 + 8;
    int cp[maxi],cd[maxi];

    int main(){

        int days,gadgets,neededGadgets,money;
        cin >> days >> gadgets >> neededGadgets >> money;
        pair<int,int> mind,minp;
        mind=make_pair(10e9 + 7,-1);
        minp=make_pair(10e9 + 7,-1);

        for(int i = 0;i < days;i++){
            cin >> cd[i];

            if(cd[i]<mind.first){
                mind = make_pair(cd[i],i+1);
            }
        }

        for(int i = 0;i < days;i++){
            cin >> cp[i];
            if(cp[i]<minp.first){
                minp=make_pair(cp[i],i+1);
            }
        }

        vector< pair<int,int> > dol,pou;

        for(int i = 0;i < gadgets;i++){
            int ti,ci;
            cin >> ti >> ci;
            if(ti)dol.push_back(make_pair(ci,i+1));
            else pou.push_back(make_pair(ci,i + 1));
        }

        sort(dol.begin(),dol.end());
        sort(pou.begin(),pou.end());
        bool invalid = false;
        int i,j,cnt = 0;

        vector< pair <int,int> > ans;

        while(cnt != neededGadgets){

            if(money < 0){
                invalid = true;
                break;
            }

            int nextd = 10e9 + 7;
            int nextp = 10e9 + 7;

            if(i < dol.size())nextd = dol[i].first;
            if(j < pou.size())nextp = pou[j].first;

            if(nextp<nextd){
                ans.push_back(make_pair(dol[i].second,minp.second));
                money -= dol[i].first;
            }
            else{
                ans.push_back(make_pair(pou[i].second,mind.second));
                money -= pou[i].first;
            }
            cnt++;
        }

        if(invalid)cout<<-1<<endl;
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<ans[i].second<<endl;
            }
        }
    }
