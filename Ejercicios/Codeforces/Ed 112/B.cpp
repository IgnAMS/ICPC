#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int w, h; cin>>w>>h;
        int x1, x2, y1, y2; cin>>x1>>y1>>x2>>y2;
        int h1, w1; cin>>w1>>h1;
        // siempre es optimo que la nueva este en un extremo
        double ans = 1e11;
        bool entre = 0;
        bool choca = 0;
        // Abajo - izquierda
        if(h1 >= y1 and w1 > x1){ // intersecta por arriba
            if(h1 + (y2 - y1) <= h) ans = min(ans, double(h1 - y1)), entre = 1;
            choca = 1;
        }
        cerr<<"abajo - izq - 1, ans: "<<ans<<' '<<h1<<' '<< y1 << ' '<<(w1 <= x1)<<'\n';
        
        if(h1 > y1 and w1 >= x1){
            if((x2 - x1) + w1 <= w) ans = min(ans, double(w1 - x1)), entre = 1;
            choca = 1;
        }
        if(h1 <= y1 or w1 <= x1) ans = 0;
        cerr<<"abajo - izq - 2, ans: "<<ans<<'\n';


        // Abajo - derecha
        if(h1 >= y1 and w - w1 < x2){
            if(h1 + (y2 - y1) <= h) ans = min(ans, double(h1 - y1)), entre = 1;
            choca = 1;
        }
        cerr<<"abajo - der - 1, ans: "<<ans<<'\n';

        if(h1 > y1 and w - w1 <= x2){
            if(w1 + (x2 - x1) <= w) ans = min(ans, double(x2 - (w - w1))), entre = 1;
            choca = 1;
        }
        if(h1 <= y1 or w - w1 >= x2) ans = 0;
        cerr<<"abajo - der - 2, ans: "<<ans<<'\n';
        
        // Arriba izquierda
        if(h - h1 <= y2 and w1 > x1){
            if(h1 + (y2 - y1) <= h) ans = min(ans, double(y2 - (h - h1))), entre = 1;
            choca = 1;
        }
        cerr<<ans<<'\n';
        if(h - h1 < y2 and w1 >= x1){
            if((x2 - x1) + w1 <= w) ans = min(ans, double(w1 - x1)), entre = 1;
            choca = 1;
        }
        if(h - h1 >= y2 or w1 <= x1) ans = 0;
        cerr<<ans<<'\n';


        // Arriba a la derecha
        if(h - h1 <= y2 and (w - w1) < x2) { 
            if(h1 + (y2 - y1) <= h) ans = min(ans, double(y2 - (h - h1))), entre = 1;
            choca = 1;
        }

        cerr<<"arriba - der - 1, ans: "<<ans<<'\n';
        if(h - h1 < y2 and (w - w1) <= x2){
            if(w1 + (x2 - x1) <= w) ans = min(ans, double(x2 - (w - w1))), entre = 1;
            choca = 1;
        } 
        if(h - h1 >= y2 or (w - w1) >= x2) ans = 0;

        //if(h - h1 >= y2 or (w - w1) >= x2) ans = 0;
        if(abs(ans - 1e11) < 1e-8) { cout<<-1<<'\n'; continue; }
        cerr<<"arriba - der - 2, ans: "<<ans<<'\n';
        cerr<<"nueva iteracion\n\n";
        cout<<setprecision(8)<<fixed<<ans<<'\n';
    }




    return 0;
}