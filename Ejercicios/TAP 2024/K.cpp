#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double db;
typedef pair<ll, ll> pll;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back


int n, m;
string mat[1005];
// const vector<pll> T = {
//     {-4, 0}, {-4, 1}, {-4, 2},
//              {-3, 1}, 
//              {-2, 1}, 
//              {-1, 1}, 
//              {0, 1}, 
// };
// const vector<pll> A = {
//     {-4, 0}, {-4, 1}, {-4, 2},
//     {-3, 0},          {-3, 2},
//     {-2, 0}, {-2, 1}, {-2, 2}, 
//     {-1, 0},          {-1, 2},
//     {0, 0},           {0, 2}
// };
// 
// const vector<pll> P = {
//     {-4, 0}, {-4, 1}, {-4, 2},
//     {-3, 0},          {-3, 2},
//     {-2, 0}, {-2, 1}, {-2, 2}, 
//     {-1, 0}, 
//     {0, 0}
// };
// 
// vector<vector<pll>> Figures = {T, A, P};

const vector<array<ll, 3>> T = {
{-4, 0, 0},	{-4, 1, 0},	{-4, 2, 0},	
{-3, 0, 1},	{-3, 1, 0},	{-3, 2, 1},	
{-2, 0, 1},	{-2, 1, 0},	{-2, 2, 1},	
{-1, 0, 1},	{-1, 1, 0},	{-1, 2, 1},	
{0, 0, 1},	{0, 1, 0},	{0, 2, 1},	
};

const vector<array<ll, 3>> A = {
{-4, 0, 0},	{-4, 1, 0},	{-4, 2, 0},	
{-3, 0, 0},	{-3, 1, 1},	{-3, 2, 0},	
{-2, 0, 0},	{-2, 1, 0},	{-2, 2, 0},	
{-1, 0, 0},	{-1, 1, 1},	{-1, 2, 0},	
{0, 0, 0},	{0, 1, 1},	{0, 2, 0},	
};

const vector<array<ll, 3>> P = {
{-4, 0, 0},	{-4, 1, 0},	{-4, 2, 0},	
{-3, 0, 0},	{-3, 1, 1},	{-3, 2, 0},	
{-2, 0, 0},	{-2, 1, 0},	{-2, 2, 0},	
{-1, 0, 0},	{-1, 1, 1},	{-1, 2, 1},	
{0, 0, 0},	{0, 1, 1},	{0, 2, 1},	
};

vector<vector<array<ll, 3>>> Figures = {T, A, P};



array<ll, 3> ans;
array<ll, 3> curr = {0, 0, 0};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, n) cin>>mat[i];

    for(int i = n - 1; i >= 4; i--) for(int j = 0; j <= m - 3; j++) {
        rep(k, 3) {
            // cout<<"estoy en la posicion "<<i<<' '<<j<<" y pruebo poner la figura "<<k<<'\n';
            bool pos = 1;
            for(auto [a, b, type]: Figures[k]) if(mat[i + a][j + b] != (type? '.': '#')) {
                pos = 0;
                break;
            }
            if(pos) {
                // cout<<"se puede poner la figura "<<k<<" en la posicion "<<i<<" "<<j<<'\n';
                for(auto [a, b, type]: Figures[k]) mat[i + a][j + b] = '.';
                ans[k]++;
            }
        }
    }

    cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<'\n';

    return 0;
}

