#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

vi uno(string& s, ll x, vector<ll>& A) {
    ll lx = 0, rx = 0;
    int n = s.size() / 3;
    vi B(3, 0);
    // cout<<"analizo a "<<char('A' + x)<<'\n';
    for(ll i = 0; i < s.size(); i++) {
        B[s[i] - 'A']++;
        while(lx <= i and i - lx + 1 + A[x] - B[x] > n) B[s[lx++] - 'A']--;
        // cout<<i<<' '<<lx<<' '<<A[x]<<' '<<B[x]<<'\n';
        if((x == 0 or x == 2) and i - lx + 1 + A[x] - B[x] == n and A[1] - B[1] == n) {
            return {1, lx, i};
        }
        if(x == 1 and i - lx + 1 + A[x] - B[x] == n and A[0] - B[0] == n) {
            return {1, lx, i};
        }
    }
    return {0, -1, -1};


}

int main(){

    int n; cin>>n;
    string s; cin>>s;
    
    vi A(3, 0);
    for(auto u: s) A[u - 'A']++;
    if(A[0] == n and A[1] == n) {
        cout<<"0\n";
        return 0;
    }
    for(int i = 0; i < 3; i++) {
        vi X = uno(s, i, A);
        if(X[0]) {
            cout<<1<<'\n';
            cout<<X[1] + 1<<' '<<X[2] + 1<<' '<<char('A' + i)<<'\n';
            return 0; 
        }
    }

    A.assign(3, 0);
    for(int i = 0; i < s.size(); i++) {
        A[s[i] - 'A']++;
        if(A[s[i] - 'A'] == n) {
            cout<<2<<'\n';
            if(s[i] == 'A') {
                cout<<i + 2<<' '<<3 * n<<" B\n";
                cout<<3 * n - (n - A[2] - 1)<<' '<<3 * n<<" C\n";
                return 0;
            }
            if(s[i] == 'B') {
                cout<<i + 2<<' '<<3 * n<<" A\n";
                cout<<3 * n - (n - A[2] - 1)<<' '<<3 * n<<" C\n";
                return 0;
            }
            if(s[i] == 'C') {
                cout<<i + 2<<' '<<3 * n<<" A\n";
                cout<<3 * n - (n - A[1] - 1)<<' '<<3 * n<<" B\n";
                return 0;
            }
        }  
    }
    



    return 0;
}