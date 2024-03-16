#include <iostream>
#include <map>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; case_num++) {
		int N,M,K;
		cin >> N >> M >> K;
		int E[M], O[M];
		for (int i = 0; i < M; i++) {
			int max_e = 0, min_e = 1e3 + 1, max_o = 0, min_o = 1e3 + 1;
			for (int j = 0; j < K; j++) {
				int a;
				cin >> a;
				if (a % 2 == 0) {
					min_e = min(a, min_e);	
					max_e = max(a, max_e);
				} else {
					min_o = min(a, min_o);
					max_o = max(a, max_o);
				}
			}
			if (min_e == 1e3+1) {
				//all odds
				max_e = -1*min_o;
			}
			if (min_o == 1e3+1) {
				//all evens
				max_o = -1*min_e;
			}
			E[i] = -1*max_o;
			O[i] = -1*max_e;
		}
		/*
		for (int e : E) {
			cout << e << " ";
		}
		cout << endl;
		for (int o : O) {
			cout << o << " ";
		}
		cout << endl;
		*/
		bool par[M];//true even false odd
		int mins[M] = {};
		int p_mins[M+1] = {};
		map<int, int> map; 
		bool works = true;
		for (int i = 1; i <= M; i++) {
			if (E[i-1] >= O[i-1]) {
				mins[i-1] = E[i-1];
				par[i-1] = true;
				p_mins[i] = E[i-1] + p_mins[i-1];
			} else {
				mins[i-1] = O[i-1];
				par[i-1] = false;
				p_mins[i] = O[i-1] + p_mins[i-1];
			}
			if (map.find(p_mins[i]) != map.end()) {
				map[p_mins[i]]++;
			} else {
				map[p_mins[i]] = 1;
			}
		}	
		for (int p : p_mins) {
			if (p+N <= 0) {
				cout << -1 << endl;
				works = false;
				break;
			}	
		}
		if (!works) {
			continue;
		}
		int offset = 0;
		for (int i = 0; i < M; i++) {
			if (par[i]) {
				//do nothing, we're even already
				cout << "Even";
			} else {
				//we're odd
				int bot = map.begin()->first;
				int test = offset - O[i] + E[i];
				if (test+bot+N > 0) {
					offset = test;
					cout << "Even";
				} else {
					cout << "Odd";
				}
			}
			if (i != M-1) {
				cout << " ";
			}
			if (map[p_mins[i+1]] == 1) {
				map.erase(p_mins[i+1]);
			} else {
				map[p_mins[i+1]]--;
			}
		}
		cout << endl;
	}
}
