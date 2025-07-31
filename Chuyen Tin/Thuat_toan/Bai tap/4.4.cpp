#include <bits/stdc++.h>
using namespace std;
int n;
char kitu[2] = {'A','B'};
bool check = true;
bool supercheck;
vector<string> kq;
string tmp = "";
void Backtracking(int i) {
	if (i == n) {
		kq.push_back(tmp);
		return;
	} else {
		for (int j = 0; j < 2; ++j) {
			if (tmp[i-1] == 'B' and j == 1) continue;
			tmp += kitu[j];
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
		++count;
	}
}