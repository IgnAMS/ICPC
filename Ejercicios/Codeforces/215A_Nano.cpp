#include<bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin>>a;
  int Ar[a];
  for(int i=0;i<a;i++){
    cin>>Ar[i];
  }
  int b;
  cin>>b;
  int R[b];
  for(int i=0;i<b;i++){
    cin>>R[i];
  }
  int rat=0;
  int cont=0;
  vector<pair<int,int> > asd;
  for(int i=0;i<a;i++){
    for(int j=b-1; j>=0; j--){
      if(R[j]%Ar[i]==0 && R[j]/Ar[i]>rat){
        rat=R[j]/Ar[i];
        cont=1;
        asd.clear();
        asd.push_back(pair<int,int>(R[j],Ar[i]));
      }
      else if(R[j]%Ar[i]==0 && R[j]/ Ar[i]==rat){
        cont++;
        asd.push_back(pair<int,int>(R[j],Ar[i]));
      }
      else if(R[j]/Ar[i]<rat){
        break;
      }
    }
  }
  cout<<cont<<endl;



  return 0;
}
