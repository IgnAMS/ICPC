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

bool win(int a, int b, int c, int x, int y, int z){
    if(a > x and b > y) return 0;
    if(a > x and b > z) return 0;
    if(a > y and b > z) return 0;
    
    if(a > y and b > x) return 0;
    if(a > z and b > x) return 0;
    if(a > z and b > y) return 0;
    
    if(a > x and c > y) return 0;
    if(a > x and c > z) return 0;
    if(a > y and c > z) return 0;

    if(a > y and c > x) return 0;
    if(a > z and c > x) return 0;
    if(a > z and c > y) return 0;
    
    if(b > x and c > y) return 0;
    if(b > x and c > z) return 0;
    if(b > y and c > z) return 0;

    if(b > y and c > x) return 0;
    if(b > z and c > x) return 0;
    if(b > z and c > y) return 0;
    
    return 1;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, c, x, y;
    while(cin>>a>>b>>c>>x>>y and a){
        int ans = -1;
        repx(i, 1, 53) if(i != a and i != b and i != c and i != x and i != y){
            if(win(a, b, c, x, y, i)) { ans = i; break; }
        }
        cout<<ans<<'\n';
    }





    return 0;
}