
int main(){
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin>>n;
    int out=0, in=0;
    char c;
    int aux;
    bool flag=0;
    deque<int> asd(n,-1);
    vector<int> pos;
    set<int> maxi;
    rep(i,n) for(int i=0;i<n;i++) maxi.insert(i+1);
    set<int>::reverse_iterator it = maxi.rbegin();
    //cout<<*it<<"\n";
    rep(i,2*n){
        cin>>c;
        if(c=='+') { 
            in++;
            pos.push_back(in-1); 
            it++;
        }
        else{
            out++;
            if(in-out<0) { flag=1; break; }