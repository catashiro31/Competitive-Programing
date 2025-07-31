#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Edge {
    int to, rev;
    int capacity;
};

class MaxFlow {
public:
    int N;
    vector<vector<Edge>> G;
    vector<int> level;
    vector<int> iter;

    MaxFlow(int N) : N(N) {
        G.resize(N);
        level.resize(N);
        iter.resize(N);
    }

    void add_edge(int from, int to, int capacity) {
        G[from].push_back({to, (int)G[to].size(), capacity});
        G[to].push_back({from, (int)G[from].size() - 1, 0});
    }

    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front(); que.pop();
            for (Edge &e : G[v]) {
                if (e.capacity > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int upTo) {
        if (v == t) return upTo;
        for (int &i = iter[v]; i < G[v].size(); ++i) {
            Edge &e = G[v][i];
            if (e.capacity > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(upTo, e.capacity));
                if (d > 0) {
                    e.capacity -= d;
                    G[e.to][e.rev].capacity += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        const int INF = 1e9;
        while (true) {
            bfs(s);
            if (level[t] < 0) break;
            fill(iter.begin(), iter.end(), 0);
            int f;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
        return flow;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        int nA, nB, nC;
        cin >> nA >> nB >> nC;

        int mA;
        cin >> mA;
        vector<int> wA(mA);
        for (int i = 0; i < mA; ++i) {
            cin >> wA[i];
            --wA[i];
        }

        int mB;
        cin >> mB;
        vector<int> wB(mB);
        for (int i = 0; i < mB; ++i) {
            cin >> wB[i];
            --wB[i];
        }

        int mC;
        cin >> mC;
        vector<int> wC(mC);
        for (int i = 0; i < mC; ++i) {
            cin >> wC[i];
            --wC[i];
        }

        // n+1 - Building A
        // n+2 - Building B
        // n+3 - Building C
        // n+4 - Sink
        int tol_N = n + 5;
        int source = 0;
        int sink = n + 4;
        int bA = n + 1;
        int bB = n + 2;
        int bC = n + 3;

        MaxFlow mf(tol_N);

        for (int i = 0; i < n; ++i) {
            mf.add_edge(source, i + 1, 1);
        }

        for (int t : wA) {
            mf.add_edge(t + 1, bA, 1);
        }
        for (int t : wB) {
            mf.add_edge(t + 1, bB, 1);
        }
        for (int t : wC) {
            mf.add_edge(t + 1, bC, 1);
        }

        mf.add_edge(bA, sink, nA);
        mf.add_edge(bB, sink, nB);
        mf.add_edge(bC, sink, nC);

        cout << mf.max_flow(source, sink) << '\n';
    }

    return 0;
}