#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll b; cin>>b;
    int k=0;
    for(int i=1;i<=sqrt(b);i++){
        if(b%i==0 && i != sqrt(b)) k+=2;
        else if(b%i==0) k++;
    }

    cout<<k<<"\n";



    return 0;
}