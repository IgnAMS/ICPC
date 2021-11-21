#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<int> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 HQueries.cpp && time ./a.out < input.txt > output.txt

vi d1, d2;
void Manacher(string& s){
    int n = s.length();
    d1.assign(n, 0); d2.assign(n, 0);
    for(int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
        d1[i] = k--;
        if (i + k > r) l = i - k, r = i + k;
    }
    for(int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
        d2[i] = k--;
        if (i + k > r) l = i - k - 1, r = i + k ;
    }
}

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*5001 + v.second;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s; 
    int n = s.length();
    Manacher(s);
    vector<vector<int>> Acc(n+1, vector<int>(n+1, 0));
    rep(i, n) { // 2.5 * 10^7 * set.find
        rep(j, n) { // que empiece en i y termine en n-j-1
            int k = n - j - 1;
            int aux = 0;
            if(i <= k){
                aux = (k-i+1) % 2 == 1? d1[(i+k)/2] * 2 - 1 >= (k-i+1): d2[(i+k)/2+1] * 2 >= (k-i+1); 
            }
            Acc[i+1][j+1] = Acc[i][j+1] + Acc[i+1][j] - Acc[i][j] + aux;
        }
    }

    int q; cin>>q;

    rep(i, q){
        int a, b; cin>>a>>b;
        int r1 = a, c1 = n-b+1, r2 = b, c2 = n-a+1;
        cout<<Acc[r2][c2] - Acc[r1-1][c2] - Acc[r2][c1-1] + Acc[r1-1][c1-1]<<'\n';
    }

    return 0;
}