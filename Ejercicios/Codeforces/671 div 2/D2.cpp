#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    int n; cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    sort(a.begin(), a.end(), greater<int>());
    vector<int> b(n);
    int j=0;
    for(int i=0;i<n;i+=2,j++){
        b[i]=a[j];
    }
    for(int i=1;i<n;i+=2,j++){
        b[i]=a[j];
    }
    int cont = 0;
    for(int i = 1; i < n - 1; i++){
        if(b[i-1]>b[i] && b[i]<b[i+1]) cont++;
    }
    cout<<cont<<"\n";
    rep(i, n) cout<<b[i]<<" "; cout<<"\n";



    return 0;
}