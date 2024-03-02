#include<bits/stdc++.h>
using namespace std;
typedef double db;

int main() {
    int t = 1;
    while(t--) {
        int n; cin>>n;
        if(n >= 10) {
            cout<<1<<' '<<2<<' '<<3<<'\n';
        }
        else if(n != 2 and n != 4) cout<<33<<' '<<55<<' '<<77<<'\n';
        else cout<<1<<' '<<20<<' '<<30<<'\n';
    }
    // cout<<(33 + 77) / db(55)<<' '<<(77 + 55) / db(33)<<'\n';
    return 0;
}