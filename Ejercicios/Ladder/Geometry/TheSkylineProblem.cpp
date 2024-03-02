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


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<vector<int>> E;
    int l, h, r;
    while(cin>>l>>h>>r){
        E.push_back({l, 0, h});
        E.push_back({r, 1, h});
    }
    sort(E.begin(), E.end());
    
    int t = 0, prev = 0;
    vector<int> ans;
    int i = 0;
    multiset<int> S;
    while(i < E.size()){
        prev = t; 
        t = E[i][0];
        int h_max = (S.size()? *S.rbegin(): 0);
        while(i < E.size() and E[i][0] == t) {
            if(E[i][1]) S.erase(S.find(E[i][2]));
            else S.insert(E[i][2]);
            i++;
        }
        int curr_h = (S.size()? *S.rbegin(): 0);
        if(curr_h != h_max){
            ans.push_back(t); ans.push_back(curr_h);
        }
    }
    rep(i, ans.size()){
        cout<<ans[i]<<" \n"[i + 1 == ans.size()];
    }

    return 0;
}