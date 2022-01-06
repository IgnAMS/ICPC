#include<bits/stdc++.h>
using namespace std;
int cont=0;
unsigned long long sum=0;
void pal(unsigned long long n){

  while(true){
    cont++;
    unsigned long long aux=n;
    unsigned long long n2=0;
    while(aux!=0){
      n2*=10;
      n2+=aux%10;
      aux/=10;
    }
    //cout<<n<<" "<<n2<<endl;
    sum=n+n2;
    deque<char> linea;
    aux=sum;
    while(aux!=0){
      linea.push_front(aux%10);
      aux/=10;
    }
    bool igual=true;
    for(int i=0;i<linea.size();i++){
      if(linea[i]!=linea[linea.size()-1-i])  igual=false;
    }
    //cout<<sum<<endl;
    if(!igual){
      n=sum;
    }
    else{
      break;
    }
  }

  return;
}


int main(){
  int t;
  cin>>t;
  while(t--){
    unsigned long long n;
    cin>>n;
    cont=0;
    pal(n);
    cout<<cont<<" "<<sum<<endl;


  }

  return 0;
}
