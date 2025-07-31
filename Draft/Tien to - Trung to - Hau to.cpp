// Tien to -> Trung to
//#include <bits/stdc++.h>
//using namespace std;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	string xau; cin >> xau;
//	stack<string> st;
//	for (int i = xau.length()-1; i >= 0; i--) {
//		if (isdigit(xau[i]) || isalpha(xau[i])) st.push(string(1,xau[i]));
//		else {
//			string tmp1 = st.top(); st.pop();
//			string tmp2 = st.top(); st.pop();
//			st.push("("+tmp1+xau[i]+tmp2+")");
//		}
//	}
//	cout << st.top();
//}
// Tien to -> Hau to
//#include <bits/stdc++.h>
//using namespace std;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	string xau; cin >> xau;
//	stack<string> st;
//	for (int i = xau.length()-1; i >= 0; i--) {
//		if (isdigit(xau[i]) || isalpha(xau[i])) st.push(string(1,xau[i]));
//		else {
//			string tmp1 = st.top(); st.pop();
//			string tmp2 = st.top(); st.pop();
//			st.push(tmp1+tmp2+xau[i]);
//		}
//	}
//	cout << st.top();
//}
// Trung to -> Hau to
//#include <bits/stdc++.h>
//using namespace std;
//int priority(char a, char b) {
//	if (a == '(') return -2;
//	if ((b == '+' || b == '-') && (a == '*' || a == '/')) return -1;
//	if ((b == '*' || b == '/') && (b == '+' || b == '-')) return 1;
//	return 0;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	string xau; cin >> xau;
//	stack<char> st;
//	string kq = "";
//	for (int i = 0; i < xau.length(); i++) {
//		if (xau[i] == '(') st.push(xau[i]);
//		else if (xau[i] == ')') {
//			while (st.top() != '(') {
//				kq += string(1,st.top());
//				st.pop();
//			}
//			st.pop();
//		} else if (isdigit(xau[i]) || isalpha(xau[i])) kq+=string(1,xau[i]);
//		else {
//			while (!st.empty() && priority(st.top(),xau[i]) >= 0) {
//				kq += string(1,st.top());
//				st.pop();
//			}
//			st.push(xau[i]);
//		}
//	}
//	while (!st.empty()) {
//		kq += string(1,st.top());
//		st.pop();
//	}
//	cout << kq;
//}
// Tinh toan hau to
//#include <bits/stdc++.h>
//using namespace std;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	string xau; cin >> xau;
//	stack<int> st;
//	for (int i = 0; i < xau.length(); i++) {
//		if (isdigit(xau[i])) st.push(xau[i]-'0');
//		else {
//			int tmp1 = st.top(); st.pop();
//			int tmp2 = st.top(); st.pop();
//			if (xau[i] == '-') st.push(tmp2-tmp1);
//			else if (xau[i] == '+') st.push(tmp1+tmp2);
//			else if (xau[i] == '*') st.push(tmp1*tmp2);
//			else if (xau[i] == '/') st.push(tmp2/tmp1);
//		}
//	}
//	cout << st.top();
//}
// Tinh toan tien to
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string xau; cin >> xau;
	stack<int> st;
	for (int i = xau.length()-1; i >= 0; i--) {
		if (isdigit(xau[i])) st.push(xau[i]-'0');
		else {
			int tmp1 = st.top(); st.pop();
			int tmp2 = st.top(); st.pop();
			if (xau[i] == '+') st.push(tmp1+tmp2);
			else if (xau[i] == '-') st.push(tmp1-tmp2);
			else if (xau[i] == '*') st.push(tmp1*tmp2);
			else if (xau[i] == '/') st.push(tmp1/tmp2);
		}
	}
	cout << st.top();
}