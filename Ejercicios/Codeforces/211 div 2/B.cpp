#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;


int main(){
    int n, k; cin>>n>>k;
    ll arr[n];
    rep(i,0,n) cin>>arr[i];
    ll suma=0;
    rep(i,0,k) suma+=arr[i];
    int ind=0;
    ll curr=suma;
    rep(i,k,n){
        curr-=arr[i-k];
        curr+=arr[i];
        if(curr<suma){
            suma=curr;
            ind=i-k+1;
        }
    }
    cout<<ind+1<<endl;

    return 0;
}