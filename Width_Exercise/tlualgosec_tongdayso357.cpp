#include<bits/stdc++.h>
using namespace std;

// Dùng long long trực tiếp thay vì define int long long để tường minh hơn
// và tránh lỗi tiềm ẩn với main()
using ll = long long;

vector<ll> v;
ll N;

void gen(ll x) {
    v.push_back(x);
    
    // Tính toán trước giá trị tiếp theo để tránh gọi đệ quy thừa
    ll n3 = x * 3 + 1;
    ll n5 = x * 5 + 1;
    ll n7 = x * 7 + 1;

    // Kiểm tra điều kiện trước khi đẩy vào stack đệ quy
    if (n3 < N) gen(n3);
    if (n5 < N) gen(n5);
    if (n7 < N) gen(n7);
}

void solve() {
    cin >> N;
    if (N <= 3) cout << 2 << endl;
    
    // Dự trữ bộ nhớ để vector không phải cấp phát lại nhiều lần
    // Với N = 1 tỷ, số lượng phần tử khoảng vài triệu.
    v.reserve(5000000); 
    
    // Bước 1: Sinh tất cả các số (chấp nhận trùng lặp)
    gen(1);
    
    // Bước 2: Sắp xếp (O(N log N) nhưng trên mảng liền kề nên rất nhanh)
    sort(v.begin(), v.end());
    
    // Bước 3: Loại bỏ trùng lặp
    // unique đẩy các phần tử trùng xuống cuối và trả về vị trí hết phần tử duy nhất
    auto last = unique(v.begin(), v.end());
    v.erase(last, v.end()); // Xóa phần thừa
    
    // Bước 4: Tính tổng
    ll kq = 0;
    for (ll val : v) {
        kq += val;
    }
    
    cout << kq;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}