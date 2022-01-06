#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

struct SegmentTree{
  vector<vll> ST,ST2;
  int n,m;

  SegmentTree(vector<vll> &A){
    n=A.size();
    m=A[0].size();
    ST.assign(4*n,vll(4*m,LONG_LONG_MAX));
    ST2.assign(4*n,vll(4*m,LONG_LONG_MIN));
    //cout<<"mori aca\n";
    build(1,1,0,n-1,0,n-1,A);
  }
  void build(int nodei, int nodej, int lowi, int topi, int lowj, int topj, vector<vll> &A){
    //printf("nodei: %d nodej: %d, lowi: %d, lowj: %d, ")
    //printf("lowi: %d, topi: %d\n",lowi,topi);
    if(lowi==topi){
      buildcol(nodei, nodej,lowi,lowj,topj,A);
      ST[nodei][nodej]=min(ST[nodei][2*nodej],ST[nodei][2*nodej+1]);
      ST2[nodei][nodej]=max(ST2[nodei][2*nodej],ST2[nodei][2*nodej+1]);
      //cout<<"entre medio\n";
      return;
    }
    //en caso de que estemos en dif filas
    //printf("wa a entrar a %d %d y a %d %d\n",lowi,(lowi+topi)/2,(lowi+topi)/2+1,topi);
    build(nodei*2, nodej, lowi,(lowi+topi)/2,lowj,topj,A);
    build(nodei*2+1, nodej, (lowi+topi)/2+1,topi,lowj,topj,A);
    for(int i=1;i<ST[nodei].size();i++){
      ST[nodei][i]=min(ST[nodei*2][i],ST[nodei*2+1][i]);
      ST2[nodei][i]=max(ST2[nodei*2][i],ST2[nodei*2+1][i]);

      //if(ST[nodei][i]!=LONG_LONG_MAX){
        //printf("ST[%d][%d]: %d\n",nodei,i,ST[nodei][i]);
      //}
    }
    //ST[nodei][nodej]=min(ST[nodei*2][nodej],ST[nodei*2+1][nodej]);
    return;
  }
  void buildcol(int nodei, int nodej, int i, int lowj, int topj, vector<vll> &A){
    //estoy en una hoja
    //printf("nodei: %d, nodej: % d, i: %d, lowj: %d, topj: %d\n",nodei,nodej,i,lowj,topj);
    if(lowj==topj){
      ST[nodei][nodej]=A[i][lowj];
      ST2[nodei][nodej]=A[i][lowj];
      //printf("estoy en la hoja %d %d y vale: %lld, en el nodo %d %d\n",i,lowj,A[i][lowj],nodei,nodej);
      //printf("ST[%d][%d]: %d\n",nodei,nodej,ST[nodei][nodej]);
      return;
    }
    //necesito dividirme
    //printf("\nvoy a dividirme en j en %d %d y %d %d\n",lowj,(lowj+topj)/2,(lowj+topj)/2+1,topj);
    buildcol(nodei, nodej*2, i, lowj, (lowj+topj)/2,A);
    buildcol(nodei, nodej*2+1, i, (lowj+topj)/2+1, topj,A);
    ST[nodei][nodej]=min(ST[nodei][nodej*2],ST[nodei][nodej*2+1]);
    ST2[nodei][nodej]=max(ST2[nodei][nodej*2],ST2[nodei][nodej*2+1]);
    //printf("ST[%d][%d]: %d\n",nodei,nodej,ST[nodei][nodej]);
    return;
  }
  ll query(int lowi, int topi,int lowj, int topj){
    //cout<<"entre a una query\n";
    return queryy(1,1,0,n-1,lowi,topi,lowj,topj);
  }
  ll queryy(int nodei, int nodej, int li, int ri, int lowi, int topi, int lowj, int topj){
    //caso 1, esta fuera de la fila
    //printf("nodei: %d, nodej: %d, li: %d, ri: %d, lowi: %d, topi: %d, lowj: %d, topj: %d\n",nodei,nodej,li,ri,lowi,topi,lowj,topj);
    if(ri<lowi || li>topi){
      //cout<<"entre a este caso\n";
      return LONG_LONG_MAX;
    }
    //caso 2, esta dentro de la fila
    if(lowi<=li && ri<=topi){
      //realizar query de la columna -> por hacer
      //printf("esta funcion esta retornando %lld para el nodo %d %d\n",qcol(nodei,nodej,0,m-1,lowi,topi,lowj,topj),nodei,nodej);
      return qcol(nodei,nodej,0,n-1,lowi,topi,lowj,topj);

    }
    //divide and conquer
    return min(queryy(nodei*2,nodej,li,(li+ri)/2,lowi,topi,lowj,topj),queryy(nodei*2+1,nodej,(li+ri)/2+1,ri,lowi,topi,lowj,topj));
  }
  ll qcol(int nodei, int nodej, int lj, int rj, int lowi, int topi, int lowj, int topj){
    //printf("nodei: %d, nodej: %d, lj: %d, rj: %d, i: %d, topi: %d, lowj: %d, topj: %d\n",nodei,nodej,lj,rj,lowi,topi,lowj,topj);
    //caso 1, esta fuera de la fila
    if(rj<lowj || lj>topj){
      return LONG_LONG_MAX;
    }
    //caso2 esta fuera dentro de la columna
    if(lowj<=lj && rj<=topj){
      //printf("tomo el nodo %d %d: %lld\n",nodei,nodej,ST[nodei][nodej]);
      return ST[nodei][nodej];
    }
    //caso 3, divide and conquer
    return min(qcol(nodei,nodej*2,lj,(lj+rj)/2,lowi,topi,lowj,topj),qcol(nodei,nodej*2+1,(lj+rj)/2+1,rj,lowi,topi,lowj,topj));
  }
  ll qmax(int lowi, int topi,int lowj, int topj){
    return qmaxx(1,1,0,n-1,lowi,topi,lowj,topj);
  }
  ll qmaxx(int nodei, int nodej, int li, int ri, int lowi, int topi, int lowj, int topj){
    //caso 1, esta fuera de la fila
    //printf("nodei: %d, nodej: %d, li: %d, ri: %d, lowi: %d, topi: %d, lowj: %d, topj: %d\n",nodei,nodej,li,ri,lowi,topi,lowj,topj);
    if(ri<lowi || li>topi){
      //cout<<"entre a este caso\n";
      return LONG_LONG_MIN;
    }
    //caso 2, esta dentro de la fila
    if(lowi<=li && ri<=topi){
      //realizar query de la columna -> por hacer
      //printf("esta funcion esta retornando %lld para el nodo %d %d\n",qcol(nodei,nodej,0,m-1,lowi,topi,lowj,topj),nodei,nodej);
      return qcolmax(nodei,nodej,0,m-1,lowi,topi,lowj,topj);

    }
    //divide and conquer
    return max(qmaxx(nodei*2,nodej,li,(li+ri)/2,lowi,topi,lowj,topj),qmaxx(nodei*2+1,nodej,(li+ri)/2+1,ri,lowi,topi,lowj,topj));
  }
  ll qcolmax(int nodei, int nodej, int lj, int rj, int lowi, int topi, int lowj, int topj){
    //printf("nodei: %d, nodej: %d, lj: %d, rj: %d, i: %d, topi: %d, lowj: %d, topj: %d\n",nodei,nodej,lj,rj,lowi,topi,lowj,topj);
    //caso 1, esta fuera de la fila
    if(rj<lowj || lj>topj){
      return LONG_LONG_MIN;
    }
    //caso2 esta fuera dentro de la columna
    if(lowj<=lj && rj<=topj){
      //printf("tomo el nodo %d %d: %lld\n",nodei,nodej,ST[nodei][nodej]);
      return ST2[nodei][nodej];
    }
    //caso 3, divide and conquer
    return max(qcolmax(nodei,nodej*2,lj,(lj+rj)/2,lowi,topi,lowj,topj),qcolmax(nodei,nodej*2+1,(lj+rj)/2+1,rj,lowi,topi,lowj,topj));
  }

  void update(int i, int j, ll x){
    uprow(1,1,0,n-1,i,j,x);
    uprowmax(1,1,0,n-1,i,j,x);
    return;
  }
  void uprow(int nodei, int nodej, int li, int ri, int i, int j, ll x){
    //printf("nodei: %d, nodej: %d, li: %d, ri: %d, i: %d, j: %d, x: %lld\n",nodei,nodej,li,ri,i,j,x);
    //caso 1 esta fuera
    if(i<li || ri<i){
      return;
    }
    //caso 2 esta dentro
    if(li==i && i==ri){
      //hacer upcol!
      upcol(nodei,nodej,0,m-1,i,j,x);
      return;
    }
    //caso 3, divide and conquer
    uprow(nodei*2,nodej,li,(li+ri)/2,i,j,x);
    uprow(nodei*2+1,nodej,(li+ri)/2+1,ri,i,j,x);
    for(int i=1;i<ST[nodei].size();i++){
      ST[nodei][i]=min(ST[nodei*2][i],ST[nodei*2+1][i]);
      /*if(ST[nodei][i]!=LONG_LONG_MAX){
        printf("acutalizo el nodo %d %d a %d\n",nodei,i,ST[nodei][i]);
      }*/
    }
    ST[nodei][nodej]= min(ST[nodei*2][nodej],ST[nodei*2+1][nodej]);
    return;
  }
  void upcol(int nodei, int nodej, int lj, int rj, int i, int j, ll x){
    //caso 1 esta fuera
    //printf("nodei: %d, nodej: %d, lj: %d, rj: %d, i: %d, j: %d, x: %lld\n",nodei,nodej,lj,rj,i,j,x);
    if(j<lj || rj<j){
      return;
    }
    //caso 2, esta dentro
    if(lj==j && j==rj){
      ST[nodei][nodej]=x;
      //printf("voy a editar el nodo %d %d a %lld unidades\n",nodei,nodej,x);
      return;
    }
    //caso 3, divide and conquer
    upcol(nodei, nodej*2,lj,(lj+rj)/2,i,j,x);
    upcol(nodei, nodej*2+1,(lj+rj)/2+1,rj,i,j,x);
    ST[nodei][nodej]=min(ST[nodei][nodej*2],ST[nodei][nodej*2+1]);
    //printf("\nactualizo el nodo %d %d a %lld\n",nodei,nodej,ST[nodei][nodej]);
    return;
  }
  void uprowmax(int nodei, int nodej, int li, int ri, int i, int j, ll x){
    //printf("nodei: %d, nodej: %d, li: %d, ri: %d, i: %d, j: %d, x: %lld\n",nodei,nodej,li,ri,i,j,x);
    //caso 1 esta fuera
    if(i<li || ri<i){
      return;
    }
    //caso 2 esta dentro
    if(li==i && i==ri){
      //hacer upcol!
      upcolmax(nodei,nodej,0,m-1,i,j,x);
      return;
    }
    //caso 3, divide and conquer
    uprowmax(nodei*2,nodej,li,(li+ri)/2,i,j,x);
    uprowmax(nodei*2+1,nodej,(li+ri)/2+1,ri,i,j,x);
    for(int i=1;i<ST2[nodei].size();i++){
      ST2[nodei][i]=max(ST2[nodei*2][i],ST2[nodei*2+1][i]);
    }
    //printf("actualizamos el nodo %d %d a: %d")
    ST2[nodei][nodej]= max(ST2[nodei*2][nodej],ST2[nodei*2+1][nodej]);
    return;
  }
  void upcolmax(int nodei, int nodej, int lj, int rj, int i, int j, ll x){
    //caso 1 esta fuera
    if(j<lj || rj<j){
      return;
    }
    //caso 2, esta dentro
    if(lj==j && j==rj){
      ST2[nodei][nodej]=x;
      //printf("voy a editar el nodo %d %d en %d unidades\n",nodei,nodej);
      return;
    }
    //caso 3, divide and conquer
    upcolmax(nodei, nodej*2,lj,(lj+rj)/2,i,j,x);
    upcolmax(nodei, nodej*2+1,(lj+rj)/2+1,rj,i,j,x);
    ST2[nodei][nodej]=max(ST2[nodei][nodej*2],ST2[nodei][nodej*2+1]);
    return;
  }
  void printmat(){
    for(int i=0;i<ST.size();i++){
      for(int j=0;j<ST[i].size();j++){
        if(ST[i][j]==LONG_LONG_MAX) continue;
        cout<<ST[i][j]<<" ";
      }
      cout<<endl;
    }
  }

};



int main(){
  int n;
  cin>>n;
  vector<pll> ans;
  vector<vll> mat(n,vll (n,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>mat[i][j];
    }
  }
  //cout<<"mori aca\n";
  SegmentTree Tree(mat);
  //Tree.printmat();
  //cout<<"mori despues\n";
  int m, x1,y1,x2,y2,v;
  char c;
  int cont=0;
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>c;
    if(c=='q'){
      cont++;
      //printf("\n\nQuery numero: %d\n",cont);
      cin>>x1>>y1>>x2>>y2;
      ll a1=Tree.qmax(x1-1,x2-1,y1-1,y2-1);
      ll a2=Tree.query(x1-1,x2-1,y1-1,y2-1);
      ans.push_back(pll(a1,a2));
      //cout<<a1<<" "<<a2<<endl;
    }
    if(c=='c'){
      cin>>x1>>y1>>v;
      Tree.update(x1-1,y1-1,v);
      //Tree.printmat();
    }
  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
  }

  return 0;
}
