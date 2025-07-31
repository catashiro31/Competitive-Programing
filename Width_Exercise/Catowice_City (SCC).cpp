// SCC cuối cùng (SCC cuối cùng được tìm thấy khi duyệt DFS ngược) chỉ có thể nhận đường đi từ 
// các SCC khác, nhưng không thể đi đến SCC nào khác do đặc điểm DAG của đồ thị co.
#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
void DFS1(vector<int> adjList[], vector<bool> &visited, int u, stack<int> &st) {
	visited[u] = true;
	for (int v : adjList[u]) {
		if (!visited[v]) DFS1(adjList,visited,v,st);
	}
	st.push(u);
}
void DFS2(vector<int> TadjList[], vector<int> &scc, int u, int tmp) {
	scc[u] = tmp;
	for (int v : TadjList[u]) {
		if (scc[v] == -1) DFS2(TadjList,scc,v,tmp);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<int> adjList[n];
		vector<int> TadjList[n];
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			if (u == v) continue;
			adjList[u-1].push_back(v-1);
			TadjList[v-1].push_back(u-1);
		}
		vector<bool> visited(n,false);
		stack<int> st;
		for (int i = 0; i < n; i++) {
			if (!visited[i]) DFS1(adjList,visited,i,st);
		}
		vector<int> scc(n,-1);
		int tmp = 0;
		while (!st.empty()) {
			int u = st.top(); st.pop();
			if (scc[u] != -1) continue;
			DFS2(TadjList,scc,u,tmp);
			tmp++;
		}
		if (tmp == 1) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			vector<int> jury;
			vector<int> contester;
			for (int i = 0; i < n; i++) {
				if (scc[i] == tmp-1) jury.push_back(i);
				else contester.push_back(i);
			}
			cout << jury.size() << " " << contester.size() << endl;
			for (int u : jury) cout << u+1 << " ";
			cout << endl;
			for (int u : contester) cout << u+1 << " ";
			cout << endl;
		}
	}
	return 0;
}