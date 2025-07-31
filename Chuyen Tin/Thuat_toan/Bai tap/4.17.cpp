#include <bits/stdc++.h>
using namespace std;
int n, w;
int a[21];
int c[21];
int weight = 0;
int value = 0;
int kq = 0;
bool check[21];
vector<int> tmp;
vector<int> Selection;
void Try (int i) {
	int maxx = 0;
	if (i == n) return;
	for (int j = 1; j <= n; ++j) {
		if (c[j] > maxx) maxx = c[j];
	}
	if (value + (n-i)*maxx < kq) return;
	for (int j = 1; j <= n; ++j) {
		if (check[j] == true) {
			check[j] = false;
			tmp.push_back(j);
			weight += a[j];
			value += c[j];
			if (weight <= w) {
				if (value > kq) {
					Selection.clear();
					for (int x : tmp) Selection.push_back(x);
					kq = value;
				}
				Try(i+1);
			}
			tmp.pop_back();
			check[j] = true;
			weight -= a[j];
			value -= c[j];
		}
	}
}
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	inFile >> n >> w;
	for (int i = 1; i <= n; ++i) inFile >> a[i];
	for (int i = 1; i <= n; ++i) inFile >> c[i];
    inFile.close();
    memset(check,true,sizeof(check));
	Try(0);
	cout << kq << endl;
	for (int x : Selection) cout << x << " ";
}
