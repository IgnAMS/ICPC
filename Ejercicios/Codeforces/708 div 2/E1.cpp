#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

vector<int> primes;
const int maxa=1e7;
int mind[maxa+1];



int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=2; i<=maxa;i++){
        if(mind[i]==0){    
            primes.emplace_back(i);
            mind[i]=i;
        }
        for(auto& x: primes){
            if(x>mind[i] || x*i>maxa) break;
            mind[x*i]=x;
        }
    }
    rep(i,100)
        cout<<mind[i]<<"\n";

    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> A(n,1);
        /* 
        rep(i,n){
            int x; cin>>x;
            int cont=0, last=0;
            while(x>1){
                int p=mind[x];
                if(last==p) cont++;
                else{
                    if(cont%2==1) a[]
                }
            }
        } 
        */
    }

    return 0;
}