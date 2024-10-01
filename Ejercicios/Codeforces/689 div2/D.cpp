#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int cont=0;
void backtrack(set<ll>& ans, set<ll>& s,vector<ll>& C){
    cont++;
    int mini=*s.begin(), maxi= *s.rbegin();
    int mid=(mini+maxi)/2;
    ll ans1=0;
    for(auto& u: s) ans1+=C[u]*u;   
    ans.insert(ans1);
    if(mini==maxi) return;
    set<ll> s1, s2;
    for(auto& u: s) u<=mid? s1.insert(u):s2.insert(u); 
    backtrack(ans,s1,C); backtrack(ans,s2,C); 
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m; cont=0;
        set<ll> s;
        set<ll> ans;
        vector<int> A(n);
        vector<ll> C(1e6,0);
        ll sum1=0;
        rep(i,n) { cin>>A[i]; C[A[i]]++; s.insert(A[i]); }
        backtrack(ans,s,C);
        rep(i,m){
            int q; cin>>q;
            if(ans.count(q)) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }




    return 0;
}