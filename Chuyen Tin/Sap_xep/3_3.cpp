#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int main() {
	string xau;
	cin >> xau;
	unordered_set<string> kq;
	string dem;
	for (int i = 1; i <= xau.length(); i++) {
		for (int j = 0; j < xau.length()-i+1; j++) {
			dem = xau.substr(j,i);
			kq.insert(dem);
		}
	}
	cout << kq.size();
}