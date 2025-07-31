#include <bits/stdc++.h>
using namespace std;
int M;
string S;
int pos[9];
bool status = true;
int to_int(string a) {
	if (a == "") return 0;
	int k = 0;
	int kq = 0;
	while (a[k] != '\0') {
		kq = kq*10+a[k]-48;
		k++;
	}
	return kq;
}
int Checkxau(string xau) {
	bool status = true;
	string tmp = "";
	int sum = 0;
	for (int j = 0; j < xau.size(); ++j) {
		if (xau[j] == '+') {
			status = true;
			tmp = "";
		}
		if (xau[j] == '-') {
			status = false;
			tmp = "";
		}
		if (xau[j] != '+' and xau[j] != '-') {
			if (status == true) sum -= to_int(tmp);
			else sum += to_int(tmp);
			tmp += xau[j];
			if (status == true) sum += to_int(tmp);
			else sum -= to_int(tmp);
		}
	}
	if (sum == M) return 1;
	return 0;
}
void Backtracking(int i) {
	if (i == S.size()) {
		string xau = "";
		for (int j = 0; j < S.size(); ++j) {
			if (pos[j] == 1) xau += "+";
			if (pos[j] == 2) xau += "-";
			xau += S[j];
		}
		if (Checkxau(xau) == 1) cout << xau << endl;
		return;
	}
	for (int j = 0; j < 3; ++j) {
		pos[i] = j;
		Backtracking(i+1);
	}
}
int main() {
	cin >> M >> S;
	Backtracking(0);
}