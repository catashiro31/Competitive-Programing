#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(all(a)); // Sắp xếp để xử lý đoạn ngắn nhất trước

    int ans = 0;
    int can_noi = n - 1; // Ban đầu có n đoạn, cần n-1 mối nối để thành 1 đoạn

    for (int i = 0; i < n; i++) {
        // Nếu cắt tan đoạn xích a[i] mà vẫn chưa đủ (hoặc vừa đủ) để nối hết phần còn lại
        // Lưu ý: Khi cắt tan a[i], ta mất đi đoạn xích đó (giảm 1 khoảng trống cần nối)
        // và ta thu được a[i] mắt xích để nối a[i] khoảng trống khác.
        // Tổng cộng số khoảng trống giảm đi là: a[i] + 1.
        
        if (can_noi == 0) break; // Đã nối xong

        if (a[i] < can_noi) {
            ans += a[i];          // Tốn công cắt hết a[i] mắt xích
            can_noi -= (a[i] + 1); // Số đoạn cần nối giảm mạnh
        } else {
            // Đoạn này dài quá, chỉ cần cắt đúng số lượng đang thiếu
            ans += can_noi;
            can_noi = 0; // Đã nối xong
            break;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--) solve();
}