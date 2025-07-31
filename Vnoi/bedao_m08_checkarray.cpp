#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	priority_queue<int,vector<int>, greater<>> pq; 
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		pq.push(x);
	}
	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		if (abs(a-b) <= 1) pq.push(a < b ? b : a); 
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
