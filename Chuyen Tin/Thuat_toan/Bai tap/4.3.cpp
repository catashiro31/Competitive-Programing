#include <bits/stdc++.h>
using namespace std;
string S;
vector<string> kq;
bool check[10];
string tmp = "";
void Backtracking(int i) {
	if (i == S.size()) {
		kq.push_back(tmp);
		return;
	} else {
		for (int j = 0; j < S.size(); ++j) {
			if (check[j] == true) {
				check[j] = false;
				tmp += S[j];
				Backtracking(i+1);
				tmp.pop_back();
				check[j] = true;
			}
		}
	}
}
int main() {
	cin >> S;
	memset(check,true,sizeof(check));
	Backtracking(0);
	cout << kq.size() << endl;
	int count = 1;
	for (string x : kq) {
		cout << count << ". " << x << endl;
		++count;
	}
}