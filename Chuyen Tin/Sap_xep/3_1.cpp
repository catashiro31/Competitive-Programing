#include <iostream> 
#include <string>
using namespace std;
string Xu_li(string hoten) {
	string ten = "";
	int i = hoten.length()-1;
	while (hoten[i] != ' ') {
		ten = hoten[i] + ten;
		i--;
	}
	string xau = ten + hoten;
	return xau;
}
int Compare(string xau1, string xau2) {
	int count = 0;
	while (0 == 0) {
		if (xau1[count] == '\0' and xau2[count] != '\0') return -1;
		if (xau1[count] != '\0' and xau2[count] == '\0') return 1;
		if (xau1[count] == '\0' and xau2[count] == '\0') return 0;
		if (int(xau1[count]) < int(xau2[count])) return -1;
		if (int(xau1[count]) > int(xau2[count])) return 1;
		count++;
	}
}
void A(string hoten[], int size, float diem[]) {
	string tmp1;
	float tmp2;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-i-1; j++) {
			if (Compare(Xu_li(hoten[j]),Xu_li(hoten[j+1])) == 1) {
				tmp1 = hoten[j];
				hoten[j] = hoten[j+1];
				hoten[j+1] = tmp1;
				tmp2 = diem[j];
				diem[j] = diem[j+1];
				diem[j+1] = tmp2;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << hoten[i] << endl;
	}
}
string Name(string hoten) {
	string ten = "";
	int i = hoten.length()-1;
	while (hoten[i] != ' ') {
		ten = hoten[i] + ten;
		i--;
	}
	return ten;
}
void B(string hoten[], int size) {
	int count = 0;
	string kq = "";
	for (int i = 0; i < size-1; i++) {
		if (Name(hoten[i]) != Name(hoten[i+1])) {
			count++;
			kq = kq + "\n" + Name(hoten[i]);
			if (i == size-2) {
				kq = kq + "\n" + Name(hoten[i+1]);
				count++;
			}
		}
	}
	cout << endl;
	cout << count << kq;
}
void C(float diem[], int size, string hoten[]) {
	float top[3] = {0,0,0};
	for (int i = 0; i < size; i++) {
		if (diem[i] > top[0]) {
			top[0] = diem[i];
		}
	}
	for (int i = 0; i < size; i++) {
		if (diem[i] > top[1] and diem[i] != top[0]) {
			top[1] = diem[i];
		}
	}
	for (int i = 0; i < size; i++) {
		if (diem[i] > top[2] and diem[i] != top[0] and diem[i] != top[1]) {
			top[2] = diem[i];
		}
	}
	cout << endl << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < size; j++) {
			if (diem[j] == top[i]) {
				cout << hoten[j] << endl;
			}
		}
	}	
}
int main() {
	int n;
	cin >> n;
	cin.ignore();
	string hoten[n] = {};
	float diem[n] = {};
	for (int i = 0; i < n; i++) {
		getline(cin,hoten[i]);
		cin.ignore();
		cin >> diem[i];
		cin.ignore();
	}
	A(hoten,n,diem);
	B(hoten,n);
	C(diem,n,hoten);
}