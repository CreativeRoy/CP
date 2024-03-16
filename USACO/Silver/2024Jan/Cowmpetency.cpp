#include <iostream>
#include <unordered_map>

using namespace std;

//first assume that all cases are possible
int main() {
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; case_num++) {
		unordered_map<int, int> pairs;
		int N, Q, C;
		cin >> N >> Q >> C;
		//original list
		int cows[N];
		//new list  
		int ans[N] = {0};
		//greater eq 0 ==> 0.5, N-1 ==> N-0.5
		int p_diff[N-1] = {0};
		for (int i = 0; i < N; i++) {
			cin >> cows[i];
		}
		for (int i = 0; i < Q; i++) {
			int a, h;
			cin >> a >> h;
			a--,h--;
			if (pairs.find(h) == pairs.end()) {
				pairs[h] = a;
			} else {
				pairs[h] = min(pairs[h], a);
			}
		}	
		bool imp = false;
		for (auto p : pairs) {
			//cout << p.second << " " << p.first << endl;
			for (int i = p.second; i < p.first-1; i++) {
				if (p_diff[i] == 2) {
					imp = true;
				}
				p_diff[i] = 1;
			}
			if (p_diff[p.first-1] == 1) {
				imp = true;
			}
			p_diff[p.first-1] = 2;
		}
		if (imp) {
			cout << -1 << endl;
			continue;
		}
		//bool imp = false;
		//traverse
		int prefix_max = 1;
		int prev = -1;
		for (int i = 0; i < N; i++) {
			int cow = cows[i];
			if (cow != 0) ans[i] = cow; 
			if (i == 0 || p_diff[i-1] == 0) {
				//okay to change p_max
				if (cow == 0) {
					prev = i;
				}
			} else if (p_diff[i-1] == 1) {
				//not okay to change p_max
				if (prefix_max < cow) {
					if (prev == -1) {
						//we're fucked
						imp = true;
						break;
					} else {
						ans[prev] = cow;
						prefix_max = cow;
					}
				}	
			} else if (p_diff[i-1] == 2) {
				//should be greater than p_max
				if (cow == 0) {
					prefix_max++;
					ans[i] = prefix_max;
					prev = i;
				} else {
					if (cow <= prefix_max) {
						//we're fucked
						imp = true;
						break;
					}
				}
			} 
			prefix_max = max(prefix_max, cow);
		}
		if (prefix_max > C) {
			imp = true;
		}
		for (int &cow : ans) {
			if (cow == 0) {
				cow = 1;
			}
		}

		int p_max = ans[0];
		for (int i = 0; i < N-1; i++) {
			p_max = max(p_max, ans[i]);
			if (p_diff[i] == 0) {
				continue;
			} else if (p_diff[i] == 1) {
				if (p_max < ans[i+1]) {
					imp = true;
					break;
				}
			} else if (p_diff[i] == 2) {
				if (p_max >= ans[i+1]) {
					imp = true;
					break;
				}
			}
		}
		if (imp) {
			cout << -1 << endl;
		} else {
			/*
			for (int i = 0; i < N-1; i++) {
				cout << cows[i] << " "; 
				if (p_diff[i] == 0) {
					cout << ". ";
				} else if (p_diff[i] == 1) {
					cout << "= ";
				} else if (p_diff[i] == 2) {
					cout << "< ";
				}
			}
			cout << cows[N-1] << endl;
			*/
			for (int i = 0; i < N-1; i++) {
				cout << ans[i] << " ";
			}
			cout << ans[N-1] << endl;
		}
	}
}
