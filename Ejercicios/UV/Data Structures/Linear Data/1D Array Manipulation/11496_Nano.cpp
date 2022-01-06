#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    if(n==0) break;

    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int cont=0;
    for(int i=0;i<n;i++){
      int up=i+1;
      int down=i-1;
      if(i==n-1) up=0;
      if(i==0) down=n-1;
      if(arr[down]>arr[i] && arr[i]<arr[up]) cont++;
      if(arr[down]<arr[i] && arr[i]>arr[up]) cont++;

    }
    cout<<cont<<endl;
  }



  return 0;
}
