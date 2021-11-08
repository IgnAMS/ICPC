#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt

ll evaluar(vi& A, ll x){
    ll mul = 1, ans = 0;
    rep(i, A.size()){
        ans += A[i] * mul;
        mul *= x;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string line;
    while(getline(cin, line) and line != "="){
        vector<vi> P1, P2;
        vector<char> op1, op2;
        bool sw = 0;
        vi P; 
        rep(i, line.size()){
            if(line[i] == '=') {
                sw = 1;
                reverse(P.begin(), P.end());
                P1.push_back(P); P.clear();
                continue;
            }
            if(!sw){
                if('0' <= line[i] and line[i] <= '9') P.push_back(line[i] - '0');
                else{
                    reverse(P.begin(), P.end());
                    P1.push_back(P); P.clear();
                    op1.push_back(line[i]);
                }
            }
            else{
                if('0' <= line[i] and line[i] <= '9') P.push_back(line[i] - '0');
                else {
                    reverse(P.begin(), P.end());
                    P2.push_back(P); P.clear();
                    op2.push_back(line[i]);
                }
            }
        }
        reverse(P.begin(), P.end()); 
        P2.push_back(P);
        
        vector<ll> ans1;
        rep(i, P1.size()){
            vi aux = P1[i];
            while(i < op1.size() and op1[i] == '*') {
                vi aux_(max(aux.size(), P1[i+1].size()), 0);
                rep(j, aux.size()) rep(k, P1[i+1].size()){
                    aux_[j+k] += aux[j] * P1[i+1][k];
                }
                aux = aux_;
                i++;
            }
            rep(j, aux.size()){
                if(j >= ans1.size()) ans1.push_back(aux[j]);
                else ans1[j] += aux[j]; 
            }
        }

        vector<ll> ans2;
        rep(i, P2.size()){
            vi aux = P2[i];
            while(i < op2.size() and op2[i] == '*') {
                vi aux_(max(aux.size(), P2[i+1].size()), 0);
                rep(j, aux.size()) rep(k, P2[i+1].size()){
                    aux_[j+k] += aux[j] * P2[i+1][k];
                }
                aux = aux_;
                i++;
            }
            rep(j, aux.size()){
                if(j >= ans2.size()) ans2.push_back(aux[j]);
                else ans2[j] += aux[j]; 
            }
        }

        // rep(i, ans1.size()) cout<<ans1[i]<<' '; cout<<'\n';
        vi ans(max(ans1.size(), ans2.size()), 0);
        rep(i, ans1.size()) ans[i] += ans1[i];
        rep(i, ans2.size()) ans[i] -= ans2[i];

        bool triv = 1;
        ll min_base = 2, p = 0, q = 0;
        rep(i, line.size()) if('0' <= line[i] and line[i] <= '9') 
            min_base = max(min_base, ll(line[i] - '0' + 1));

        rep(i, ans.size()) if(ans[i] != 0) triv = 0;
        rep(i, ans.size()) {
            if(p == 0) p = abs(ans[i]);
            if(ans[i] != 0) q = abs(ans[i]);
        }
        if(triv) cout<<min_base<<"+\n";
        else{
            set<ll> dp = {1, p}, dq = {1, q};
            repx(i, 2, sqrt(max(p, q)) + 1){
                if(p % i == 0) { dp.insert(i); dp.insert(p/i); }
                if(q % i == 0) { dq.insert(i); dq.insert(q/i); }
            }
            set<ll> roots;
            for(auto x: dp) for(auto y: dq){
                if(x % y == 0 and evaluar(ans, x/y) == 0) 
                    roots.insert(x/y);
            }
            if(roots.size() == 0) cout<<"*\n";
            else { for(auto x: roots) cout<<x<<' '; cout<<'\n'; }
        }

    }


    return 0;
}