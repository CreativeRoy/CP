#include <bits/stdc++.h>

using namespace std;



class DisjointSets {

  private:

	vector<int> parents;

	vector<int> sizes;


  public:

	DisjointSets(int size) : parents(size), sizes(size, 1) {

		for (int i = 0; i < size; i++) { parents[i] = i; }

	}


	/** @return the "representative" node in x's component */

	int find(int x) {

		return parents[x] == x ? x : (parents[x] = find(parents[x]));

	}


	/** @return whether the merge changed connectivity */

	bool unite(int x, int y) {

		int x_root = find(x);

		int y_root = find(y);
		//cout << x_root << " " << y_root << endl;
		if (x_root == y_root) { return false; }


		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }

		sizes[x_root] += sizes[y_root];

		parents[y_root] = x_root;

		return true;

	}


	/** @return whether x and y are in the same connected component */

	bool connected(int x, int y) { return find(x) == find(y); }

	int set_size(int x) {
		int x_root = find(x);
		return sizes[x_root];
	}

};


int main() {
	int N, M;
	cin >> N >> M;
	vector<int> edges[N];
	int num_edges[N] = {};
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		num_edges[a]++, num_edges[b]++;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	set<pair<int, int>> line;
	for (int i = 0; i < N; i++) {
		line.insert({num_edges[i], i});
	}
	//removal algorithm
	
	int rem = N-1;
	int rem_ind[N] = {};
	int rem_min[N] = {};
	bool active[N] = {false};	
	while(!line.empty()) {
		/*
		//to string
		for (auto pr : line) {
			cout << "("<< pr.second << "," << pr.first << ") ";
		}
		cout << endl;
		*/
		auto it = line.begin();
		int node = it->second;
		rem_min[rem] = it->first;
		rem_ind[rem] = it->second; 
		rem--;
		active[node] = false;
		//update the removal
		for (int fr : edges[node]) {
			// if it still exists in list, delete re-add it
			auto fr_it = line.find({num_edges[fr], fr});
			if (fr_it != line.end()) {
				line.erase(fr_it);
				num_edges[fr]--;
				line.insert({num_edges[fr], fr});
			}
		}
		line.erase(it);
	}


	//iterate through the order of removal
	long long ans = 0;
	DisjointSets dsu(N);
	bool added[N] = {false};
	int union_size = 1;
	for (int i = 0; i < N; i++) {
		int node =  rem_ind[i];
		added[node] = true;
		for (int fr : edges[node]) {
			if (added[fr]) {
				//connect the nodes
				dsu.unite(node, fr);
				union_size = max(union_size, dsu.set_size(node));
			}
		}
		//get size of node
		//multiply size by rem_min, save the answer
		/*
		for (int j = 0; j < N; j++) {
			if (added[j]) {
				cout << j << " ";
			}
		}
		cout << endl;
		cout << union_size << " " << rem_min[i] << endl;
		*/
		ans = max(ans, 1ll * union_size*rem_min[i]);
	}
	cout << ans << endl;	
	return 0;
}
