#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include<algorithm>
#include<numeric>
#include <unordered_map>
#include <cmath>
#include<set>
#include<array>
using namespace std;
// g++ -std=c++17 F.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -std=c++17 -O2 F.cpp && time ./a.out <input.txt> output.txt

// https://codeforces.com/gym/640342/attachments/download/33659/main.pdf

#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define repx(i, a, b) for(int i = (int)a; i < (int)b; ++i)
#define pb push_back
typedef pair<ll, ll> pll; 
typedef vector<int> vi;

const int mxN = 1000;
int n;

struct P {
    ll x, y;
    P(): x(0), y(0) {}
    ll dist(const P& p){
        return (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y);
    }
};

struct Inter {
    int i1, i2;
    ll t;
};

P Points[mxN];
ll last[mxN];


int main() {
    cin>>n;
    rep(i, n) {
        cin>>Points[i].x>>Points[i].y;
        last[i] = -1;
    }

    vector<Inter> intersections;
    rep(i, n) repx(j, i + 1, n) {
        intersections.pb({i, j, Points[i].dist(Points[j])});
    }

    sort(intersections.begin(), intersections.end(), [&](const Inter p1, const Inter p2){
        return p1.t < p2.t;
    });

    ll cont = 0;
    ll prev = 0;
    for(auto [i1, i2, time]: intersections) {
        // cout<<"i1: "<<i1<<", i2: "<<i2<<", lasti1: "<<last[i1]<<", lasti2: "<<last[i2]<<", time: "<<time<<"\n";
        
        if(last[i1] == -1 and last[i2] == -1) {
            if(prev != time) cont++;
            prev = last[i1] = last[i2] = time;
        }
        // check if the time works
        else if(last[i1] != -1 and last[i2] == -1 and last[i1] == time) {
            prev = last[i2] = time;
        }
        else if(last[i1] == -1 and last[i2] != -1 and last[i2] == time) {
            prev = last[i1] = time;
        }
    }
    cout<<cont<<'\n';


}