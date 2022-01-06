#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;


int main(){
    int n; cin>>n;
    int i=0;
    while(n >= (i+1)*(i+2) / 2) i++;
    cout<<i<<"\n";
    rep(j, i-1){
        cout<<(j+1)<<" ";
    }
    cout<<n-(i-1)*i/2<<"\n";


    return 0;
}