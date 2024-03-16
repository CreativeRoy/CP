#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N; cin >> N;
	int A[N+1];

	vector<char> ans; 
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		A[i] = temp;
	}
	A[N] = 0;
	int ind = 0;
	while (!(A[ind] == 0 && ind == 0)) {
		while (A[ind] > 0) {
			//cout << "R";
			ans.push_back('R');
			A[ind] -= 1;
			ind++;
		}
		while (ind > 0 && (A[ind-1] > 1 || A[ind] == 0)) {
			//cout << "L";
			ans.push_back('L');
			ind--;
			A[ind] -= 1;
		}
	}
	for (char c : ans) cout << c;
	cout << endl;
}
