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
        int A[n]; rep(i,n) cin>>A[i];
        int x = A[0];
        rep(i, n) x = x & A[i];
        cout<<x<<'\n';
    }






    return 0;
}