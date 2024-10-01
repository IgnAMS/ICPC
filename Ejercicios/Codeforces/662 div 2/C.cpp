#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
typedef long long ll;


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        map<int,int> conts;
        int maxrep=0;
        rep(i,n){
            cin>>arr[i];
            if(!conts.count(arr[i])){
                conts.insert({arr[i],0});
            }
            conts[arr[i]]++;
        }
        map<int,int> asd;
        for(auto x: conts){
            if(!asd.count(x.ss)){
                asd.insert({x.ss,0});
            }
            asd[x.ss]++;
        }

        cout<<(*asd.end()).ss<<endl;

    }

    return 0;
}