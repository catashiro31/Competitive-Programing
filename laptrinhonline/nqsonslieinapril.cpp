//#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#define endl '\n'
//using namespace __gnu_pbds;
//using namespace std;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//	int n, m; cin >> n >> m;
//	long a[n];
//	for (long &x : a) cin >> x;
//	pair<int,pair<long,long>> low[m];
//	pair<int,pair<long,long>> high[m];
//	int x[m], y[m];
//	long l[m], r[m];
//	for (int i = 0; i < m; i++) {
//		cin >> x[i] >> y[i] >> l[i] >> r[i];
//		low[i].first = x[i]; low[i].second.first = l[i]; low[i].second.second = r[i];
//		high[i].first = y[i]; high[i].second.first = l[i]; high[i].second.second = r[i];
//	}
//	sort(low,low+m);
//	sort(high,high+m);
//	order_set os;
//	int rl = 0, rh = 0;
//	map<pair<int,long>,int> sl;
//	while (low[rl].first < 2) {
//		sl[{low[rl].first,low[rl].second.first}] = 0;
//		sl[{low[rl].first,low[rl].second.second}] = 0;
//		rl++;
//	}
//	for (int i = 0; i < n; i++) {
//		os.insert(a[i]);
//		while (low[rl].first-2 == i) {
//			sl[{low[rl].first,low[rl].second.first}] = os.order_of_key(low[rl].second.first);
//			sl[{low[rl].first,low[rl].second.second}] = os.order_of_key(low[rl].second.second+1);
//			rl++;
//		}
//		while (high[rh].first-1 == i) {
//			sl[{high[rh].first,high[rh].second.first}] = os.order_of_key(high[rh].second.first);
//			sl[{high[rh].first,high[rh].second.second}] = os.order_of_key(high[rh].second.second+1);
//			rh++;
//		}
//	}
//	for (int i = 0; i < m; i++) {
//		cout << (sl[{y[i],r[i]}]-sl[{x[i],r[i]}]) - (sl[{y[i],l[i]}]-sl[{x[i],l[i]}]) << endl;
//	}
//	return 0;
//}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; 
    cin >> n >> m;
    vector<long> a(n);
    for (long &x : a) cin >> x;

    vector<pair<int, pair<long, long>>> low(m), high(m);
    vector<int> x(m), y(m);
    vector<long> l(m), r(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i] >> l[i] >> r[i];
        low[i] = {x[i], {l[i], r[i]}};
        high[i] = {y[i], {l[i], r[i]}};
    }

    sort(low.begin(), low.end());
    sort(high.begin(), high.end());

    order_set os;
    int rl = 0, rh = 0;
    map<pair<int, long>, int> sl;

    while (rl < m && low[rl].first < 2) {
        sl[{low[rl].first, low[rl].second.first}] = 0;
        sl[{low[rl].first, low[rl].second.second}] = 0;
        rl++;
    }

    for (int i = 0; i < n; i++) {
        os.insert(a[i]);

        while (rl < m && low[rl].first - 2 == i) {
            sl[{low[rl].first, low[rl].second.first}] = os.order_of_key(low[rl].second.first);
            sl[{low[rl].first, low[rl].second.second}] = os.order_of_key(low[rl].second.second + 1);
            rl++;
        }

        while (rh < m && high[rh].first - 1 == i) {
            sl[{high[rh].first, high[rh].second.first}] = os.order_of_key(high[rh].second.first);
            sl[{high[rh].first, high[rh].second.second}] = os.order_of_key(high[rh].second.second + 1);
            rh++;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << (sl[{y[i], r[i]}] - sl[{x[i], r[i]}]) - (sl[{y[i], l[i]}] - sl[{x[i], l[i]}]) << endl;
    }

    return 0;
}
