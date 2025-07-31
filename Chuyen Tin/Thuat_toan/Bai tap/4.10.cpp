#include <bits/stdc++.h>
using namespace std;
int n = 7;
int arr[8][8];
int pos1 = 1;
int pos2 = 1;
bool supercheck = true;
int dem = 0;
void Backtracking(int i) {
//	cout << pos1 << " " << pos2 << endl;
	if (supercheck == false) return;
	if (i == n*n+1) {
		dem++;
		for (int z1 = 1; z1 <= n; ++z1) {
			for (int z2 = 1; z2 <= n; ++z2) {
				if (arr[z1][z2] < 10) cout << "0" << arr[z1][z2] << " ";
				else cout << arr[z1][z2] << " ";
			}
			cout << endl <<endl;
		}
		supercheck = false;
		cout << endl << endl;
		return;
	}
	if (i > n*n) return;
	for (int j = -2; j <= 2; ++j) {
		if (j == 0) continue;
		for (int k = -2; k <= 2; ++k) {
			if (k == 0 or abs(k) == abs(j)) continue;
			if (0 < pos1 - j and pos1 -j <= n and 0 <  pos2 - k and pos2 - k <= n) {
				pos1 -= j; pos2 -= k;
				if (arr[pos1][pos2] == 0) {
					arr[pos1][pos2] = i;
					Backtracking(i+1);
					arr[pos1][pos2] = 0;
				}
				pos1 += j; pos2 += k;
			}
		}
	}
	
}
int main() {
	memset(arr,0,sizeof(arr));
	arr[1][1] = 1;
	Backtracking(2);
	cout << dem;
}