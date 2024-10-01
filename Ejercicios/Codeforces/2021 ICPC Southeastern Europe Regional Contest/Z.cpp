#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main(){

    int n;
    cin>>n;

    string s;
    cin>>s;

    int a = 0;
    int b = 0;
    int c = 0;

    for(char ch: s){
        if(ch == 'A'){
            a++;
        }
        if(ch == 'B'){
            b++;
        }
        if(ch == 'C'){
            c++;
        }
    }

    int ab = (a+b-c)/2;
    int ac = (a+c-b)/2;
    int bc = (b+c-a)/2;

    if((a+b-c)%2 == 1){
        cout<<"NO\n";
        return 0;
    }
    if((a+c-b)%2 == 1){
        cout<<"NO\n";
        return 0;
    }
    if((b+c-a)%2 == 1){
        cout<<"NO\n";
        return 0;
    }

    if(ab + bc + ac != n){
        cout<<"NO\n";
        return 0;
    }

    queue<int> B;
    vector<ii> res;
    vector<bool> used(2*n, false);

    for(int i = 0; i<2*n; i++){
        if(s[i] == 'B' && bc > 0){
            B.push(i);
            bc--;
            used[i] = true;
        }
        if(s[i] == 'C' && B.size() > 0){
            used[i] = true;
            res.push_back(ii(B.front(), i));
            B.pop();
        }
    }

    if(B.size() > 0){
        cout<<"NO\n";
        return 0;
    }

    queue<int> A;

    for(int i = 0; i<2*n; i++){
        if(s[i] == 'A'){
            A.push(i);
        }
        else{
            if(used[i] == false && A.size() > 0){
                res.push_back(ii(A.front(), i));
                A.pop();
            }
        }
    }

    if(A.size() > 0){
        cout<<"NO\n";
        return 0;
    }

    if(res.size() < n){
        cout<<"NO\n";
        return 0;
    }

    cout<<"YES\n";

    for(int i = 0; i<n; i++){
        cout<<res[i].first+1<<" "<<res[i].second+1<<"\n";
    }

    return 0;
}