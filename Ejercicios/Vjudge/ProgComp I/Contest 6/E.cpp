#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int A[n]; rep(i,n) cin>>A[i];
        set<int> s; rep(i,n) s.insert(A[i]);
        bool encontrado=0;
        repx(k,1,1025){
            bool flag=0;
            rep(i,n) {
                if(!s.count(A[i]^k)) flag=1;
            }
            if(flag) continue;
            cout<<k<<"\n"; 
            encontrado=1;
            break; 
        }
        if(!encontrado) cout<<-1<<"\n";        
    }




    return 0;
}