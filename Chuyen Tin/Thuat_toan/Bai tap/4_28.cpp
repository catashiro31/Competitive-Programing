#include <bits/stdc++.h>
using namespace std;
string Cong(string a, string b) {
	while (a.length() < b.length()) a = '0'+a;
	while (a.length() > b.length()) b = '0'+b;
	string kq =  "";
	int res = 0;
	int tmp;
	for (int i = a.length()-1; i >= 0; i--) {
		tmp = a[i] + b[i] + res - 96;
		kq = to_string(tmp%10) + kq;
		if (tmp >= 10) res = 1;
		else res = 0;
	}
	if (res == 1) kq = "1" + kq;
	return kq;
}
string Hieu(string a, string b) {
	while (b.length() < a.length()) b = '0'+b;
	int res = 0;
	int tmp;
	string kq = "";
	for (int i = a.length()-1; i >= 0; i--) {
		tmp = a[i]-b[i]+res;
		if (tmp < 0) {
			res = -1;
			kq = to_string(tmp+10) +kq;
		} else {
			res = 0;
			kq = to_string(tmp) + kq;
		}
	}
	while (kq[0] == '0' and kq.size() > 1) kq.erase(0,1);
	return kq;
}
int Sosanh(string a, string b) {
	if (a.length() < b.length()) return -1;
	else if (a.length() > b.length()) return 1;
	for(int i = 0; i < a.length(); i++) {
		if (a[i] < b[i]) return -1;
		else if (a[i] > b[i]) return 1;
	}
	return 0;
}
int main() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	string N;
	inFile >> N;
    inFile.close();
    string tmp1 = "1";
    string tmp2 = "1";
    string tmp = "1";
	vector<string> arr;
    while (Sosanh(tmp,N) == -1) {
    	arr.push_back(tmp);
    	tmp = Cong(tmp1,tmp2);
    	tmp1 = tmp2;
    	tmp2 = tmp;
	}
	int i = arr.size()-1;
	while (Sosanh(N,"0") > 0) {
		if (Sosanh(N,arr[i]) >= 0) {
			cout << arr[i] << " ";
			N = Hieu(N,arr[i]);
		} else i--;
	}
}
