#include <bits/stdc++.h>
using namespace std;
int n, k;
bool check[10];
string arr[10];
string tmp[10];
vector<string> kq;
void Backtracking(int i) {
	if (i == k) {
		string dem = "";
		for (int i = 0; i < k; ++i) dem += tmp[i] + " ";
		kq.push_back(dem);
		return;
	} else {
		for (int j = 0; j < n; ++j) {
			if (check[j] == true) {
				check[j] = false;
				tmp[i] = arr[j];
				if (tmp[i-1] < tmp[i]) Backtracking(i+1);
				check[j] = true;
			}
		}
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	memset(check,true,sizeof(check));
	Backtracking(0);
	int count = 1;
	cout << kq.size() << endl;
	for (string x : kq) {
		cout << count << ". " << x << endl;
		count++;
	}
}