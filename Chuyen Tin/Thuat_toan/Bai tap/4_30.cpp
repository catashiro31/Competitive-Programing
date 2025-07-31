#include <bits/stdc++.h>
using namespace std;
int K;
long int M, N;
long int dem;
int Try(int i) {
	if (i == 1) return M;
	int tmp = i/2;
	if (i % 2 == 0) return ((Try(tmp)%dem)*(Try(tmp)%dem))%dem;
	else return ((Try(tmp)%dem)*(Try(tmp)%dem)*M)%dem;
}
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	inFile >> K >> M >> N;
	dem = pow(10,K);
    inFile.close();
    cout << Try(N);
}
