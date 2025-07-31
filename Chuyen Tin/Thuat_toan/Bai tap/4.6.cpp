#include <bits/stdc++.h>
using namespace std;
string S;
int limit;
string xau;
int pos;
vector<string> kq;
void Backtracking(int i) {
	if (i == limit) {
		kq.push_back(xau);
		return;
	}
	for (int j = pos+1; j <= S.size()-limit+i; ++j) {
		int tmp = pos;
		pos = j;
		xau += S[j];
		if (S.size()-pos >= limit-i) Backtracking(i+1);
		xau.pop_back();
		pos = tmp;
	}
}
int main() {
	cin >> S;
	for (int i = 1; i <= S.size(); ++i) {
		limit = i;
		xau = "";
		pos = -1;
		Backtracking(0);
	}
	for (string x : kq) cout << x << endl;
}