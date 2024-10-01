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
        int a, b; cin>>a>>b;
        cout<<(a + b - 1) / b * b - a<<'\n';
    }
    return 0;
}