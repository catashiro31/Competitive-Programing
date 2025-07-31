#include <bits/stdc++.h>
using namespace std;
int n;
int arr[21][21];
bool check[21];
int sum = 0;
int kq = INT_MAX;
vector<int> road;
vector<int> hienthi(21);
void Try(int i) {
	int cmin = INT_MAX;
	for (int j = 1; j <= n; ++j) {
		if (check[j] == true and arr[road[i-1]][j] != 0 and arr[road[i-1]][j] < cmin) cmin = arr[road[i-1]][j];
	}
	if (sum + cmin*(n-i+1) >= kq) return;
	for (int j = 2; j <= n; ++j) {
		if (check[j] == true) {
			check[j] = false;
			road.push_back(j);
			sum += arr[road[i-1]][j];
			if (i == n-1) {
				if (sum+arr[j][1] < kq) {
					hienthi.clear();
					kq = sum+arr[j][1];
					for (int x : road) hienthi.push_back(x);
				}
			} else Try(i+1);
			road.pop_back();
			check[j] = true;
			sum -= arr[road[i-1]][j];
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> arr[i][j];
		}
	}
	road.push_back(1);
	memset(check,true,sizeof(check));
	Try(1);
	cout << endl << kq << endl;
	for (int x : hienthi) cout << x << "->";
	cout << "1";
}