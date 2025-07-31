#include <bits/stdc++.h>
using namespace std;
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	pair<int,int> Ps;
	inFile >> Ps.first >> Ps.second;
    inFile.close();
    Ps.first*=2;
    Ps.second*=2;
	vector<int> U;
	for (int j = 1; j <= sqrt(Ps.second); j++) {
		if (Ps.second % j == 0) {
			U.push_back(j);
			if (j != Ps.second/j) U.push_back(Ps.second/j);
		}
	}
	sort(U.begin(),U.end(),greater<int> ());
	int dem = 0;
	vector<int> kq;
	int ccount = 0;
	while (Ps.first != 0) {
		if (Ps.first >= U[dem]) {
			ccount++;
			kq.push_back(Ps.second/U[dem]);
			Ps.first -= U[dem];
		} else {
			dem++;
		}
	}
	cout << ccount << endl;
	for (int x : kq) cout << x << " ";
}
