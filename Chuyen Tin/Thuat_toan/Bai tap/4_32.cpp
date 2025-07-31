#include <bits/stdc++.h>
using namespace std;
int k;
int xPos, yPos;
int size;
void output(vector<vector<int>> floor) {
	for (int i = 0;i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (floor[i][j] < 10) cout << " " << floor[i][j] << " ";
			else cout << floor[i][j] << " ";
		}
		cout << endl << endl;
	}
}
int ccount = 1;
void Hinh_mu(vector<vector<int>> &floor, int side, int ybegin, int xbegin, int status) {
	if (side == 2) {
		if (status == 4) {
			floor[ybegin][xbegin] = ccount;
			floor[ybegin+1][xbegin] = ccount;
			floor[ybegin][xbegin+1] = ccount;
		} else if (status == 2) {
			floor[ybegin][xbegin] = ccount;
			floor[ybegin+1][xbegin] = ccount;
			floor[ybegin+1][xbegin+1] = ccount;
		} else if (status == 1) {
			floor[ybegin][xbegin+1] = ccount;
			floor[ybegin+1][xbegin+1] = ccount;
			floor[ybegin+1][xbegin] = ccount;
		} else if (status == 3) {
			floor[ybegin][xbegin] = ccount;
			floor[ybegin][xbegin+1] = ccount;
			floor[ybegin+1][xbegin+1] = ccount;
		}
		ccount++;
		return;
	} else {
		int tmp = side/2;
		if (status == 1) {
			Hinh_mu(floor,tmp,ybegin+tmp,xbegin,2);
			Hinh_mu(floor,tmp,ybegin+tmp/2,xbegin+tmp/2,1);
			Hinh_mu(floor,tmp,ybegin+tmp,xbegin+tmp,1);
			Hinh_mu(floor,tmp,ybegin,xbegin+tmp,3);
		} else if (status == 2) {
			Hinh_mu(floor,tmp,ybegin,xbegin,4);
			Hinh_mu(floor,tmp,ybegin+tmp/2,xbegin+tmp/2,2);
			Hinh_mu(floor,tmp,ybegin+tmp,xbegin,2);
			Hinh_mu(floor,tmp,ybegin+tmp,xbegin+tmp,1);
		} else if (status == 3) {
			Hinh_mu(floor,tmp,ybegin,xbegin,4);
			Hinh_mu(floor,tmp,ybegin,xbegin+tmp,3);
			Hinh_mu(floor,tmp,ybegin+tmp/2,xbegin+tmp/2,3);
			Hinh_mu(floor,tmp,ybegin+tmp,xbegin+tmp,1);
		} else if (status == 4)  {
			Hinh_mu(floor,tmp,ybegin,xbegin,4);
			Hinh_mu(floor,tmp,ybegin,xbegin+tmp,3);
			Hinh_mu(floor,tmp,ybegin+tmp/2,xbegin+tmp/2,4);
			Hinh_mu(floor,tmp,ybegin+tmp,xbegin,2);
		}
	}
}
void Hinh_vuong(vector<vector<int>> &floor, int side, int ybegin, int xbegin) {
	if (side == 2) {
		for (int i = ybegin; i <= ybegin+1; i++) {
			for (int j = xbegin; j <= xbegin+1; j++) {
				if (i == yPos and j == xPos) continue;
				floor[i][j] = ccount;
			}
		}
		ccount++;
		return;
	} else {
		if (yPos >= ybegin+side/2) {
			if (xPos >= xbegin+side/2) {
				Hinh_mu(floor,side,ybegin,xbegin,4);
				Hinh_vuong(floor,side/2,ybegin+side/2,xbegin+side/2);
			} else {
				Hinh_mu(floor,side,ybegin,xbegin,3);
				Hinh_vuong(floor,side/2,ybegin+side/2,xbegin);
			}
		} else {
			if (xPos >= xbegin+side/2) {
				Hinh_mu(floor,side,ybegin,xbegin,2);
				Hinh_vuong(floor,side/2,ybegin,xbegin+side/2);
			}  else {
				Hinh_mu(floor,side,ybegin,xbegin,1);
				Hinh_vuong(floor,side/2,ybegin,xbegin);
			}
		}
	}
}
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	inFile >> k;
	inFile >> xPos >> yPos;
	xPos--;
	yPos--;
    inFile.close();
    size = pow(2,k);
    vector<vector<int>> floor (size,vector<int>(size));
    Hinh_vuong(floor,size,0,0);
    output(floor);
}
