#include <bits/stdc++.h>
using namespace std;
int N;
int NUM;
int UP[21];
int DOWN[21];
int kq = INT_MAX;
int SumUp = 0;
int SumDown = 0;
int cmin = abs(SumUp-SumDown);
bool check[20];
vector<int> Pos;
vector<int> Hienthi;
void Try(int i) {
	if (abs(SumUp-SumDown) == cmin and i < kq) {
		Hienthi.clear();
		for (int x : Pos) Hienthi.push_back(x);
		kq = i;
	}
	if (abs(SumUp-SumDown) < cmin) {
		Hienthi.clear();
		for (int x : Pos) Hienthi.push_back(x);
		cmin = abs(SumUp-SumDown);
		kq = i;
	}
	if (i == N) return;
	for (int j = 0; j < N; ++j) {
		if (check[j] == true) {
			check[j] = false;
			Pos.push_back(j);
			SumUp = SumUp - UP[j] + DOWN[j];
			SumDown = SumDown - DOWN[j] + UP[j];
			Try(i+1);
			Pos.pop_back();
			SumUp = SumUp + UP[j] - DOWN[j];
			SumDown = SumDown + DOWN[j] - UP[j];
			check[j] = true;
		}
	}
}
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	inFile >> N;
	NUM = pow(2,N);
	memset(check,true,sizeof(check));
	for (int i = 0; i < N; ++i) {
		inFile >> UP[i];
		SumUp += UP[i];
	}
	for (int i = 0; i < N; ++i) {
		inFile >> DOWN[i];
		SumDown += DOWN[i];
	}
    inFile.close();
    Try(0);
    cout << "So vi tri can xoay la: " << kq << endl;
    cout << "Do chenh lech nho nhat: " << cmin << endl;
    cout << "Vi tri can xoay la: ";
    for (int x : Hienthi) cout << x+1 << " ";
}
