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

    bool border(int x, int y, int w, int h){
        return x == 0 or x == w or y == 0 or y == h;
    }

    int main(){
        ios::sync_with_stdio(0); cin.tie(0);
        ll w, h; cin>>w>>h;
        int n; cin>>n;
        vector<vi> D, U, L, R;
        // D -> R -> U -> L
        rep(i, n) {
            int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
            if(border(x2, y2, w, h)) {
                if(x1 == 0) L.push_back({-y1, i});
                else if(y1 == 0) D.push_back({x1, i});
                else if(x1 == w) R.push_back({y1, i});
                else if(y1 == h) U.push_back({-x1, i});
            }
            if(border(x1, y1, w, h)) {
                if(x2 == 0) L.push_back({-y2, i});
                else if(y2 == 0) D.push_back({x2, i});
                else if(x2 == w) R.push_back({y2, i});
                else if(y2 == h) U.push_back({-x2, i});
            }
        }

        vi S;
        sort(D.begin(), D.end());
        sort(R.begin(), R.end());
        sort(U.begin(), U.end());
        sort(L.begin(), L.end());
        for(auto u: D) {
            if(!S.empty() and u[1] == S.back()) S.pop_back();
            else S.push_back(u[1]);
        }
        for(auto u: R) {
            if(!S.empty() and u[1] == S.back()) S.pop_back();
            else S.push_back(u[1]);
        }
        for(auto u: U) {
            if(!S.empty() and u[1] == S.back()) S.pop_back();
            else S.push_back(u[1]);
        }
        for(auto u: L) {
            if(!S.empty() and u[1] == S.back()) S.pop_back();
            else S.push_back(u[1]);
        }
        if(S.empty()) cout<<"Y\n";
        else cout<<"N\n";
        



        return 0;
    }