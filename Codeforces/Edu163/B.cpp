#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; case_num++) {
		int curr = 0;
		int N;
		cin >> N;
		bool good = true;
		for (int i = 0; i < N; i++) {
			int a;
			cin	>> a;
			if (a > 9) {
				int front = a/10;
				int next = a%10;
				if (a < curr) {
					good = false;
				} else if (a >= curr){
					if (front > next) {
						//keep as is
						curr = a;
					} else {
						if (front >= curr) {
							curr = next;
						}
					}
				}
			} else {
				if (a < curr) {
					good = false;
				}
				curr = a;
			}
		}
		if (good) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}		
