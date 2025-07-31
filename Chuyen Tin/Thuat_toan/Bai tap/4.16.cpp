#include <bits/stdc++.h>
using namespace std;
int N = 8;
int check[9];
int sum = 0;
int kq = 0;
int arr[9][9];
bool cheochinh[16];
bool cheophu[16];
void Try(int i) {
	for (int j = 1; j <= 8; ++j) {
		if (cheochinh[i+j-1] == true and cheophu[i-j+N] == true) {
			cheochinh[i+j-1] = false;
			cheophu[i-j+N] = false;
			sum += arr[j][i];
			if (i == N) {
				if (sum > kq) kq = sum;
			} else Try(i+1);
			sum -= arr[j][i];
			cheochinh[i+j-1] = true;
			cheophu[i-j+N] = true;
		}
	}
}
int main() {
    ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            inFile >> arr[i][j];
        }
    }
    inFile.close();
	memset(cheophu,true,sizeof(cheophu));
	memset(cheochinh,true,sizeof(cheochinh));
	Try(1);
	cout << kq;
}