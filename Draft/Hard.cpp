#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Hard";
void solve() {
	// LIST PROBLEMS
	set<string> s = {
	"https://oj.vnoi.info/problem/bedao_m03_covigame",
	"https://oj.vnoi.info/problem/bedao_m10_hidden",
	"https://oj.vnoi.info/problem/bedao_m10_raid",
	"https://oj.vnoi.info/problem/bedao_m24_d",
	"https://cses.fi/problemset/task/1748",
	"https://usaco.org/index.php?page=viewproblem2&cpid=1041",
	"https://oj.vnoi.info/problem/bedao_r01_zstring",
	"https://csacademy.com/contest/archive/task/bfs-dfs/statement/",
	"https://atcoder.jp/contests/abc197/tasks/abc197_f",
	"https://cses.fi/problemset/task/1690",
	"https://codeforces.com/contest/2074/problem/C",
	"https://oj.vnoi.info/problem/segtree_itmix",
	"https://oj.vnoi.info/problem/atcoder_dp_p",
	"https://codeforces.com/contest/2085/problem/C",
	"https://codeforces.com/contest/2085/problem/D",
	"https://codeforces.com/contest/2091/problem/F",
	"https://oj.vnoi.info/problem/bedao_r03_kindness",
	"https://oj.vnoi.info/problem/bedao_r05_carray",
	"https://oj.vnoi.info/problem/bedao_r05_factory",
	"https://oj.vnoi.info/problem/bedao_r04_marble",
	"https://laptrinhonline.club/problem/tichpxllshiper",
	"https://oj.vnoi.info/problem/bedao_r13_xorqry",
	"https://oj.vnoi.info/problem/bedao_r14_sumxor",
	"https://oj.vnoi.info/problem/bedao_r14_bracket",
	
	};
	int i = 1;
	map<string,string> cm;
	
	// UPDATE COMMIT
	cm["https://oj.vnoi.info/problem/bedao_m10_hidden"] = "EASY";
	cm["https://oj.vnoi.info/problem/bedao_m03_covigame"] = "MEDIUM";
	cm["https://oj.vnoi.info/problem/bedao_m10_raid"] = "HARD";
	cm["https://oj.vnoi.info/problem/bedao_m24_d"] = "HARD";
	cm["https://cses.fi/problemset/task/1748"] = "MEDIUM";
	cm["https://usaco.org/index.php?page=viewproblem2&cpid=1041"] = "MEDIUM";
	cm["https://oj.vnoi.info/problem/bedao_r01_zstring"] = "MEDIUM";
	cm["https://csacademy.com/contest/archive/task/bfs-dfs/statement/"] = "MEDIUM";
	cm["https://atcoder.jp/contests/abc197/tasks/abc197_f"] = "HARD";
	cm["https://cses.fi/problemset/task/1690"] = "MEDIUM";
	cm["https://codeforces.com/contest/2074/problem/C"] = "MEDIUM";
	cm["https://oj.vnoi.info/problem/segtree_itmix"] = "HARD";
	cm["https://oj.vnoi.info/problem/atcoder_dp_p"] = "EASY";
	cm["https://codeforces.com/contest/2085/problem/C"] = "MEDIUM";
	cm["https://codeforces.com/contest/2085/problem/D"] = "HARD";
	cm["https://codeforces.com/contest/2091/problem/F"] = "HARD";
	cm["https://oj.vnoi.info/problem/bedao_r03_kindness"] = "EASY";
	cm["https://oj.vnoi.info/problem/bedao_r05_carray"] = "MEDIUM";
	cm["https://oj.vnoi.info/problem/bedao_r05_factory"] = "HARD";
	cm["https://oj.vnoi.info/problem/bedao_r04_marble"] = "HARD";
	cm["https://laptrinhonline.club/problem/tichpxllshiper"] = "HARD";
	cm["https://oj.vnoi.info/problem/bedao_r13_xorqry"] = "HARD";
	cm["https://oj.vnoi.info/problem/bedao_r14_sumxor"] = "MEDIUM";
	cm["https://oj.vnoi.info/problem/bedao_r14_bracket"] = "HARD";
	// OUTPUT
	for (auto x : s) {
		cout << i << " --> " << x << "               " << cm[x] << endl;
		i++; 
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen((NoF + ".txt").c_str(),"w",stdout);
	solve();
}
