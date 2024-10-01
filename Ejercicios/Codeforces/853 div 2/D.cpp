#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string a, b; cin>>a>>b;
        string b2 = "";
        int curr = -1, start = -1;
        rep(i, n) {
            if(b[i] == '1' and start == -1) start = i, curr = i;
            if(b[i] == '1') {
                while(curr <= i) b2 += b[curr], curr++;
            }
        }
        if(start == -1) {
            cout<<"1\n";
            cout<<n<<'\n';
            continue;
        }
        if(a == b) {
            cout<<"0\n";
            continue;
        }
        bool logrado = 0;
        rep(i, n - int(b2.length()) + 1) {
            bool oc = 1;
            rep(j, b2.length()) if(b2[j] != a[i + j]) oc = 0;
            if(oc) {
                logrado = 1;
                int left = -i, right = n - i - b2.length();
                if(start == 0) {
                    if(right == 0) { 
                        cout<<"1\n";
                        cout<<left<<'\n';
                    }
                    else { 
                        cout<<"2\n";
                        cout<<right<<' '<<-right + left<<'\n';
                    }
                }
                else if(start + b2.length() == n) {
                    if(i == 0) {
                        cout<<"1\n";
                        cout<<right<<'\n';
                    }
                    else {
                        cout<<"2\n";
                        cout<<left<<' '<<right - left<<'\n';
                    }
                }
                else {
                    if(left == 0) {
                        cout<<"2\n";
                        cout<<right<<' '<<-right + start<<'\n';
                    }
                    else if(right == 0) { 
                        cout<<"2\n";
                        cout<<left<<' '<<start<<'\n';
                    }
                    else { // Esta bien
                        cout<<"3\n";
                        cout<<right<<' '<<-right + left<<' '<<start<<'\n';
                    }
                }
                
            }
        }
        if(!logrado) cout<<"-1\n";
    }


    return 0;
}