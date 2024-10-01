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
    int t; cin>>t;
    vi A;
    for(int i = 2; 7 * i <= 999; i++) A.push_back(7 * i);
    vector<vi> AD;
    for(auto u: A) {
        vi aux(3);
        rep(i, 3) aux[i] = u % 10, u /= 10; 
        AD.push_back(aux);
    }

    while(t--) {
        ll n; cin>>n;
        if(n % 7 == 0) { cout<<n<<'\n'; continue; } 
        vi D(3);
        ll aux = n;
        rep(i, 3) D[i] = aux % 10, aux /= 10;
        ll mini = 4, ans = -1;
        ll digits = D[2] != 0? 3: 2;
        rep(i, AD.size()) {
            cerr<<i<<'\n';
            if(digits == 3) while(AD[i][2] == 0) i++;
            vi u = AD[i];
            ll dif = (u[0] != D[0]) + (u[1] != D[1]) + (u[2] != D[2]);
            if(dif < mini) mini = dif, ans = A[i]; 
        }
        cout<<ans<<'\n';
    }


    return 0;
}