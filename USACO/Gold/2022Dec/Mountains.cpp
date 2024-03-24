#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll h[2001];

bool compare(int ind, int a, int b) {
	//if the slope to b is greater than the slope to a
	return ((h[ind]- h[a])*(ind - b) <= (h[ind]-h[b])*(ind-a)); 
}

int main() {
	int N, Q;
	cin >> N;
	set<int> sets[N]; 
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}
	cin >> Q;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (sets[i].empty()) {
				sets[i].insert(j);
				ans++;
			} else {
				if (compare(i, *sets[i].rbegin(), j)) {
					sets[i].insert(j);
					ans++;
				}
			}
		}
	}
	//cout << ans << endl;
	for (int i = 0; i < Q; i++) {
		int x;
		ll y;
		cin >> x >> y;
		x--;
		h[x] += y;
		// first check for all < x
		for (int j = 0; j < x; j++) {
			auto it = sets[j].lower_bound(x);   
			bool add = false;
			if (*it == x) {
				//x exists	
				//the slope of x can only get greater
				it++;
				add = true;
			} else {
				//see if we can insert x
				it--;
				if (compare(j, *it, x)) {
					ans++;
					sets[j].insert(x);
					it++;
					it++;
					add = true;
				}
			}
			if (add) {
				while (it != sets[j].end() && !compare(j, x, *it)) {
					//cout << "deleting: " << j << "," << *it << endl; 
					it = sets[j].erase(it);
					ans--;
				}
			}
		}
		//check for all after x
		ans -= (int)sets[x].size();
		sets[x].clear();
		for (int j = x+1; j < N; j++) {
			if (sets[x].empty()) {
				sets[x].insert(j);
				ans++;
			} else {
				if (compare(x, *sets[x].rbegin(), j)) {
					sets[x].insert(j);
					ans++;
				}
			}
		}	
		cout << ans << endl;
	}
	return 0;
}
