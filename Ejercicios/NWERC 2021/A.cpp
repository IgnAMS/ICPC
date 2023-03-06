#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

string abc = "";

ll get_time() {
    string a, b, c, d; cin>>a>>b;
    if(b == "GRANTED") return -1;
    else cin>>c>>d;
    string c2 = "";
    for(int i = 1; i < c.length(); i++) c2 += c[i];
    ll ans = 0;
    for(auto u: c2) ans = (ans * 10) + u - '0';
    return ans;
}

int main() {
    for(char c = 'a'; c <= 'z'; c++) abc += c;
    for(char c = 'A'; c <= 'Z'; c++) abc += c;
    for(char c = '0'; c <= '9'; c++) abc += c;
    // cout<<abc<<'\n';
    ll largo = 0;
    string pass = "A";
    for(int i = 0; i < 20; i++) {
        cout<<pass<<endl;
        ll t = get_time();
        if(t == -1) return 0;
        if(t != 5) break;
        pass += 'A';
    }
    cout<<pass<<endl;
    ll t = get_time();
    while(t != -1) {
        ll ind = (t - 5) / 9 - 1;
        for(auto j: abc) {
            pass[ind] = j;
            cout<<pass<<endl;
            t = get_time();
            if(t == -1) return 0;
            if((t - 5) / 9 - 1 != ind) {
                ind = (t - 5) / 9 - 1;
                break;
            }
        }
    }
}

// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

