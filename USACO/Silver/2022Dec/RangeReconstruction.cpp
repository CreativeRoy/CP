#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> r;
vector<int> MAX, MIN, arr, diff;

void update_max(int n) {
	int m = -1000000000; 
	for (int i = n; i >= 0; i--) {
		m = max(m, arr[i]);
		MAX[i] = m;
	}
}

void update_min(int n) {
	int m = 1000000000; 
//	cout << "mins ";
	for (int i = n; i >= 0; i--) {
		m = min(m, arr[i]);
		//cout << m << " ";
		MIN[i] = m;
	}
	//cout << endl;
}


int main() {
	cin >> N;
	r.resize(N);
	for (int i = 0; i < N; i++) {
		r[i].resize(N-i);
		for (int &t : r[i]) cin >> t;
	}
	MAX.resize(N), MIN.resize(N), arr.resize(N), diff.resize(N);
	arr[0] = 0;
	for (int i = 1; i < N; i++) { 
		diff[i] = r[i-1][1];
	}
	int sub = 0;
	cout << arr[0] << " ";
	for (int i = 1; i < N; i++) {
		arr[i] += diff[i] + arr[i-1];
		update_max(i);
		update_min(i);
		bool right = true;
		for (int j = 1; j <= i; j++) {
			//cout << "I : " << i << " J: " << j << endl;
		//	cout << "i , j " << i << " " << j << " ";
			//cout << "max min: " << MAX[i] << " " << MIN[i] << "\n";
			int range = MAX[i-j] - MIN[i-j];
			//cout << "RANGE: " << range << " R: " << r[i-j][j] << "\n";
			//cout << "range: " << range << " r: " << r[i-j][j] << " \n";
			if (range != r[i-j][j]) {
				right = false;
				break;
			}	
		}	
		if (!right) {
			arr[i] -= 2*diff[i];
			update_max(i);
			update_min(i);	
		}
		if (i < N-1) { 
			cout << arr[i] << " ";
		} else {
			cout << arr[i];
		}
	}
}	


