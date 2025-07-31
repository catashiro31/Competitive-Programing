#include <bits/stdc++.h>
long int N;
long int a;
int Try(int i) {
	if (i == 1) return a;
	long int tmp = i/2;
	if (i % 2 == 0) return ((Try(tmp)%N)*Try(tmp)%N)%N;
	else return ((Try(tmp)%N)*Try(tmp)%N*a)%N;
}
using namespace std;
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	inFile >> N;
    inFile.close();
    srand(time(NULL));
    a = rand() % (N-3) + 2;
    if (Try(N-1) == 1) cout << "La so gia nguyen to";
    else cout << "Ko la so gia nguyen to";
}
