#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;   


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;
    int arr[n];
    unordered_set<int> s;
    int acc[n];

    rep(i,n) cin>>arr[i];
    for(int i=n-1;i>=0;i--){
        s.insert(arr[i]);
        acc[i]=s.size();
    }
    while(m--){
        int q; cin>>q;
        cout<<acc[q-1]<<endl;
    }

    return 0;
}