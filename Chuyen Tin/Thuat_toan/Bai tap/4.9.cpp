#include <bits/stdc++.h>
using namespace std;
string S;
string xau = "";
bool check[10];
set<string> kq;
void Backtracking() {
	if (xau.size() == S.size()) {
		kq.insert(xau);
		return;
	}
	for (int j = 0; j < S.size(); ++j) {
		if (check[j] == true) {
			check[j] = false;
			xau += S[j];
			Backtracking();
			xau.pop_back();
			check[j] = true;
		}
	}
}
int main() {
	cin >> S;
	memset(check,true,sizeof(check));
	Backtracking();
	cout << kq.size() << endl;
}