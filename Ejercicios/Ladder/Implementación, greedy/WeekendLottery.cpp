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
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, c, k; 
    while(cin>>n>>c>>k and n) {
        vi Acc(k + 1, 0);  
        rep(i, n) rep(j, c) { 
            int x; cin>>x;
            Acc[x]++;
        }
        vi Ans; 
        ll mn = *min_element(Acc.begin() + 1, Acc.end());
        repx(i, 1, k + 1) {
            if(Acc[i] == mn) Ans.push_back(i);
        }
        rep(i, Ans.size()) cout<<Ans[i]<<" \n"[i == Ans.size() -1];
    }





    return 0;
}