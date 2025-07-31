#include<iostream>
using namespace std;
int n = 4;
int kq = 0;
int arr[9] = {};
bool Cheo_Xuoi[16];
bool Cheo_Nguoc[16];
bool Cot[9];
void shown() {
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void Xep_Hau(int i) {
    if (i == n+1) {
    	kq++;
        shown();
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (Cot[j] == true and Cheo_Xuoi[i-j+n] == true and Cheo_Nguoc[i+j-1] == true) {
        	arr[i] = j;
        	Cot[j] = false;
        	Cheo_Xuoi[i-j+n] = false;
        	Cheo_Nguoc[i+j-1] = false;
        	Xep_Hau(i+1);
        	Cot[j] = true;
        	Cheo_Xuoi[i-j+n] = true;
        	Cheo_Nguoc[i+j-1] = true;
		}
    }
}
int main() {  
	for (int i = 1; i <= 2*n-1; i++) {
		Cheo_Xuoi[i] = true;
		Cheo_Nguoc[i] = true;
	}
	for (int i = 1; i <= n; i++) {
		Cot[i] = true;
	}
    Xep_Hau(1);
    cout << kq;
}
