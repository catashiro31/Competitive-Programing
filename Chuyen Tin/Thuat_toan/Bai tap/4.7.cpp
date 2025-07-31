#include <bits/stdc++.h>
using namespace std;
int n;
string kq = "";
char kitu[2] = {'(',')'};
int sum = 0;
bool check[2] = {true,true};
int dem = 0;
void Backtracking(int i) {
	if (i == 2*n) {
		cout << kq << endl;
		return;
	}
	for (int j = 0; j < 2; ++j) {
		if (sum == 0) check[1] = false;
		if (sum > 0) check[1] = true;
		if (check[j] == true) {
			kq += kitu[j];
			if (j == 0) {
				sum++;
				dem++;
			}
			else sum--;
			if (sum >= 0 and sum <= n and dem <= n) Backtracking(i+1);
			kq.pop_back();
			if (j == 0) {
				sum--;
				dem--;
			}
			else sum++;
		}
	}
}
int main() {
	cin >> n;
	Backtracking(0);
}
