#include <iostream>
#include <vector>

using namespace std;

bool leaf[100001];
int points[100001];
int under_leaf[100001];
int pot_spots[100001];
vector<int> adj[100001];

int dfs_calc_leaves(int par, int node) {
	int curr = 0;
	if (adj[node].size() == 1) {
		//cout << "leaf!" << endl;
		leaf[node] = true;
		curr++;
	}
	//cout << adj[node].size() << endl;
	for (int n : adj[node]) {
		if (n != par) {
			curr += dfs_calc_leaves(node, n);
		}
	}
	under_leaf[node] = curr;
	return curr;
}

int dfs_calc_pots(int par, int node) {
	int cur_leaf = under_leaf[node];
	int cur_pot = 0;
	cur_pot+=pot_spots[node];
	for (int n : adj[node]) {
		if (n != par) {
			cur_pot += dfs_calc_pots(node, n);
		}
	}
	return min(cur_pot, cur_leaf);
}

int main() {
	int N; 	
	cin >> N;
	int pots[N];
	for (int &p : pots) {
		cin >> p;
	}
	for (int i = 0; i < N-1; i++) {
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int num_leaves = dfs_calc_leaves(1, 1);
	if (leaf[1]) {
		leaf[1] = false;
		num_leaves--;
	}
	//cout << "num_leaves: " << num_leaves << endl;
	for (int i = 0; i < num_leaves; i++) {
		pot_spots[pots[i]]++; 
	}
	cout << dfs_calc_pots(1, 1) << endl;
}

