#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; case_num++) {
		int N;
		cin >> N;
		if (N % 2 == 0) {
			cout << "YES" << endl;
			
			for (int i = 0; i < N/2; i++) {
				if (i % 3 == 0) {
					cout << "AA";
				} else if(i % 3 == 1) {
					cout << "BB";
				} else if(i % 3 == 2) {
					cout << "CC";
				}
			}
			cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
