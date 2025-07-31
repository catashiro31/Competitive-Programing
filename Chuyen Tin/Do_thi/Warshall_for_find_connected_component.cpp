#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int n, m; 
	inFile >> n >> m;
	vector<vector<int>> adjMatrix(n,vector<int> (n,false));
	for (int i = 0; i < m; ++i)  {
		int u, v; inFile >> u >> v;
		adjMatrix[u-1][v-1] = true;
		adjMatrix[v-1][u-1] = true;
	}
	inFile.close();
	for (int i = 0; i < m; ++i) adjMatrix[i][i] = true;
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				adjMatrix[i][j] = adjMatrix[i][j] || (adjMatrix[i][k] && adjMatrix[k][j]);
			}
		}
	}
	vector<int> avail(n,false);
	int ccount = 0;
	for (int i = 0; i < n; ++i) {
		if (!avail[i]) {
			ccount++;
			cout << "Connected Component " << ccount << ": ";
			for (int j = 0; j < n; ++j) {
				if (adjMatrix[i][j]) {
					cout << j+1 << " ";
					avail[j] = true;
				}
			}
			cout << '\n';
		}
	}
	return 0;
}
