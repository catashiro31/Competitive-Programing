#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()

vector<vector<int>> mul(const vector<vector<int>> &A, const vector<vector<int>> &B) {
	vector<vector<int>> res(A.size(), vector<int>(B[0].size()));
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B[0].size(); j++) {
			for (int k = 0; k < A[0].size(); k++) {
				res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % 2012;
			}
		}
	}
	return res;
}

vector<vector<int>> pow_up(vector<vector<int>> base, int exp) {
	vector<vector<int>> res(base.size(),vector<int>(base.size(),0));
	for (int i = 0; i < base.size(); i++) res[i][i] = 1;
	while (exp) {
		if (exp&1) res = mul(res,base);
		base = mul(base,base);
		exp /= 2;
	}
	return res;
}

void solve() {
	int n, x, p; cin >> n >> x >> p;
	vector<pair<int,int>> edge;
	for (int i = 1; i <= n; i++) {
		edge.psb({i, i+n});
		edge.psb({i+n, i});
		if (i == n) {
			edge.psb({i,1});
			edge.psb({1,i});
			edge.psb({i+n, n+1});
			edge.psb({n+1, i+n});
		} else {
			edge.psb({i, i+1});
			edge.psb({i+1, i});
			edge.psb({i+n, i+n+1});
			edge.psb({i+n+1, i+n});
		}
	}
	vector<vector<int>> mat(6*n,vector<int>(6*n,0));
	for (int i = 0; i < edge.size(); i++) {
		for (int j = 0; j < edge.size(); j++) {
			if (edge[i].second != edge[j].first) continue;
			if (edge[i].first == edge[j].second) continue;
			mat[i][j] = 1;
		}
	}
	if (p == 1) {
		for (int i = 0; i < edge.size(); i++) {
			if (edge[i].first == 1 && edge[i].second == x) cout << 1 << endl; 
		}
	} else {
		mat = pow_up(mat,p-1);
		int kq = 0;
		for (int i = 0; i < edge.size(); i++) {
			if (edge[i].first != 1) continue;
			for (int j = 0; j < edge.size(); j++) {
				if (edge[j].second != x) continue;
				kq = (kq + mat[i][j]) % 2012;
			}
		}
		cout << kq << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
