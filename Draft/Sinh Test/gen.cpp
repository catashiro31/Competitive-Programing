#include <bits/stdc++.h>
using namespace std;

const string NAME = "task";
const int NTEST = 100;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

long long rand(long long L, long long R) {
    assert(L <= R);
    uniform_int_distribution<long long> dist(L, R);
    return dist(rd);
}

//#ifdef _WIN32
const string SOL = NAME + ".exe";
const string TRAU = NAME + "_trau.exe";
const string CMP = "fc " + NAME + ".out " + NAME + ".ans";
//#else
//    const string SOL = "./" + NAME;
//    const string TRAU = "./" + NAME + "_trau";
//    const string CMP = "diff -w " + NAME + ".out " + NAME + ".ans";
//#endif

int main()
{
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
		
		int n = rand(1,50), k = rand(1,50), r = rand(1,n), p = rand(1,5);
		inp << n << " " << k << " " << r << " " << p << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int val = rand(1,1000000);
				inp << val << " ";
			}
			inp << "\n";
		}
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < p; j++) {
				int x = rand(1,n-r+1), y = rand(1,n-r+1);
				inp << x << " " << y << " ";
			}
			inp << "\n";
		}
		
        inp.close();
        system(SOL.c_str());
        system(TRAU.c_str());
        if (system(CMP.c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }

        cout << "Test " << iTest << ": CORRECT!\n";
    }

    cout << "All tests passed!\n";
    return 0;
}
