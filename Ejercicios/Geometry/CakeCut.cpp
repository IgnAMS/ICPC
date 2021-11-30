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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    while(cin>>n){
        vector<ll> X(n), Y(n); rep(i,n) cin>>X[i]>>Y[i];
        ll area = 0;
        rep(i, n) area += X[i] * Y[(i+1)%n] - Y[i] * X[(i+1)%n];

        ll j = 1;
        ll curr = 0;
        ll a = 0, b = 0;
        ll maxi = 0;
        rep(i, n){
            ll dx = X[i] - X[(i+1)%n], dy = Y[i] - Y[(i+1)%n];
            ll dxj = X[(j)%n] - X[(j+1)%n], dyj = Y[(j)%n] - Y[(j+1)%n];
            a = dx, b = dy;
            ll mini = 1e17;
            a = X[(j)%n] - X[i], b = Y[(j)%n] - Y[i];
            while(2 * (curr + abs(a * dyj - dxj * b)) < area){
                curr += abs(a * dyj - dxj * b);
                mini = min(mini, max(curr, area - curr));
                j++; 
                dxj = X[(j)%n] - X[(j+1)%n], dyj = Y[(j)%n] - Y[(j+1)%n];
                a = X[(j)%n] - X[i], b = Y[(j)%n] - Y[i];
            }
            mini = min((curr, area - curr), max(curr + abs(a * dyj - dxj * b), area - curr - abs(a * dyj - dxj * b)));
            maxi = max(maxi, mini);
            a = X[(j)%n] - X[i], b = Y[(j)%n] - Y[i];
            curr -= abs(dx * b - dy * a);
            j %= n;
        }
        cout<<maxi<<' '<<area - maxi<<'\n';
    }

    return 0;
}