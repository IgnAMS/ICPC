#include<bits/stdc++.h>
using namespace std;
int main(){
  set<int> num;
  int t,n;
  cin>>t;
  //while(t--){
    for(int h=1000165;h<10000000;h++){

    n=h;
    bool smith=false;

    while(!smith){
      n++;
      int aux=n;
      int ind=2;
      int cont=0;

      while(aux>1){

        if(aux%ind==0){
          int aux2=ind;
          while(aux2>0){
            cont+=aux2%10;
            aux2/=10;
          }
          aux/=ind;
        }
        else ind++;
      }
      aux=n;
      int cont2=0;
      while(aux>0){
        cont2+=aux%10;
        aux/=10;
      }
      //cout<<cont<<" "<<cont2<<endl;
      bool prime=true;
      for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
          prime=false;
          break;
        }
      }
      if(cont==cont2 && !prime) smith=true;
    }
    num.insert(n);
    h=n;

    }

  //}
  std::set<int>::iterator it;
  for(it=num.begin();it!=num.end();++it){
    cout<<*it;
    cout<<", ";
  }


  return 0;
}
