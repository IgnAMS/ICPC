#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int maxi = 0;
    int A[n]; rep(i,n) { cin>>A[i]; maxi=max(A[i],maxi); }
    int sumatoria = 0; 
    rep(i,n) sumatoria+=A[i];
    while(sumatoria >= maxi*n - sumatoria) maxi++;
    cout<<maxi<<"\n";



    return 0;
}