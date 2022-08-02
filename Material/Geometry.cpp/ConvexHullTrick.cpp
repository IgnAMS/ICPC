// Given lines mantains a convex space to minimum queries, crescent slopes
struct CHT {
    vi A, B;
    
    db cross(int i, int j, int k) { 
        return 1.d * (A[j] - A[i]) * (B[k] - B[i]) - 1.d * (A[k] - A[i]) * (B[j] - B[i]);
    }
 
    void add(ll a, ll b) {
        A.push_back(a);
        B.push_back(b);
 
        while(A.size() > 2 and cross(A.size() - 3, A.size() - 2, A.size() - 1) <= 0) {
            A.erase(A.end() - 2);
	        B.erase(B.end() - 2);
	    }
    }
 
    ll query(ll x) {
        if(A.empty()) return (long long)1e18;
        int l = 0, r = A.size() - 1;
 
        while (l < r) {
            int mid = l + (r - l)/2;
		    ll f1 = A[mid] * x + B[mid];
		    ll f2 = A[mid + 1] * x + B[mid + 1];
 
			if(f1 > f2) l = mid + 1;
			else r = mid;
        }
 
        return A[l] * x + B[l];
      }
};