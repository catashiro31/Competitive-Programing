#include <bits/stdc++.h>

using namespace std;

int M, N;
vector<vector<int>> initialGrid;

// Hàm đếm số đèn sáng trong lưới
int countLights(const vector<vector<int>>& grid) {
    int count = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

// Hàm tạo ra trạng thái mới của lưới sau khi tác động vào các công tắc dòng và cột
vector<vector<int>> toggleGrid(int rowMask, int colMask) {
    vector<vector<int>> grid = initialGrid;  // Sao chép lưới ban đầu

    // Bật tắt công tắc dòng
    for (int i = 0; i < M; i++) {
        if (rowMask & (1 << i)) {  // Nếu dòng i cần bật tắt
            for (int j = 0; j < N; j++) {
                grid[i][j] = 1 - grid[i][j];  // Đổi trạng thái bóng đèn
            }
        }
    }

    // Bật tắt công tắc cột
    for (int j = 0; j < N; j++) {
        if (colMask & (1 << j)) {  // Nếu cột j cần bật tắt
            for (int i = 0; i < M; i++) {
                grid[i][j] = 1 - grid[i][j];  // Đổi trạng thái bóng đèn
            }
        }
    }

    return grid;
}

int main() {
    ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	inFile >> M >> N;
    initialGrid.resize(M, vector<int>(N));

    // Nhập lưới ban đầu
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			inFile >> initialGrid[i][j];
		}
	}
	inFile.close();
    int maxLights = 0;

    // Duyệt qua tất cả các cách bật/tắt công tắc dòng và cột
    for (int rowMask = 0; rowMask < (1 << M); rowMask++) {
        for (int colMask = 0; colMask < (1 << N); colMask++) {
            vector<vector<int>> grid = toggleGrid(rowMask, colMask);  // Tạo lưới mới sau khi bật tắt
            int lightsOn = countLights(grid);  // Đếm số đèn sáng
            maxLights = max(maxLights, lightsOn);  // Cập nhật số đèn sáng nhiều nhất
        }
    }

    cout << maxLights << endl;  // In ra số đèn sáng nhiều nhất

    return 0;
}


