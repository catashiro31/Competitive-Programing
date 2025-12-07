#include<bits/stdc++.h>
using namespace std;

// Dùng long long cho cả cost và weight vì weight tích lũy có thể > 2 tỷ
#define int long long 
const int INF = 1e18;

struct state {
    int cost, weight, u;
    
    // Priority Queue mặc định là Max Heap, cần đảo ngược để thành Min Heap
    bool operator>(const state& other) const {
        return cost > other.cost;
    }
};

void solve() {
    int n, m; 
    if (!(cin >> n >> m)) return;
    
    vector<int> w(n);
    for (int &x : w) cin >> x;
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    priority_queue<state, vector<state>, greater<state>> pq;
    
    // TỐI ƯU 1: Chỉ cần lưu min_weight đã từng đi qua đỉnh i
    // Khởi tạo INF
    vector<int> min_weight(n, INF);
    
    // cost = 0, weight ban đầu = w[0]
    pq.push({0, w[0], 0});
    // min_weight[0] chưa cập nhật ngay để logic trong vòng lặp xử lý, 
    // hoặc cập nhật luôn cũng được nhưng phải cẩn thận logic đẩy vào.
    
    vector<int> kq(n, -1);
    
    while (!pq.empty()) {
        auto [cost, weight, u] = pq.top(); 
        pq.pop();
        
        // TỐI ƯU 2: Cắt tỉa nhánh (Pruning)
        // Vì Dijkstra luôn lấy cost tăng dần, nên nếu ta gặp một trạng thái
        // có weight >= min_weight từng thấy, nghĩa là trạng thái này 
        // vừa đắt hơn (hoặc bằng), vừa nặng hơn (hoặc bằng) -> Vứt.
        if (weight >= min_weight[u]) continue;
        
        // Cập nhật min_weight mới (nhỏ hơn) cho đỉnh u
        min_weight[u] = weight;

        // Lưu kết quả lần đầu tiên chạm tới u (đây là cost nhỏ nhất)
        if (kq[u] == -1) kq[u] = cost;
        
        for (int v : adj[u]) {
            int new_cost = cost + weight;
            int new_weight = w[v] + weight;
            
            // Chỉ đẩy vào nếu weight mới có triển vọng nhỏ hơn cái đã biết ở v
            if (new_weight < min_weight[v]) {
                pq.push({new_cost, new_weight, v});
            }
        }
    }
    
    // TỐI ƯU 3: Thay endl bằng "\n"
    for (int x : kq) cout << x << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}