#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int arr[n];
  int arr2[n];
  int aux1[n/2];
  int aux2[n/2];

  for(int i=0;i<n;i++){
    arr[i]=i+1;
    //cout<<arr[i]<<" ";
    if(i<n/2) aux1[i]=i+1;
    else aux2[i-n/2]= i+1;
  }
  //cout<<endl;
  for(int i=0;i<n/2;i++){
    arr2[2*i]=aux2[i];
    arr2[2*i+1]=aux1[i];
    //cout<<arr2[2*i]<<" "<<arr2[2*i+1]<<" ";
  }
  //cout<<endl;
  int cont=0;
  int pos=2;
  while(true){
    cont++;
    //cout<<pos<<endl;
    for(int i=0;i<n;i++){
      if(arr2[i]==pos){
        pos=i+1;
        break;
      }
    }
    if(pos==2){
      break;
    }
  }
  cout<<cont<<endl;

  return 0;
}
