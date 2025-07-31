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
void insertion_sort(int arr[], int n) {
	fo(i,1,n-1) {
		int j = i-1;
		int key = arr[i];
		while (j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key; 
	}
}
void selection_sort(int arr[], int n) {
	rep(i,n-1) {
		fo(j,i,n-1) if (arr[j] < arr[i]) swap(arr[j],arr[i]);
	}
}
void bubble_sort(int arr[], int n) {
	rep(i,n-1) rep(j,n-i-1) {
		if (arr[j] > arr[j+1]) swap(arr[j],arr[j+1]);
	} 
}
void output(int arr[], int n) {
	rep(i,n) cout << arr[i] << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt","r",stdin);
	int n; cin >> n;
	int arr[n];
	for (int &x : arr) cin >> x;
//	insertion_sort(arr,n);
//	selection_sort(arr,n);
	bubble_sort(arr,n);
	output(arr,n);
}
