#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c,d; cin>>a>>b>>c>>d;
    cout<<min({
        abs(a+b-c-d),
        abs(a+c-b-d),
        abs(a+d-c-b)
        })<<"\n";



    return 0;
}