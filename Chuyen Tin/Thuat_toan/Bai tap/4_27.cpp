#include <bits/stdc++.h>
using namespace std;
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int N;
	inFile >> N;
    inFile.close();
    string kq = "";
    while (N % 2 == 0) {
		N /= 2;
		kq += "*2";
	}
	int ccount = 1;
    int tmp1 = N*3;
    int tmp2 = N*3+2;
    while (int(log2(tmp1)) == int(log2(tmp2))) {
    	tmp1 = tmp1*3;
    	tmp2 = tmp2*3+2;
    	ccount++;
	}
	for (int i = 0; i < ccount; i++) kq = "/3"+kq;
	for (int i = 0; i < int(log2(tmp2)); i++) kq = "*2"+kq;
	kq = "1"+kq;
	cout << kq;
}
