#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 D.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int winner(vi &B) {
    cout<<"? "<<B[0]<<' '<<B[2]<<endl;
    int ans1; cin>>ans1;
    if(ans1 == 1) { // gano el 1 ante el 3
        cout<<"? "<<B[0]<<' '<<B[3]<<endl;
        int ans2; cin>>ans2;
        if(ans2 == 1) return B[0];
        else return B[3];
    }
    else if(ans1 == 2) {
        cout<<"? "<<B[1]<<' '<<B[2]<<endl;
        int ans2; cin>>ans2;
        if(ans2 == 1) return B[1];
        else return B[2];
    }
    else {
        cout<<"? "<<B[1]<<' '<<B[3]<<endl;
        int ans2; cin>>ans2;
        if(ans2 == 1) return B[1];
        else return B[3];
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        n = (1LL << n);
        vi A(n); rep(i, n) A[i] = i + 1;
        while(A.size() > 1) {
            vi B;
            vi C;
            while(A.size() >= 4) {
                rep(i, 4) {
                    B.push_back(A.back()); 
                    A.pop_back();
                }
                C.push_back(winner(B));
                B.clear();
            }
            if(!A.empty()) {
                cout<<"? "<<A[0]<<' '<<A[1]<<endl;
                int ans; cin>>ans;
                if(ans == 1) C.push_back(A[0]);
                else C.push_back(A[1]);
            }
            A = C;
        }
        cout<<"! "<<A[0]<<endl;
    }





    return 0;
}