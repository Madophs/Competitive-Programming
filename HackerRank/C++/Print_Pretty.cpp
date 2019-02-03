#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
                cout << hex << nouppercase <<showbase << left << ((long long)(A)) << endl;
                cout << setw(0xf) << fixed << setprecision(2) << showpos << setfill('_') << right << B << endl;
                cout << setw(0xf) << fixed << setprecision(9) << scientific << noshowpos << uppercase << C << endl;
	}
	return 0;

}