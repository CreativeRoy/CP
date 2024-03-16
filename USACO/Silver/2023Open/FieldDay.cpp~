#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	int C, N;
	cin >> C >> N;
	int teams[N];
	int opp[N];
	int x = 1;
	for (int i = 0; i < C; i++) x = x << 1;
	int bi[x+1] = {0};	
	queue<int> q;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		int tm = 0;
		int op = 0;
		for (char c : str) {
			tm = tm << 1;
			op = op << 1;
			if (c == 'G') {
				tm += 1;
				op += 0;
			} else {
				tm += 0;
				op += 1;
			}
		}
		opp[i] = op;
		teams[i] = tm;
		bi[tm] = 1;
		q.push(tm);
	}
	while(!q.empty()) {
		int ind = q.front();
		q.pop();
		int k = 1;
		for (int i = 0; i < C; i++) {
			int temp = ind ^ k;
		   	if (bi[temp] == 0) {
				bi[temp] = bi[ind]+1;
				q.push(temp);	
			}
			k = k << 1;
		}	
	}
	for (int op : opp) {
		cout << (C - bi[op] + 1) << endl;
	}
}

