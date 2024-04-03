#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pl = pair<ll, int>;

int main() {
	int N, K;
	cin >> N >> K;
	int t[N];
	for (int i = 0; i < N; i++) {
		cin >> t[i];
	}
	priority_queue<pl, vector<pl>, greater<pl>> pq;
	for (int i = 0; i < K; i++) {
		pl add = {t[i], i};
		pq.push(add);
	}
	ll time = 0;
	int ind = K;
	int farmer;
	
	vector<vector<int>> events;
	while (true) {
		vector<int> free;
		do {
			auto rem = pq.top();		
			pq.pop();
			free.push_back(rem.second);
			time = rem.first;
		} while (!pq.empty() && time == pq.top().first);
		if (free.size() > 1) {
			vector<int> farmers;
			for (int f : free) {
				farmers.push_back(f);	
			}
			events.push_back(farmers);
		}
		bool quit = false;
		for (int f : free) {
			if (ind == N) {
				farmer = f;
				quit = true;
				break;
			}
			pl add = {t[ind]+time, f}; 
			pq.push(add);
			ind++;
		}
		if (quit) break;
	}
	cout << time << endl;
	vector<bool> can_interview(K, false);
	can_interview[farmer] = true;
	for (int i = (int)events.size()-1; i >= 0; i--) {
		bool intersect = false;
		for (int j : events[i]) {
			if (can_interview[j]) {
				intersect = true;
				break;
			}
		}
		if (intersect) {
			for (int j : events[i]) {
				can_interview[j] = true;
			}
		}
	}
	for (bool b : can_interview) {
		cout << b;
	}
	cout << endl;
	return 0;
}
