#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int arr[n];
    int cont=0;
    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=n-1;i>=1;i--){
      bool swap=false;
      //cout<<i<<endl;
      for(int j=n-1;j>=1+(n-1-i);j--){
        //cout<<j<<endl;
        //cout<<arr[j]<<" "<<arr[j-1]<<endl;
        if(arr[j]<arr[j-1]){
          swap=true;
          //cout<<arr[j-1]<<" "<<arr[j]<<endl;
          cont++;
          int aux=arr[j];
          arr[j]=arr[j-1];
          arr[j-1]=aux;
        }
      }
      if(!swap) break;
    }
    printf("Optimal train swapping takes %d swaps.\n",cont);
  }

  return 0;
}
