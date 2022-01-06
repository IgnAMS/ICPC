#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int n;
ll l;
vector<ll> A;

bool check(double d){
    if(A[0]>d) return 0;
    rep(i,n-1){
        if(A[i+1]-A[i] > 2*d) return 0;
    }
    if(l>A[n-1]+d) return 0;

    return 1;
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(14);
    cin>>n>>l;
    A.resize(n); rep(i,n) cin>>A[i];
    sort(A.begin(),A.end());
    double i=0, j=l+1, m;
    rep(_, 400){
        m=(i+j)/2;
        if(check(m)) j=m;
        else i=m;
    }
    cout<<(i+j)/2<<"\n";




    return 0;
}