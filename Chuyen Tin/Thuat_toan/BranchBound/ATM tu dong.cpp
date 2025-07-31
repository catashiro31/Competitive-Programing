#include <iostream>
using namespace std;
int n;
long int S;
long int To[21];
int x[21];
long int kq[21];
bool check[21];
long int sum = 0;
int best = INT_MAX;
bool supercheck = false;
long int maxTo = 0;
void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (check[j] == true and To[x[i-1]] <= To[j]) {
			check[j] = false;
			x[i] = j;
			sum += To[j];
			if (sum == S) {
				supercheck = true;
				if (i < best) {
					best = i;
					for (int k = 1; k <= i; k++) kq[k] = To[x[k]];
				}
			} else {
				if (i < best and sum < S) Try(i+1);
			}
			check[j] = true;
			sum -= To[j];
		}
	}
}
int main() {
	cin >> n >> S;
	for (int i = 1; i <= n; i++) {
		cin >> To[i];
	}
	memset(check,true,sizeof(check));
	Try(1);
	if (supercheck == false) {
		cout << "-1";
	} else {
		cout << best << endl;
		for (int i = 1; i <= best; i++) {
			cout << kq[i] << " ";
		}
	}
}