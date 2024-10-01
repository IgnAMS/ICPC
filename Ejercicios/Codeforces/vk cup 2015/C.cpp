#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second



int main(){
    int xp, yp, xv, yv; cin>>xp>>yp>>xv>>yv;
    bool ans = 0; // 0 vasily, 1 polycarp
    // if(xv >= yv){ // llega primero a la esquina (xv - yv, 0)
    //     int dx = max(0, xp - (xv - yv));
    //     int dy = max(0, yp - (yv - yv));
    //     if(dx + dy <= yv) ans = 1;
    //     else ans = 0; 
    // }
    // else{ // llega primero a (0, yv - xv)
    //     int dx = max(0, xp - (xv - xv));
    //     int dy = max(0, yp - (yv - xv)); 
    //     if(dx + dy <= xv) ans = 1;
    //     else ans = 0; 
    // }
    if(xp < xv and max(0, yp - (xv - xp)) <= max(0, yv - (xv - xp))) ans = 1;
    if(yp < yv and max(0, xp - (yv - yp)) <= max(0, xv - (yv - yp))) ans = 1;

    if(ans) cout<<"Polycarp\n";
    else cout<<"Vasiliy\n";






    return 0;
}