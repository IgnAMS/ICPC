#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define INF (int)1e9
#define pb push_back
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


bool inp;
ll minint,maxint;

void ask(ll &mid, ll &ant, ll &low, ll &top, ll n){
  //sabemos que para una distancia de minint funcionará, ahora la pregunta es para una
  //distancia minint/2;
  //la mitad desde que funciona hasta que no funciona
  if(maxint==n-2 || minint-maxint==1){
    //cout<<"mm"<<endl;
    return;
  }
    if(mid + (maxint + minint)/2 < n){
    cout<<"? "<<mid + (minint+maxint)/2<<endl;
    cin>>inp;
    ant= mid;
    mid= mid + (minint+maxint)/2;
    if(inp){
      //C <= n-mid -> procede a buscar en un intervalo mas chico
      minint=abs(mid-ant);
      low= mid-(maxint+minint)/2;
      top= mid-(maxint+minint)/2;
      //cout<<minint<<" "<<maxint<<endl;

      return;
    }
    else{
      //C > n-mid -> procede a buscar en un intervalo mas grande
      maxint=max(maxint, abs(mid-ant));
      if(maxint+1==minint){
        return;
      }

      ask(mid,ant,low,top,n);
      return;
    }
  }

  //si puedo preguntar en el intervalo de abajo lo hago
  else if(mid -(minint+maxint)/2 > 0){
    cout<<"? "<<mid -(minint+maxint)/2<<endl;
    cin>>inp;
    ant=mid;
    mid=mid-(minint+maxint)/2;
    if(inp){
      //procede a buscar en un intervalo mas chico
      minint= abs(mid-ant);
      //aca hay que cambiar las cosas chaval
      low= mid + (minint+maxint)/2;
      top= mid + (minint+maxint)/2;
      return;
    }
    else{
      //procede buscar en un intervalo mas grande
      maxint=max(maxint, abs(mid-ant));
      if(maxint+1==minint){
        return;
      }

      ask(mid,ant,low,top,n);
      return;
    }

  }
  else{
    //si no puedo buscar ni para arriba ni para abajo debo resetear
    cout<<"? 1"<<endl;
    cin>>inp;
    //se que dara 0, ahora procede a preguntar por el punto medio
    //del (|mid-anterior| + n)/2
    cout<<"? "<<(minint+maxint+1)/2<<endl;
    cin>>inp;
    ll aux=ant;
    ant=1;
    mid=(minint+abs(mid-aux)+1)/2;
    if(inp){
      minint=abs(mid-ant);
      low= mid- (minint+maxint)/2;
      top= mid- (minint+maxint)/2;
      return;
    }
    else{
      maxint=max(maxint, abs(mid-ant));
      if(maxint+1==minint){
        return;
      }

      ask(mid,ant,low,top,n);
      return;
    }
  }
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    //sOJ;
    int t;
    cin>>t;
    while(t--){
        ll n; cin>>n;
        ll low=1, top=n;
        //cin>>C;
        cout<<"? "<<low<<endl;
        cin>>inp;
        ll ant;
        ll mid=low;
        minint=n;
        maxint=1;
        bool mayor=false;
        if(n==2) minint=1;
        while(minint - maxint>1){
          //mientras el intervalo en el que este preguntando sea mayor
          if(maxint==n-2){
            minint=n-1;
            break;
          }
          ant=mid;
          mid=(top+low)/2;
          cout<<"? "<<mid<<endl;
          cin>>inp;
          if(inp){
            minint= abs(mid-ant);
            //si puedo preguntar hacia abajo lo hago, si no no
            if(mid-(maxint+minint)/2>=1){
              top = mid-(maxint+minint)/2;
              low = mid-(maxint+minint)/2;
            }
            else{
              top = mid+(maxint+minint)/2;
              low = mid+(maxint+minint)/2;
            }
          }
          else{
            maxint=max(maxint, abs(mid-ant));
            mayor=true;
            ask(mid,ant,low,top,n);
          }
        }
        cout<<"= "<<minint<<endl;
    }

    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}

