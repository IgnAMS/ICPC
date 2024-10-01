#include<bits/stdc++.h>
using namespace std;

int top=-1;
int low=0;

int findMaxSubarraySum(int arr[], int n, int sum){
    int curr_sum = arr[0], max_sum = 0, start = 0;

    // To find max_sum less than sum

    for (int i = 1; i < n; i++) {
      //printf("la suma actual es de %d desde %d hasta %d\nY el maximo es de %d\n\n",curr_sum, start, i-1, max_sum);
        if (curr_sum <= sum){
          if((i-1)-start>top-low){
            top=i-1;
            low=start;
          }
          max_sum = max(max_sum, curr_sum);
        }

        while (curr_sum + arr[i] > sum && start < i) {
            curr_sum -= arr[start];
            start++;
        }

        // Add elements to curr_sum
        curr_sum += arr[i];
    }

    // Adding an extra check for last subarray
    if (curr_sum <= sum){
      if((n-1)-start>top-low){
        top=n-1;
        low=start;
      }
      max_sum = max(max_sum , curr_sum);

    }


    return max_sum;
}


int main(){
  int n,t;
  cin>>n>>t;
  int tiemp[n];

  for(int i=0;i<n;i++){
    cin>>tiemp[i];
  }
  int xd= findMaxSubarraySum(tiemp,n,t);
  //cout<<xd<<" "<<low<<" "<<top<<endl;
  int dist= top-low+1;
  cout<<dist<<endl;


  return 0;
}
