#include <bits/stdc++.h>
#define Int int
using namespace std;

vector< vector<Int> > Ans;
map < pair<int, int>, vector< vector<Int> >> ma;
int MOD , n , m;


class SegTree {
private:
	vector< vector<Int> > Identity ;
	vector< vector< vector<Int> > > Seg;

	Int MulMod(Int a , Int b) {
		return (a % MOD * b % MOD) % MOD;
	}

	void Compain(vector< vector< Int > > &a , vector< vector< Int > > &b, vector< vector< Int > > &Res) {
		for (int i = 0 ; i < 2 ; i++)
			for (int j = 0 ; j < 2 ; j++)
				for (int k = 0 ; k < 2 ; k++) {
					Res[i][j] += MulMod(a[i][k] , b[k][j]);
					Res[i][j] %= MOD;
				}
	}

	void DoIdentity () {
		Identity.assign(2 , vector< Int >(2 , 0));
		for (int i = 0 ; i < 2 ; i++)
			Identity[i][i] = 1;
	}

	void UPD(int i , vector< vector< Int > > &v , int p , int L , int R) {
		if ( i >  R || i <  L ) return;
		if ( L == R ) {
			Seg[p] = v;
			return;
		}

		int Mid = (L + R) >> 1;
		if (i >= L and i <= Mid)
			UPD(i , v , 2 * p , L , Mid);
		else
			UPD(i , v , 2 * p + 1 , Mid + 1 , R);
		Seg[p].assign(2 , vector< Int >(2 , 0));
		Compain(Seg[2 * p] , Seg[2 * p + 1], Seg[p]);
	}

	void QRY(int i , int j , int p , int L , int R, vector< vector< Int > > &v) {
		if ( i >  R || L >  j ) return ;
		if ( i <= L && R <= j ) {
			vector< vector< Int > > V(2 , vector< Int >(2));
			Compain(v , Seg[p], V);
			v = V;
			return;
		}

		int Mid = (L + R) >> 1;
		QRY(i , j , 2 * p , L , Mid, v);
		QRY(i , j , 2 * p + 1 , Mid + 1 , R, v);
	}

public:
	SegTree(int n) {
		DoIdentity();
		Seg.assign(4 * n , Identity );
	}
	void UPD(int i , vector< vector< Int > > &v) {
		UPD(i , v , 1 , 1 , n);
	}
	void QRY(int L , int R) {

		Ans.assign(2 , vector< Int >(2 , 0));
		for (int i = 0 ; i < 2 ; i++)
			Ans[i][i] = 1;

		QRY(L , R , 1 , 1 , n, Ans);
	}
};

int main() {
	ios::sync_with_stdio(0); 		cin.tie(0); cout.tie(0);
	cin >> MOD >> n >> m;
	SegTree ST(n + 1);

	vector< vector< Int > > V(2 , vector< Int >(2));
	for (int idx = 1 ; idx <= n ; idx++) {
		for (int i = 0 ; i < 2 ; i++)
			for (int j = 0 ; j < 2 ; j++)
				cin >> V[i][j];
		ST.UPD(idx , V);
	}
	int L , R, i;

	while ( m-- ) {
		cin >> L >> R;
		ST.QRY(L , R);

		for (i = 0 ; i < 2 ; i++) {
			for (int j = 0 ; j < 2 ; j++)
				cout << Ans[i][j] << " ";
			cout << "\n";
		}
		cout << "\n";
	}
}
