#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
#define ff first
#define ss second

char car(char a, char b){
    if(a != 'a' and b != 'a') return 'a';
    if(a != 'b' and b != 'b') return 'b';
    return 'c';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, t; cin>>n>>t; // t son la cantidad diferentes
    string a, b; cin>>a>>b;
    int same = 0, dif; 
    rep(i, n) if(a[i] == b[i]) same++;
    dif = n - same; // la cantidad de iguales no puede ser mayor a iguales + dif/2
    if(n - t > same + dif/2) { cout<<"-1\n"; return 0; }
    string ans = "";
    int cont = 0;
    if(n - t <= same){
        rep(i, n) {
            if(a[i] == b[i] and cont < n - t) ans += a[i], cont++;
            else ans += car(a[i], b[i]); 
        }
    }
    else{
        bool sw = 0;
        rep(i, n){
            if(a[i] == b[i]) ans += a[i];
            else if(cont < 2*(n - t - same)) ans += (sw? a[i]:b[i]), cont++, sw = !sw;
            else ans += car(a[i], b[i]);
        }
    }
    cout<<ans<<'\n';




    return 0;
}