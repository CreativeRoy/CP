#include <bits/stdc++.h>

using namespace std;

void modify(unordered_map<int, int>& map, int entry, int val) {
	if (map.find(entry) != map.end()) {
		if (map[entry] < val) {
			map[entry] = val;
		}
	} else {
		map[entry] = val;
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	int val[N], price[N];
	for (int i = 0; i < N; i++) {
		cin >> val[i] >> price[i];
	}
	unordered_map<int, int> map;
	for (int i = 0; i < N; i++) {
		int v = val[i];
		int p = price[i];
		cout << "new: " << p << " " << v << endl;
		vector<int> modP;
		vector<int> modV;
		for (const auto& pair : map) {
			cout << "old " << pair.first << " " << pair.second << endl; 
			modP.push_back(pair.first + p);
			modV.push_back(pair.second + v);
		}
		for (int i = 0; i < modP.size(); i++) {
			modify(map, modP[i], modV[i]);
		}
		modify(map, p, v);
	}
	int ans = 0;
	for (const auto& pair : map) {
		cout << pair.first << " " << pair.second << endl;
		if (pair.first <= M) {
			ans = max(ans, pair.second);
		}
	}
	cout << ans << endl;
	return 0;
}
