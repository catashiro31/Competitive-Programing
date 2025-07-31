#include <bits/stdc++.h>
using namespace std;
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int N;
	inFile >> N;
	pair<int,int> D[N];
	for (int i = 0; i < N; i++) {
		inFile >> D[i].second >> D[i].first;
	}
	inFile.close();
	sort(D,D+N);
	for (int i = 0; i < N; ++i) {
		swap(D[i].second,D[i].first);
	}
	set<int> kq;
	for (int i = 0; i < N; i++) {
		if (sizeof(kq) == 0) {
			kq.insert(D[i].second-1);
			kq.insert(D[i].second);
		} else {
			int ccount = 0;
			for (int x : kq) {
				if (D[i].first <= x and x <= D[i].second) ccount++;
				if (ccount == 2) break;
			}
			if (ccount == 0) {
				kq.insert(D[i].second);
				kq.insert(D[i].second-1);
			}
			if (ccount == 1) kq.insert(D[i].second);
		}
	}
	for (int x : kq) cout << x << " ";
}
