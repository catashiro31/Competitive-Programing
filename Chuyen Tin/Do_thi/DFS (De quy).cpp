#include <bits/stdc++.h>
using namespace std;
vector<int> tracer;
void DFSVisit(int u, vector<vector<int>> adjList, vector<bool> &ctravel, int t) {
	if (u == t) {
		for (int i = 0; i < tracer.size()-1; ++i) {
			cout << tracer[i] << " --> ";
		}
		cout << tracer[tracer.size()-1];
		return;
	}
	for (int v : adjList[u]) {
		if (ctravel[v]) {
			ctravel[v] = false;
			tracer.push_back(v);
			DFSVisit(v,adjList,ctravel,t);
			tracer.pop_back();
			ctravel[v] = true;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int n, m; inFile >> n >> m;
	int s, t; inFile >> s >> t;
	vector<vector<int>> adjList(n);
	for (int i = 0; i < m; ++i) {
		int u, v; inFile >> u >> v;
		adjList[u].push_back(v);
	}
	inFile.close();
	vector<bool> ctravel(n,true);
	ctravel[s] = false;
	tracer.push_back(s);
	DFSVisit(s,adjList,ctravel,t);
}
