#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++14 H.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string comand;
    cin>>comand;
    while(comand == "start") {
        int b;
        for(b = 0; b < 30; b++) {
            cout<<"? "<<(1<<(b))<<" "<<(1<<(b+1))<<endl;
            string ans; cin>>ans;
            if(ans == "x") break;
        }
        if(b == 0) {
            cout<<"? "<<2<<" "<<1<<endl;
            string ans; cin>>ans;
            if(ans == "x") cout<<"! 1"<<endl;
            else cout<<"! 2"<<endl;
        }
        else {
            ll l = (1<<b), r = (1<<(b+1)) - 1;
            while(b) {
                b--;
                cout<<"? "<<l<<' '<<(l + (1<<b))<<endl;
                string ans; cin>>ans;
                if(ans == "y") l += (1<<b);
            }
            cout<<"! "<<l + 1<<endl;
        }
        
        cin>>comand;
    }


    return 0;
}