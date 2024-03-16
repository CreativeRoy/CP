#include <iostream>
using namespace std;

int main() {
	//first create seive
	int MAX = 5000000;
	bool prime[MAX+1];
	for (int i = 1; i <= MAX; i++) prime[i] = true;
	for (int i = 2; i <= MAX; i++) {
		if (!prime) continue; 
		for (int k = i+i; k <= MAX; k+=i) {
			prime[k] = false;
		}
	}
	int turns[MAX+1];
	turns[0] = 0;
	turns[1] = 1;
	turns[2] = 1;
	turns[3] = 1;
	turns[4] = 1;
	int prev1 = 1;
	int prev2 = 2;
	int prev3 = 3;
	for (int i = 5; i <= MAX; i++) {
		if (i % 4 == 1) {
			if (prime[i]) prev1 = i;
			turns[i] = 1+turns[i-prev1];
		} else if (i % 4 == 2) {
			turns[i] = 1+turns[i-prev2];
		} else if (i % 4 == 3) {
			if (prime[i]) prev3 = i;			
			turns[i] = 1+turns[i-prev3];
		} else {
			turns[i] = i/4;
		}		
	}
	
	for (int i = 1; i <= MAX; i++) {
		if (i%4 == 0) turns[i]++; 					
	}

	int t; cin >> t;
	int minW = 50000000; int iW = -1;
	int minL = 50000000; int iL = -1;
	while (t--) {
		minW = 50000000;
		minL = 50000000;
		iW = -1;
		iL = -1;
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int temp; cin >> temp;
			if (temp % 4 == 0) {
				if (turns[temp] < minL) {
					iL = i;
					minL = turns[temp];
				}
			} else {
				if (turns[temp] < minW) {
					iW = i;
					minW = turns[temp];
				}
			}
		}
		if (minW < minL) {
			cout << "Farmer John" << endl;
		} else if (minW > minL) {
			cout << "Farmer Nhoj" << endl;
		} else {
			if (iL > iW) {
				cout << "Farmer John"<< endl;
			} else {
				cout << "Farmer Nhoj"<< endl;
			}
		}
	}
	return 0;
}

