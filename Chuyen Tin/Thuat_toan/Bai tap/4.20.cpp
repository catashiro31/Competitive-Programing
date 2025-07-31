#include <bits/stdc++.h>
using namespace std;
int kq = INT_MAX;
int sum = 0;
bool supercheck(vector<vector<int>> grid) {
	int tmp = grid[0][0];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (tmp != grid[i][j]) return false;
		}
	}
	return true;
}
void Try (vector<vector<int>> &grid, int i) {
	if (i == 16 or sum > kq) {
		if (supercheck(grid) == true) {
			if (sum < kq) {
				kq = sum;
			}
		}
		return;
	}
	int row = i/4;
	int col = i%4;
	sum++;
	grid[row][col] = 1 - grid[row][col];
	if (0 <= row-1 and row-1 <= 3 and 0 <= col and col <= 3) grid[row-1][col] = 1 - grid[row-1][col];
	if (0 <= row+1 and row+1 <= 3 and 0 <= col and col <= 3) grid[row+1][col] = 1 - grid[row+1][col];
	if (0 <= row and row <= 3 and 0 <= col+1 and col+1 <= 3) grid[row][col+1] = 1 - grid[row][col+1];
	if (0 <= row and row <= 3 and 0 <= col-1 and col-1 <= 3) grid[row][col-1] = 1 - grid[row][col-1];
	Try(grid,i+1);
	grid[row][col] = 1 - grid[row][col];
	sum--;
	if (0 <= row-1 and row-1 <= 3 and 0 <= col and col <= 3) grid[row-1][col] = 1 - grid[row-1][col];
	if (0 <= row+1 and row+1 <= 3 and 0 <= col and col <= 3) grid[row+1][col] = 1 - grid[row+1][col];
	if (0 <= row and row <= 3 and 0 <= col+1 and col+1 <= 3) grid[row][col+1] = 1 - grid[row][col+1];
	if (0 <= row and row <= 3 and 0 <= col-1 and col-1 <= 3) grid[row][col-1] = 1 - grid[row][col-1];
	Try(grid,i+1);
	
}
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	vector<vector<int>> grid (4,vector<int>(4));
	for (int i = 0; i < 4; ++i) {
		string xau;
		inFile >> xau;
		for (int j = 0; j < 4; ++j) {
			if (xau[j] == 'w') grid[i][j] = 1;
			else grid[i][j] = 0;
		}
	}
    inFile.close();
    Try(grid,0);
    if (kq == INT_MAX) {
    	cout << "Impossible";
    	return 0;
	}
    cout << kq;
}
