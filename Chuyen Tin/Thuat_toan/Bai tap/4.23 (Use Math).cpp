#include <bits/stdc++.h>
using namespace std;

string S;

void Solution() {
    int n = S.size();
    int x = 0, y = 0, z = 0;
    
    // Đếm số lượng 'A', 'B', 'C'
    for (char c : S) {
        if (c == 'A') x++;
        else if (c == 'B') y++;
        else if (c == 'C') z++;
    }

    // Bước 1: Xử lý các cặp sai vùng
    int ccount = 0;
    // Đếm số lượng 'B' và 'C' trong vùng 'A'
    int AB = 0, AC = 0;
    for (int i = 0; i < x; ++i) {
        if (S[i] == 'B') AB++;
        else if (S[i] == 'C') AC++;
    }
    
    // Đếm số lượng 'A' và 'C' trong vùng 'B'
    int BA = 0, BC = 0;
    for (int i = x; i < x + y; ++i) {
        if (S[i] == 'A') BA++;
        else if (S[i] == 'C') BC++;
    }
    
    // Đếm số lượng 'A' và 'B' trong vùng 'C'
    int CA = 0, CB = 0;
    for (int i = x + y; i < n; ++i) {
        if (S[i] == 'A') CA++;
        else if (S[i] == 'B') CB++;
    }
    
    // Đổi chỗ các cặp để đúng vị trí
    int step1 = min(AB, BA) + min(AC, CA) + min(BC, CB);
    ccount += step1;
    
    // Bước 2: Xử lý các bộ ba ký tự
    int remaining = abs(AB - BA) + abs(AC - CA) + abs(BC - CB);
    int step2 = remaining / 3 * 2;
    ccount += step2;

    // In kết quả
    cout << ccount << endl;
}

int main() {
    ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
    inFile >> S;
    inFile.close();
    Solution();
    return 0;
}
