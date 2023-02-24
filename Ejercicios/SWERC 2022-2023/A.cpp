#include<bits/stdc++.h>
using namespace std;


int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int A[n + 2];
        A[0] = 0;
        A[n + 1] = 1440; 
        for(int i = 0; i < n; i++) cin>>A[i + 1];
        int cant = 0;
        for(int i = 0; i < n + 1; i++) cant += (A[i + 1] - A[i]) / 120;
        if(cant >= 2) cout<<"YES\n";
        else cout<<"NO\n";
    }


    return 0;
}