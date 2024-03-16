#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool compareSecond(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    return a.second < b.second;
}

bool check_pos(vector<pair<ll, ll>> pos, vector<ll> pos_m, ll icp) {
	vector<ll> slopes;
	//cout << "restart: " << endl;
	for (const auto& coord : pos) {
		slopes.push_back((coord.second-icp)/coord.first);
	}
	sort(slopes.begin(), slopes.end(), greater<int>());
	for (int i = 0; i < slopes.size(); i++) {
		if (pos_m[i] > slopes[i]) {
			return false;
		}
		//cout << pos_m[i] << " > " << slopes[i] << endl; 
	}
	return true;
}

bool check_neg(vector<pair<ll, ll>> neg, vector<ll> neg_m, ll icp) {
	vector<ll> slopes;
	//cout << "restart: " << endl;
	for (const auto& coord : neg) {
		slopes.push_back((coord.second-icp)/coord.first);
	}
	sort(slopes.begin(), slopes.end());
	for (int i = 0; i < slopes.size(); i++) {
		if (neg_m[i] < slopes[i]) {
			return false;
		}
		//cout << neg_m[i] << " < " << slopes[i] << endl; 
	}
	return true;
}

ll find_pos(vector<pair<ll, ll>> pos, vector<ll> pos_m) {		
	sort(pos_m.begin(), pos_m.end(), greater<int>());
	ll hi = 1e9;
	ll lo = -1e18;
	while (hi > lo) {
		ll mid = (hi+lo+1)/2;
		//cout << mid << endl;
		if (check_pos(pos, pos_m, mid)) {
			lo = mid;	
		} else {
			hi = mid-1;
		}
	}	
	return lo;
}

ll find_neg(vector<pair<ll, ll>> neg, vector<ll> neg_m) {
	sort(neg_m.begin(), neg_m.end());
	ll hi = 1.1e18;
	ll lo = 0;
	while (hi > lo) {
		ll mid = (hi+lo)/2;
		//cout << mid << " " << hi << " " << lo << endl;
		if (check_neg(neg, neg_m, mid)) {
			hi = mid;
		} else {
			lo = mid+1;
		}
	}
	return hi;
}

int main() {
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; case_num++) {
		//cout << "case_num: " << case_num << endl;
		int N;
		ll X1;
		cin >> N >> X1;
		ll Y1[N], Y2[N], X2[N];
		vector<pair<ll,ll>> neg, pos, tba;
		vector<ll> neg_m, pos_m;
		for (int i = 0; i < N; i++) {
			cin >> Y1[i] >> Y2[i] >> X2[i];
			neg.push_back({X2[i], Y2[i]});
			pos.push_back({X2[i], Y1[i]});
			tba.push_back({X1, Y1[i]});
			tba.push_back({X1, Y2[i]});
		}
		int num_neg = 0;
		for (int i = 0; i < 4*N; i++) {
			int m;
			cin >> m;
			if (m < 0) {
				num_neg++;
				neg_m.emplace_back(m);
			} else {
				pos_m.emplace_back(m);
			}
		}

		//cout << "num_neg: " << num_neg << endl;
		if (num_neg < N || num_neg > 3*N) {
			cout << -1 << endl;
			continue;
		}
		
		//sort first
		sort(tba.begin(), tba.end(), compareSecond);
		num_neg -= N;
		for (int i = 0; i < 2*N; i++) {
			if (i < num_neg) {
				neg.push_back(tba[i]);	
			} else {
				pos.push_back(tba[i]);
			}
		}
		
		ll top_int = find_pos(pos, pos_m);
		ll bot_int = find_neg(neg, neg_m);
		//cout << bot_int << " " << top_int << endl;
		cout << bot_int - top_int << endl;
	}
	return 0;
}
