#include <bits/stdc++.h>
using namespace std;
int N, K;
int a[10];
int tong[10];
int pos[10];
int s;
bool supercheck = false;
void Backtracking(int i) {
	if (i == N) {
		dem++;
		for (int j = 1; j < K; ++j) {
			if (tong[j-1] != tong[j]) return;
		}
		for (int j = 0; j < K; ++j) {
			for (int x = 0; x < N; ++x) {
				if (pos[x] == j) cout << a[x] << " ";
			}
			cout << endl;
		}
		supercheck = true;
		return;
	}
	if (i < N) {
		for (int k = 0; k < K; ++k) {
			pos[i] = k;
			tong[k] += a[i];
			if (tong[k] <= s) Backtracking(i+1);
			if (supercheck == true) return;
			tong[k] -= a[i];
		}
	}
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {	
		cin >> a[i];
		s += a[i];
	}
	s = s/K;
	memset(tong,0,sizeof(tong));
	Backtracking(0);
}