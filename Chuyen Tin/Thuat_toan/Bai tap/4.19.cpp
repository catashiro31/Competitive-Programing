//O(2^(M+N)*N*M
#include <bits/stdc++.h>
using namespace std;
int kq = 0;
int M, N;
int countOn(vector<vector<int>> grid) {
	int count = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; ++j) {
			if (grid[i][j] == 1) count++;
		}
	}
	return count;
}
void ChangeRow(vector<vector<int>> &grid, int row) {
	for (int i = 0; i < N; ++i) {
		grid[row][i] = 1 - grid[row][i];
	}
	return;
}
void ChangeCol(vector<vector<int>> &grid, int col) {
	for (int i = 0; i < M; ++i) {
		grid[i][col] = 1 - grid[i][col];
	}
}
void Try(vector<vector<int>> &grid, int i) {
	if (i == M+N) {
		if (countOn(grid) > kq) kq = countOn(grid);
		return;
	}
	if (i < M) {
		ChangeRow(grid,i);
		Try(grid,i+1);
		ChangeRow(grid,i);
	} else {
		ChangeCol(grid,i-M);
		Try(grid,i+1);
		ChangeCol(grid,i-M);
	}
	Try(grid,i+1);
}
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	inFile >> N >> M;
	vector<vector<int>> grid(M, vector<int>(N));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			inFile >> grid[i][j];
		}
	}
    inFile.close();
    Try(grid,0);
    cout << kq;
}
// Example Solution - Use Masking and Bitwise - O(2^(M)*N*M
//#include <bits/stdc++.h>
//using namespace std;
//int M, N;
//vector<vector<int>> initialGrid;
//
//// Hàm đếm số đèn sáng trong lưới
//int countLights(const vector<vector<int>>& grid) {
//    int count = 0;
//    for (int i = 0; i < M; i++) {
//        for (int j = 0; j < N; j++) {
//            if (grid[i][j] == 1) {
//                count++;
//            }
//        }
//    }
//    return count;
//}
//
//// Hàm tạo ra trạng thái mới của lưới sau khi tác động vào các công tắc dòng và cột
//vector<vector<int>> toggleGrid(int rowMask, int colMask) {
//    vector<vector<int>> grid = initialGrid;  // Sao chép lưới ban đầu
//
//    // Bật tắt công tắc dòng
//    for (int i = 0; i < M; i++) {
//        if (rowMask & (1 << i)) {  // Nếu dòng i cần bật tắt
//            for (int j = 0; j < N; j++) {
//                grid[i][j] = 1 - grid[i][j];  // Đổi trạng thái bóng đèn
//            }
//        }
//    }
//
//    // Bật tắt công tắc cột
//    for (int j = 0; j < N; j++) {
//        if (colMask & (1 << j)) {  // Nếu cột j cần bật tắt
//            for (int i = 0; i < M; i++) {
//                grid[i][j] = 1 - grid[i][j];  // Đổi trạng thái bóng đèn
//            }
//        }
//    }
//
//    return grid;
//}
//
//int main() {
//    ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
//	inFile >> M >> N;
//    initialGrid.resize(M, vector<int>(N));
//
//    // Nhập lưới ban đầu
//	for (int i = 0; i < M; ++i) {
//		for (int j = 0; j < N; ++j) {
//			inFile >> initialGrid[i][j];
//		}
//	}
//	inFile.close();
//    int maxLights = 0;
//
//    // Duyệt qua tất cả các cách bật/tắt công tắc dòng và cột
//    for (int rowMask = 0; rowMask < (1 << M); rowMask++) {
//        for (int colMask = 0; colMask < (1 << N); colMask++) {
//            vector<vector<int>> grid = toggleGrid(rowMask, colMask);  // Tạo lưới mới sau khi bật tắt
//            int lightsOn = countLights(grid);  // Đếm số đèn sáng
//            maxLights = max(maxLights, lightsOn);  // Cập nhật số đèn sáng nhiều nhất
//        }
//    }
//
//    cout << maxLights << endl;  // In ra số đèn sáng nhiều nhất
//
//    return 0;
//}