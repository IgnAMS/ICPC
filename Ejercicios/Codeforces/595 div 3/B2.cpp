#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second



int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int P[n]; rep(i,n) { cin>>P[i]; P[i]--; }
        int D[n]; memset(D, -1, sizeof D);
        rep(i, n){
            if(D[i] == -1){
                vector<int> A;
                int u = i;
                while(P[u] != i) { A.push_back(u); u = P[u]; }
                rep(i, A.size()) D[A[i]] = A.size() + 1;
                D[u] = A.size() + 1;
            }
            cout<<D[i]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}