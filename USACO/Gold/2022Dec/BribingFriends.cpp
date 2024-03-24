#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	int dp[N][2000][2] = {0};
	vector<array<int, 3>> cows(N);
	for (auto &[x, p, c] : cows) {
		cin >> p >> c >> x;
	}	
	sort(cows.begin(), cows.end());	
	for (int i = 0; i < N; i++) {	
		//current
		auto [x, p, c] = cows[i];
		if (i != 0) {
			//mooney 
			for (int j = 0; j < A; j++) {
				dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0]);
				if (j < c) {
					//nothing happens
					dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0]);
				} else {
					//we see if one is better
					dp[i][j-c][0] = max(dp[i][j-c][0], dp[i-1][j][0]+p);
				}
			}
			//ice cream
			for (int j = 0; j < B; j++) {
				dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1]);
				if (j/x < c) {
					//not enough ice cream
					int new_c = c - j/x;
					if (new_c > A) continue;
					dp[i][A-new_c][0] = max(dp[i][A-new_c][0], dp[i-1][j][1]+p);
				} else {
					//enough ice cream
					dp[i][j-c*x][1] = max(dp[i][j-c*x][1], dp[i-1][j][1]+p);
				}
			}
		}
		//do the curr
		dp[i][B][1] = max(0, dp[i][B][1]);
		if (B/x < c) {
			//have to use money
			int new_c = c-B/x;
			//cant afford
			if (new_c > A) continue;
			//can afford
			dp[i][A-new_c][0] = max(dp[i][A-new_c][0], dp[i][B][1]+p);
		} else {
			//dont have to use money
			dp[i][B-c*x][1] = max(dp[i][B][1] + p, dp[i][B-c*x][1]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= A; i++) {
		ans = max(ans, dp[N-1][i][0]);
	}
	for (int i = 0; i <= B; i++) {
		ans = max(ans, dp[N-1][i][1]);
	}

	cout << ans << endl;
	return 0;	
}
