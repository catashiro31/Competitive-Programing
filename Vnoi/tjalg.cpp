#include <bits/stdc++.h>
#define endl '\n'
#define INF 1e9
#define LINF 1e18
#define pii pair<int,int>
#define pli pair<long,int>
#define plli pair<ll,int>
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define sz(x) ((x).size())
#define vi vector<int>
#define vl vector<long>
#define vll vector<long long>
#define fo(i,a,b) for(int i=(a); i <= (b); ++i)
#define fod(i,a,b) for(int i=(b); i >= (a); --i)
#define rep(i,n) for(int i= 0; i < (n); ++i)
#define repd(i,n) for(int i= (n)-1; i >= 0; --i)
#define mod 1000000007
using ll = long long;
using namespace std;
void DFS(vector<vi> adjList, int u, vector<bool> &visited, stack<int> &s) {
	visited[u] = true;
	for(int v : adjList[u]) {
		if (!visited[v]) DFS(adjList,v,visited,s);
	}
	s.push(u);
}
void Kosaraju(vector<vi> TadjList, int u, vector<bool> &visited) {
	visited[u] = true;
	for (int v : TadjList[u]) {
		if (!visited[v]) Kosaraju(TadjList,v,visited);
	}
} 
void solve() {
	int n, m; cin >> n >> m;
	vector<vi> adjList(n), TadjList(n);
	rep(i,m) {
		int u,v; cin >> u >> v;
		adjList[u-1].pb(v-1);
		TadjList[v-1].pb(u-1);
	}
	stack<int> s;
	vector<bool> visited(n,false);
	rep(i,n) if (!visited[i]) DFS(adjList,i,visited,s);
	rep(i,n) visited[i] = false;
	int kq = 0;
	while(!s.empty()) {
		int u = s.top(); s.pop();
		if (visited[u]) continue;
		kq++;
		Kosaraju(TadjList,u,visited);
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt","r",stdin);
	solve();
}
