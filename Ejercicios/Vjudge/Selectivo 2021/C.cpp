#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    for(int i=n/2+(n%2); i<=n; i++){
        if(i%m==0) { cout<<i<<"\n"; return 0; }
    }
    cout<<-1<<"\n";

    return 0;   
}