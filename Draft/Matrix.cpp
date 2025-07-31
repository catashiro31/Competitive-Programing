#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

struct Matrix {
    int r, c;
    vector<vector<int>> d;
    // 
    Matrix(int rows, int cols) : r(rows), c(cols), d(rows, vector<int>(cols, 0)) {}
    //
    friend Matrix operator*(Matrix a, Matrix b) {      
        Matrix kq(a.r, b.c);
        for (int i = 0; i < a.r; ++i) {
            for (int j = 0; j < b.c; ++j) {
                for (int k = 0; k < a.c; ++k) {
                    kq.d[i][j] += a.d[i][k] * b.d[k][j];
                }
            }
        }
        return kq;
    }
	//
	static Matrix identity(long long n) {
		Matrix dv(n,n);
		while (n--) dv.d[n][n] = 1;
		return dv;
	}
	//
	Matrix Pow(long long exp) {
		Matrix base = *this;
		Matrix ans = identity(r);
		while (exp) {
			if (exp & 1) ans = ans * base; 
			base = base * base;
			exp >>= 1;
		}
		return ans;
	}
    //
    void print() const {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "Ma tran A" << endl;
    int A_r, A_c;
    cout << "Nhap so hang, so cot A: "; cin >> A_r >> A_c;
	Matrix A(A_r,A_c);
	cout << "Nhap du lieu: " << endl;
	for (int i = 0; i < A_r; i++) {
		for (int j = 0; j < A_c; j++) cin >> A.d[i][j];
	}

    cout << "Ma tran B" << endl;
	int B_r, B_c;
	cout << "Nhap so hang, so cot B: "; cin >> B_r >> B_c;
	Matrix B(B_r,B_c);
	cout << "Nhap du lieu: " << endl;
	for (int i = 0 ;i  < B_r; i++) {
		for (int j = 0; j < B_c; j++) cin >> B.d[i][j];
	}

    // Nhân ma trận A và B
    Matrix C = A * B;
    cout << "Matrix A * Matrix B:\n";
    C.print();
	
	Matrix D = A.Pow(3);
	cout << "Matrix A pow 3:\n";
	D.print();
    return 0;
}
