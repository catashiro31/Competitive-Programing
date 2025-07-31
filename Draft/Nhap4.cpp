#include <bits/stdc++.h>
using namespace std;

int N, K;
bool cheochinh[20];
bool cheophu[20];
int dem = 0;

// Hàm đệ quy backtracking
void Backtracking(int i, int x, int y) {  // x, y là vị trí hiện tại bắt đầu duyệt
    if (i == K) {  // Nếu đã đặt đủ K quân tượng
        dem++;
        return;
    }

    // Duyệt từ vị trí x, y trên bàn cờ
    for (int j = x; j <= N; ++j) {
        for (int k = (j == x ? y : 1); k <= N; ++k) {  // Bắt đầu từ cột y nếu đang ở hàng đầu tiên x, và từ cột 1 nếu ở hàng khác
            if (cheochinh[j + k - 1] && cheophu[j - k + N]) {  // Nếu không có xung đột trên các đường chéo
                cheochinh[j + k - 1] = false;  // Đánh dấu đường chéo chính là đã bị chiếm
                cheophu[j - k + N] = false;    // Đánh dấu đường chéo phụ là đã bị chiếm

                // Đặt quân tượng tiếp theo, bắt đầu từ ô tiếp theo
                Backtracking(i + 1, j, k + 1);

                // Quay lui
                cheochinh[j + k - 1] = true;   // Bỏ đánh dấu đường chéo chính
                cheophu[j - k + N] = true;     // Bỏ đánh dấu đường chéo phụ
            }
        }
    }
}

int main() {
    // Kích thước bàn cờ N và số quân tượng K
    N = 7;
    K = 10;

    // Khởi tạo các mảng đánh dấu đường chéo chính và phụ là true
    memset(cheophu, true, sizeof(cheophu));
    memset(cheochinh, true, sizeof(cheochinh));

    // Gọi hàm đệ quy bắt đầu từ quân tượng đầu tiên
    Backtracking(0, 1, 1);

    // In ra số cách đặt quân
    cout << dem;
    return 0;
}
