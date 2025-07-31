#include <bits/stdc++.h>
using namespace std;
void adjMatrixToEdgeList(const vector<vector<int>> &adjMatrix) {
	int n = adjMatrix.size();
	vector<pair<int,int>> edgeList;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (adjMatrix[i][j] != 0) edgeList.push_back({i+1,j+1});
		}
	}
	for (auto x : edgeList) cout << x.first << " " << x.second << '\n';
}
void edgeListToAdjMatrix(const vector<pair<int,int>> &edgeList) {
	int n = edgeList.size()-1;
	vector<vector<int>> adjMatrix (n,vector<int> (n,0));
	for (int i = 0; i < edgeList.size(); ++i) {
		adjMatrix[edgeList[i].first-1][edgeList[i].second-1] = 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << adjMatrix[i][j] << " ";
		}
		cout << '\n';
	}
}
void adjMatrixToAdjList(const vector<vector<int>> &adjMatrix) {
	int n = adjMatrix.size();
	vector<vector<int>> adjList(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (adjMatrix[i][j] != 0) adjList[i].push_back(j+1);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int v : adjList[i]) {
			cout << v << " ";
		}
		cout << '\n';
	}
}
void adjListToAdjMatrix(const vector<vector<int>> &adjList) {
	int n = adjList.size();
	vector<vector<int>> adjMatrix(n, vector<int> (n,0));
	for (int i = 0; i < n; ++i) {
		for (int v : adjList[i]) adjMatrix[i][v-1] = 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << adjMatrix[i][j] << " ";
		}
		cout << '\n';
	}
}
void edgeListToAdjList(const vector<pair<int,int>> &edgeList, int n) {
	vector<vector<int>> adjList(n);
	for (auto e : edgeList) {
		adjList[e.first-1].push_back(e.second);
	}
	for (int i = 0; i < n; ++i) {
		for (int v : adjList[i]) cout << v << " ";
		cout << '\n';
	}
}
void adjListToEdgeList(const vector<vector<int>> &adjList) {
	int n = adjList.size();
	vector<pair<int,int>> edgeList;
	for (int i = 0; i < n; ++i) {
		for (int v : adjList[i]) edgeList.push_back({i+1,v});
	}
	for (auto e : edgeList) cout << e.first << " " << e.second << '\n';
}
void edgeListToIncidenceMatrix(const vector<pair<int,int>> &edgeList, int n) {
	int m = edgeList.size();
	vector<vector<int>> incidenceMatrix(n, vector<int>(m,0));
	for (int i = 0; i < m; ++i) {
		int u = edgeList[i].first-1;
		int v = edgeList[i].second-1;
		incidenceMatrix[u][i] = 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) cout << incidenceMatrix[i][j] << " ";
		cout << '\n';
	}
}
void incidenceMatrixToEdgeList(const vector<vector<int>>& incidenceMatrix) {
    int n = incidenceMatrix.size();    // So dinh
    int m = incidenceMatrix[0].size(); // So canh
    vector<pair<int, int>> edgeList;
    for (int j = 0; j < m; ++j) {
        int u = -1, v = -1;
        for (int i = 0; i < n; ++i) {
            if (incidenceMatrix[i][j] == 1) {
                if (u == -1) u = i;
                else v = i;
            }
        }
        if (u != -1 && v != -1) edgeList.push_back({u+1, v+1});
    }
    for (auto e : edgeList) cout << e.first << " " << e.second << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	inFile.close();
	// Do thi co huong
	vector<vector<int>> adjMatrix = {
		{0, 1, 0},
		{1, 0, 1},
		{0, 1, 0}
	};
	vector<pair<int,int>> edgeList = {{1,2},{1,3},{2,3},{2,4}};
	vector<vector<int>> adjList = {
		{2},
		{1, 3},
		{2}
	};
	vector<vector<int>> incidenceMatrix = {
        {1, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 1, 0},
        {0, 0, 0, 1}
    };
	int n = 4; //so dinh
//	adjMatrixToEdgeList(adjMatrix);
//	edgeListToAdjMatrix(edgeList);
//	adjMatrixToAdjList(adjMatrix);
//	adjListToAdjMatrix(adjList);
//	edgeListToAdjList(edgeList,n);
//	adjListToEdgeList(adjList);
//	edgeListToIncidenceMatrix(edgeList,n);
	incidenceMatrixToEdgeList(incidenceMatrix);
}
