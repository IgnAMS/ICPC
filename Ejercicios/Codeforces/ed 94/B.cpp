#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        ll p, f; cin>>p>>f;
        //unidades maximas a llevar
        ll conts, contw; cin>>conts>>contw;
        ll s,w; cin>>s>>w;
        ll ans=0;
        ll aux=0;
        if(s<w){
            //espadas
            aux=min(conts, p/s);
            conts-=aux;
            p-= aux*s;
            cout<<"agrego "<<aux<<" espadas a p"<<endl;
            ans+=aux, aux=0;
            //mientras pueda cambiar una hacha po
            while(){
                
            }

            aux=min(conts, f/s);
            conts-=aux;
            f-=aux*s;
            ans+=aux, aux=0;
            cout<<"agrego "<<aux<<" espadas a f"<<endl;

            //hachas
            aux=min(contw, p/w);
            conts-=aux;
            p-=aux*w;
            cout<<"agrego "<<aux<<" hachas a p"<<endl;
            ans+=aux, aux=0;

            aux=min(contw, f/w);
            conts-=aux;
            f-=aux*w;
            cout<<"agrego "<<aux<<" hachas a p"<<endl;
            ans+=aux, aux=0;
        }
        else{
            //hachas
            aux=min(contw, p/w);
            conts-=aux;
            p-=aux*w;
            ans+=aux, aux=0;
            aux=min(contw, f/w);
            conts-=aux;
            f-=aux*w;
            ans+=aux, aux=0;

            //espadas
            aux=min(conts, p/s);
            conts-=aux;
            p-= aux*s;
            ans+=aux, aux=0;
            aux=min(conts, f/s);
            conts-=aux;
            f-=aux*s;
            ans+=aux, aux=0;
        }
        cout<<ans<<endl;
    }




    return 0;
}