#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    int n; cin>>n;
    vector<int> arr(int(1e5+3),0);
    int h;
    unordered_set<int> mas4;
    unordered_set<int> mas2;
    rep(i,n){
        cin>>h;
        arr[h]++;
        if(arr[h]>=2) mas2.insert(h);
        if(arr[h]>=4) mas4.insert(h);
    }

    int q; cin>>q;
    char sig;
    while(q--){
        cin>>sig>>h;
        if(sig=='+'){
            arr[h]++;
            if(arr[h]>=2) mas2.insert(h);
            if(arr[h]>=4) mas4.insert(h);
        } 
        if(sig=='-'){
            arr[h]--;
            if(mas2.count(h) && arr[h]<2){
                mas2.erase(h);
            }
            if(mas4.count(h) && arr[h]<4){
                mas4.erase(h);
            }
        }
        if(!mas4.size()){
            cout<<"NO"<<endl;
            continue;
        } 

        if(mas4.size()==1 && mas2.size()==1){
            if(arr[*mas4.begin()]>=8){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        if(mas4.size()==1 && mas2.size()==2){
            if(arr[*mas4.begin()]>=6){
                cout<<"YES"<<endl;
                continue;
            }
            else{
                cout<<"NO"<<endl;
                continue;
            }
        }
        else{
            cout<<"YES"<<endl;
            continue;
        }
    }

    return 0;
}