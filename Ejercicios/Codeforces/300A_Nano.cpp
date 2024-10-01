#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int Arr[n];
  vector<int> pos;
  vector<int> neg;
  vector<int> cero;

  for(int i=0;i<n;i++){
    cin>>Arr[i];
    if(Arr[i]>0) pos.push_back(Arr[i]);
    else if(Arr[i]<0) neg.push_back(Arr[i]);
    else if(Arr[i]==0) cero.push_back(0);
  }
  cout<<"1 "<<neg[neg.size()-1]<<endl;
  neg.pop_back();

  int aux=0;

  if(neg.size()%2!=0){
    aux=neg[neg.size()-1];
    neg.pop_back();
  }
  cout<<pos.size()+neg.size();

  for(int i=0;i<pos.size();i++){
    cout<<" "<<pos[i];
  }
  for(int i=0;i<neg.size();i++){
    cout<<" "<<neg[i];
  }
  if(aux==0){
    cout<<endl<<cero.size();
    for(int i=0;i<cero.size();i++){
      cout<<" "<<0;
    }
  }
  else{
    cout<<endl<<cero.size()+1;
    for(int i=0;i<cero.size();i++){
      cout<<" "<<0;
    }
    cout<<" "<<aux;
  }

  cout<<endl;




  return 0;
}
