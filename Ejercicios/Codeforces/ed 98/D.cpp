#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

static const int p=998244353;

ll mul(ll a, ll b){
    return ((a*b)%p+p)%p;
}

ll memo[int(1e5)];
ll bin(int a, int k){ //a^k
    ll& ans=memo[k];
    if(ans!=-1) return ans;
    if(k==1) return ans=a;
    if(k%2==0) return ans=mul(bin(a,k/2),bin(a,k/2));
    return ans=mul(mul(bin(a,k/2),bin(a,k/2)),k);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    memset(memo, -1, sizeof memo);
    ll fib[n+1];
    fib[1]=1; fib[2]=2;
    for(int i=3;i<=n;i++) fib[i]=fib[i-1]+fib[i-2];

    cout<<



    return 0;
}