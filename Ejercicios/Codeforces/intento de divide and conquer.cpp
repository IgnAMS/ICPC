#include<bits/stdc++.h>
using namespace std;

int max_sum=INT_MIN;
int low=0,top=0;

int maxtrip(int a, int b, int c){
  return max(max(a,b),c);
}


int maxCross(int arr[],int l, int m, int h, int ot){
  int right_sum=INT_MIN;
  int left_sum=INT_MIN;
  int sum=0;
  for(int i=l;i<=m;++i){
    sum+=arr[i];
    if(sum>left_sum){
      left_sum=sum;
    }
  }

  sum=0;
  for(int i=m+1;i<=h;++i){
    sum+=arr[i];
    if(sum>right_sum){
      right_sum=sum;
    }
  }
  printf("la suma es de %d y l es %d y h es %d\n",right_sum+left_sum,l,h);
  if(right_sum + left_sum > ot) return INT_MIN;

  if(right_sum + left_sum >= max_sum){
    if(h-l>top-low){
      cout<<"debi entrar aca xd\n";
      low=l;
      max_sum=right_sum+left_sum;
      top=h;
    }
  }
  return right_sum + left_sum;
}

int maxsub(int arr[],int l, int h, int ot){

  if(l==h && arr[l]<=ot) return arr[l];
  if(l==h && arr[l]>ot) return INT_MIN;

  int m= (l+h)/2;

  return maxtrip(maxsub(arr, l, m, ot),
              maxsub(arr, m+1, h, ot),
              maxCross(arr, l, m, h, ot));

}



int main(){
  int n,t;
  cin>>n>>t;
  int tiemp[n];

  for(int i=0;i<n;i++){
    cin>>tiemp[i];
  }
  //cout<<max_sum<<endl;
  max_sum=maxsub(tiemp,0,n-1,t);
  printf("la suma maxima es de %d, con low %d y top %d\n",max_sum,low,top);




  return 0;
}
