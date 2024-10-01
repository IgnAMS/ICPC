#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
#define ss second
#define ff first

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> A(n), B(n); 
        int suma=0, sumb=0;
        rep(i,n) { cin>>A[i]; suma+=A[i]; }
        rep(i,n) { cin>>B[i]; sumb+=B[i]; }
        if(suma != sumb) { cout<<"-1\n"; continue; }
        map<int,int> aumentar, disminuir;
        int movimientos = 0;
        rep(i,n){
            if(A[i] > B[i]) disminuir[i] = A[i] - B[i];
            if(A[i] < B[i]) aumentar[i] = B[i] - A[i];
            movimientos += abs(B[i] - A[i]);
        } 
        cout<<movimientos/2<<'\n';
        cerr<<"sorbevivi aca\n";
        for(auto& u: aumentar){
            while(u.ss) {
                if((*disminuir.begin()).ss == 0) disminuir.erase(disminuir.begin());
                cout<<(*disminuir.begin()).ff + 1<<" "<<u.ff + 1<<"\n";
                (*disminuir.begin()).ss--;
                u.ss--;
            }
        }
    }
    return 0;
}