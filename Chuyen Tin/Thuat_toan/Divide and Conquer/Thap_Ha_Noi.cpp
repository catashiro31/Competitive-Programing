#include <iostream>
using namespace std;
void Move(int n, int tmp1, int tmp2, int tmp3) {
	if (n == 1) {
		cout << "Move:  " << tmp1 << " -> " << tmp2 << endl; 
	} else {
		Move(n-1,tmp1,tmp3,tmp2);
		Move(1,tmp1,tmp2,tmp3);
		Move(n-1,tmp3,tmp2,tmp1);
	}
}
int main() {
	int n;
	cin >> n;
	Move(n,1,2,3);
}