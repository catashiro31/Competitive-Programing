#include <bits/stdc++.h>
using namespace std;
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int N, D;
	int S[N];
	inFile >> N >> D;
	for (int i = 0; i < N; i++) inFile >> S[i];
    inFile.close();
    sort(S,S+N,greater<int>());
    bool check[N];
    memset(check,true,sizeof(check));
    int sum = 0;
    int kq = 0;
    while (true) {
    	for (int i = 0; i < N; ++i) {
    		if (check[i] == true) {
    			if (sum + S[i] < D) {
    				check[i] = false;
    				sum += S[i];
				}
			}
		}
		if (sum == 0) break;
		kq++;
		sum = 0;
	}
	cout << kq;
}
