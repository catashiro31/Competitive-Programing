#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int k;
int size;
string arr[10][10];
int count = 0;
void cover(int x, int y, int s, int t) {
	if (s == 2) {
		count++;
		string xau = to_string(count);
		if (count < 10) xau = " " + xau;
		if (t != 1) arr[x][y] = xau;
		if (t != 2) arr[x][y+1] = xau;
		if (t != 3) arr[x+1][y] = xau;
		if (t != 4) arr[x+1][y+1] = xau;
	} else {
		int z = s/2;
		int a = s/4;
		if (t == 1)	{
			cover(x+z,y,z,2);
			cover(x,y+z,z,3);
			cover(x+a,y+a,z,1);
			cover(x+z,y+z,z,1);
		}
		if (t == 2)	{
			cover(x,y,z,4);
			cover(x+a,y+a,z,2);
			cover(x+z,y,z,2);
			cover(x+z,y+z,z,1);
		}
		if (t == 3)	{
			cover(x,y,z,4);
			cover(x,y+z,z,3);
			cover(x+a,y+a,z,3);
			cover(x+z,y+z,z,1);
		}
		if (t == 4)	{
			cover(x,y,z,4);
			cover(x,y+z,z,3);
			cover(x+a,y+a,z,4);
			cover(x+z,y,z,2);
		}
	}
	return;
}
int main() {
	cin >> k;
	size = pow(2,k);
	cover(0,0,size,2);
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (arr[i][j] != "") cout << arr[i][j] << " ";
			if (arr[i][j] == "") cout << " 0" << " ";
		}
		cout << endl <<endl;
	}
}