#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
#define ff first
#define ss second



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){ // n = 10^3
        int n; cin>>n;
        vector<int> A(n); rep(i, n) cin>>A[i];
        bool oc = 1;
        rep(i, n-1) if(A[i] > A[i+1]) oc = 0;
        int i = 0;
        // cout<<"aaa\n";
        while(!oc){ // no deberia demorarse mas de 2 * n
            rep(j, n/2) if(2 * j + (i%2) + 1 < n){
                //cout<<2 * j + (i%2) + 1<<'\n';
                if(A[2*j+(i%2)+1] < A[2*j+(i%2)]) swap(A[2*j+(i%2)], A[2*j+(i%2)+1]);
            }
            //rep(i, n) cout<<A[i]<<' '; cout<<'\n';
            oc = 1;
            rep(i, n-1) if(A[i] > A[i+1]) oc = 0; 
            i++;
        }
        cout<<i<<'\n';
        

    }





    return 0;
}