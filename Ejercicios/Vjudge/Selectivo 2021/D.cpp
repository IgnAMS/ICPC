#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

vector<ii> DP(200010);
int n; 
vector<int> A;

ii dp(int i, int sum){
    sum+=A[i];
    if(i==n-1){ return {(sum%3==0), sum}; }
    //cout<<i<<" "<<sum<<"\n";
    if(DP[i].ff != -1) return DP[i];
    DP[i] = { dp(i+1,0).ff + bool(sum%3==0), 0};
    DP[i] = { dp(i+1,0).ff+bool(sum%3==0), 0}; 
    

    DP[i]=max(DP[i], dp(i+1,sum));
    return DP[i];
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string linea; cin>>linea;
    n = linea.length(); A.resize(n);
    rep(i,n) A[i]= linea[i]-'0';
    memset(DP, -1, sizeof DP);
    int i=0;
    rep(i,n){

    }


    return 0;
}