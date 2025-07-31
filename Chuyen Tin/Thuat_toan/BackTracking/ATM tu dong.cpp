#include<iostream>
using namespace std;
int n, S;
bool supercheck = false;
long int dem = 0;
void shown(int *kq, int size) {
	supercheck = true;
	for (int i = 0; i < size; i++) {
		cout << kq[i] << " ";
	}
	cout << endl;
}
void BackTracking(int i, int sum, int *kq, int t[], bool check[]) {
	dem++;
	if (supercheck == true) {
		return;
	}
	if (sum == S) {
		supercheck = true;
		shown(kq,i);
		return;
	}
	if (sum > S) {
		return;
	}
	for (int j = 0; j < n; j++) {
		if (check[j] == true and kq[i-1] <= t[j]) {
			kq[i] = t[j];
			check[j] = false;
			BackTracking(i+1,sum+t[j],kq,t,check);
			check[j] = true; 
		}
	}
}
int main() {  
	cin >> n >> S;
	int t[n];
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	bool check[n];
	for (int i = 0; i < n; i++) {
		check[i] = true;
	}
	int *kq = new int;	
	BackTracking(0,0,kq,t,check);
	if (supercheck == false) {
		cout << "-1";
	}
	cout << endl << dem;
}
