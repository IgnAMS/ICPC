#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define repx(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    if(n%2) { cout<<"0\n"; return 0; }
    n/=2; 
    cout<<(1<<n)<<"\n";




    return 0;
}