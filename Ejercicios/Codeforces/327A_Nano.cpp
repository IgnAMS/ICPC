#include<bits/stdc++.h>
using namespace std;



int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  vector<int> ac(n);
  int ind=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    if(arr[i]==1) ind++;
    ac[i]+=ind;
  }
  int maxsuma=ind;
  //cout<<ind<<endl;
  if(ind==n){
    cout<<ind-1<<endl;
    return 0;
  }
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      int rest=0;
      if(i>0){
        rest=ac[i-1];
      }
      //printf("estamos intercambiando el intervalo %d %d\n",i,j);
      int asd=(j-i+1)-(ac[j]-rest);
      //printf("tenemos %d a la izquierda, %d entre medio y %d a la derecha\n\n",rest,asd,ac[n-1]-ac[j]);
      maxsuma=max(maxsuma,rest+(ac[n-1]-ac[j])+asd);
    }
  }
  //O(n^3)
  /*
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      int suma=0;
      for(int k=0;k<n;k++){
        if(k<i || k>j){
          suma+=arr[k];
        }
        else{
          suma+=1-arr[k];
        }
      }
      //cout<<suma<<endl;
      maxsuma=max(maxsuma,suma);
    }
  }*/
  cout<<maxsuma<<endl;

  return 0;
}
