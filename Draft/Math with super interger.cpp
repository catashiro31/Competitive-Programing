#include <iostream>
#include <string>
using namespace std;
int Length(string x) {
	int count = 0;
	while (x[count] != '\0') {
		count++;
	}
	return count;
}
string Cong(string a, string b) {
	while (Length(a) > Length(b)) {
		b = '0'+b;
	}
	while (Length(a) < Length(b)) {
		a = '0'+a;
	}
	string c = a;
	int dem,plus = 0;
	for (int i = Length(a)-1; i >= 0; i--) {
		dem = (int(a[i]) + int(b[i]) - 96 + plus)%10;
		plus = int((int(a[i])+ int(b[i]) - 96 + plus)/10);
		c[i] = char(dem + 48);
	}
	if (plus != 0) {
		c = '1'+c;
	}
	return c;
}
int So_sanh(string a, string b) {
	if (Length(a) > Length(b)) {
		return 1;
	}
	if (Length(a) < Length(b)) {
		return -1;
	}
	for (int i = 0; i < Length(a); i++) {
		if (int(a[i]) > int(b[i])) {
			return 1;
		}
		if (int(a[i]) < int(b[i])) {
			return -1;
		}
	}
	return 0;
}
string Hieu(string a, string b) {
	while (Length(a) > Length(b)) {
		b = '0'+b;
	}
	while (Length(a) < Length(b)) {
		a = '0'+a;
	}
	if (So_sanh(a,b) == 0) {
		return "0";
	}
	string c = a;
	int dem, plus = 0;
	if (So_sanh(a,b) == 1) {
		for (int i = Length(a)-1; i >= 0; i--) {
			if (int(a[i]) + plus < int(b[i])) {
				c[i] = char(int(a[i]) - int(b[i]) + plus + 10 + 48);
				plus = -1;
			}
			else {
				c[i] = char(int(a[i] - int(b[i]) + plus + 48));
				plus = 0;
			}
		}
		int z = 0;
		while (c[z] == '0') {
			c.erase(z,1);
		}	
		return c;
	}
	if (So_sanh(a,b) == -1) {
		for (int i = Length(a)-1; i >= 0; i--) {
			if (int(b[i]) + plus < int(a[i])) {
				c[i] = char(int(b[i]) - int(a[i]) + plus + 10 + 48);
				plus = -1;
			}
			else {
				c[i] = char(int(b[i] - int(a[i]) + plus + 48));
				plus = 0;
			}
		}
		return "-"+c;
	}
}
string Tich(string a, string b) {
	string c="0";
	string dem;
	for (int i = Length(b)-1; i >= 0; i--) {
		if (int(b[i]) != 48) {
			for (int j = 0; j < int(b[i])-48; j++) {
				dem = Cong(dem,a);
			}
		}
		for (int k = 0; k < Length(b)-1-i; k++) {
			dem = dem +'0';
		}
		c = Cong(dem,c);
		dem = "0";
	} 
	return c;
}
int main() {
	string so1,so2;
	cout << Hieu("130","45");
} 