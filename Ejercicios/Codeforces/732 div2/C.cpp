#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b;i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> A(n), B(n);
        map<int,int> cont;
        map<int,int> imp;
        rep(i,n) {
            cin>>A[i]; B[i] = A[i];
            if(!cont.count(A[i])) cont[A[i]] = 0;
            cont[A[i]]++;
            imp[A[i]] = 0;
        }
        sort(B.begin(), B.end());
        bool flag = true;
        
        rep(i,n) {
            int lower = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
            imp[A[i]] += abs(lower - i)%2 == 1;
        }
        for(auto& u: imp){
            if(u.ss != cont[u.ff]/2) flag = false;   
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }





    return 0;
}