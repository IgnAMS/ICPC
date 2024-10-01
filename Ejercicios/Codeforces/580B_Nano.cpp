#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,d;
  cin>>n>>d;
  vector<pair<int,int> > chavo;
  int a,b;
  pair<int,int> par;

  for(int i=0;i<n;i++){
    cin>>a>>b;
    chavo.push_back(pair<int,int> (a,b));
  }
  sort(chavo.begin(),chavo.end());
  reverse(chavo.begin(),chavo.end());

  unsigned long long max_sum=0;
  //cout<<chavo[0].first<<endl;
  unsigned long long curr_sum=chavo[0].first;
  int start=0;
  unsigned long long curr_ben=chavo[0].second;

  for (int i = 1; i < n; i++) {
    //printf("la suma actual es de %d desde %d hasta %d\nY el maximo es de %d\n\n",curr_sum, start, i-1, max_sum);
    if (curr_sum < d){
      max_sum = max(max_sum, curr_ben);
    }
    cout<<cur_ben<<endl;
    while (curr_sum + chavo[i].first > d && start < i) {
      curr_sum -= chavo[start].first;
      curr_ben -= chavo[start].second;
      start++;
    }

        // Add elements to curr_ben
    curr_ben += chavo[i].second;
    curr_sum += chavo[i].first;
  }

  // Adding an extra check for last subarray
  if (curr_sum < d){
    max_sum = max(max_sum , curr_ben);
  }


  cout<<max_sum<<endl;



  return 0;
}
