#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> kq;
string tmp = "";
void Backtracking(int i) {
	if (i == n) {
		kq.push_back(tmp);
		return;
	} else {
		for (int j = 0; j <= 1; ++j) {
			tmp += to_string(j);
			Backtracking(i+1);
			tmp.pop_back();
		}
	}
}
int main() {
	cin >> n;
	Backtracking(0);
	cout << kq.size() << endl;
	int count = 1;
	for (string x : kq) {
		cout << count << ". " << x << endl;
		count++;
	}
}