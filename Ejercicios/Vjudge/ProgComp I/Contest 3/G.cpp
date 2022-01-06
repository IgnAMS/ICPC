#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define ff first
#define ss second


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    while(cin>>n>>m && n+1 && m+1){
        vector<int> A(n); rep(i,n) cin>>A[i];
        sort(A.begin(), A.end());
        priority_queue<iii> pq;
        rep(i,n) pq.push({{A[i]/1,A[i]},1}); //numero de divisiones
        rep(i,m-n){
            iii u = pq.top(); pq.pop();
            //cout<<u.ff.ss/(u.ss+1) + bool(u.ff.ss%(u.ss+1))<<"\n";
            pq.push({{u.ff.ss/(u.ss+1) + bool(u.ff.ss%(u.ss+1)), u.ff.ss},u.ss+1});
        }
        cout<<pq.top().ff.ff<<"\n";

    }





    return 0;
}