#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        set<int> s;
        int arr[n];
        bool flag=0;
        rep(i,n) { 
            cin>>arr[i]; 
            if(s.count(arr[i])) flag=true;
            s.insert(arr[i]);   
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
}