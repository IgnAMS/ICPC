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
       int ind = -1;
       rep(i, n-1) if(A[i] == 0 and A[i+1] == 1) ind = i;
       if(A[0] == 1) {
           cout<<n+1;
           repx(i, 1, n+1) cout<<' '<<i;
           cout<<'\n';
       }
       else if(A[n-1] == 0){
           repx(i, 1, n+1) cout<<i<<' ';
           cout<<n+1<<'\n';
       }
       else if(ind != -1){
           repx(i, 1, ind + 2) cout<<i<<' ';
           cout<<n + 1<<' ';
           repx(i, ind + 2, n + 1) cout<<i<<' ';
           cout<<'\n';
       }
       else cout<<"-1\n";

   } 






    return 0;
}