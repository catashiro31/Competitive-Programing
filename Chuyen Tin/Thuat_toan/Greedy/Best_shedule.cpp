#include <bits/stdc++.h>

using namespace std;

int n;
pair<pair<int,int>, int> a[100000];
priority_queue<pair<int,int> > q;
bool mark[100000];

int main() {
    cin >> n; // Nhập n
    for(int i=0;i<n;++i) cin >> a[i].first.second; // Nhập p
    for(int i=0;i<n;++i) cin >> a[i].first.first; // Nhập d
    for(int i=0;i<n;++i) a[i].second = i+1; // Lưu trữ thứ tự
    sort(a, a+n); // Sắp xếp theo thứ tự từ d -> p
    memset( mark, true, sizeof(mark));
    int total = 0;
    for(int i=0;i<n;++i) {
        total += a[i].first.second;
        q.push( make_pair( a[i].first.second, i));
        if(total>a[i].first.first) {
            pair<int,int> p = q.top(); q.pop();
            total -= p.first;
            mark[p.second] = false;
        }
    }
    int dem = 0;
    for(int i=0;i<n;++i) if(!mark[i]) ++dem;
    cout << endl << dem << endl;
    for(int i=0;i<n;++i) if(mark[i]) cout << a[i].second << " ";
    for(int i=0;i<n;++i) if(!mark[i]) cout << a[i].second << " ";
    return 0;   
}