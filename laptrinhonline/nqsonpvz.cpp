#include <bits/stdc++.h>
#define endl '\n'
#define mod 10000000007
using namespace std;
int n, m, x;
bool Plant_win(vector<long> a, long nub) {
    priority_queue<long, vector<long>, greater<int>> pq;
    vector<long> play(n, 0);
    deque<long> d;
    long minus = nub;
    int k = 1;
    pq.push(a[0]);
    play[n - 1] = max(0L, a[0] - nub);
    while (!pq.empty()) {
        int tmp = 0;
        for (int i = 1; i < n; i++) {
            if (play[i]) tmp++;
            if (tmp <= x) 
                play[i - 1] = max(0L, play[i] - nub);
            else 
                play[i - 1] = play[i];
        }
        if (play[0] != 0) return false;
        if (k < m) {
            d.push_back(a[k]);
            if (tmp < x) 
                play[n - 1] = max(0L, a[k] - nub);
            else 
                play[n - 1] = a[k];
            k++;
        } else {
            play[n - 1] = 0;
        }
        while (!pq.empty() && pq.top() < minus) pq.pop();
        while (!d.empty() && pq.size() < x) {
            pq.push(d.front() + minus);
            d.pop_front();
        }
        minus += nub;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);   
    cin >> n >> m >> x;
    vector<long> a(m);
    for (long &vl : a) cin >> vl;
    long i = 0, j = *max_element(a.begin(), a.end());
    long result = j;
    while (i < j) {
        long mid = (i + j) / 2;
        if (Plant_win(a, mid)) {
            result = mid;
            j = mid;
        } else {
            i = mid + 1;
        }
    }
    cout << result;
    return 0;
}