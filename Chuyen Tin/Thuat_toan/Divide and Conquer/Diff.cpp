#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100000;
vector<int> a(MAXN);  
int n;                
int maxDiff;         
void find2(int l, int r, int &maxDiff, int &maxValue, int &minValue) {
    if (l == r) {
        maxDiff = 0;
        maxValue = a[r]; 
        minValue = a[r];
    } else {
        int mid = (l + r) / 2;
        int maxD1, maxV1, minV1;
        int maxD2, maxV2, minV2;
        find2(l, mid, maxD1, maxV1, minV1);
        find2(mid + 1, r, maxD2, maxV2, minV2);
        maxDiff = maxV2 - minV1;
        if (maxDiff < maxD1) maxDiff = maxD1;
        if (maxDiff < maxD2) maxDiff = maxD2;
        maxValue = max(maxV1, maxV2);
        minValue = min(minV1, minV2);
    }
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
    int tmp1, tmp2;
    find2(1, n, maxDiff, tmp1, tmp2);
    cout << maxDiff << endl;
    return 0;
}
