#include <iostream>
#include <vector>
#include <tuple>
using ll = long long;
using namespace std;

vector<ll> h, subtree_sum;
vector<vector<int>> adj;
vector<tuple<int, int, ll>> orders;

ll avg = 0;

void fill_subtree_sum(int node = 0, int parent = 0) {
	subtree_sum[node] = h[node]-avg;
	for (int child: adj[node]) {
		if (child != parent) {
			fill_subtree_sum(child, node);
			subtree_sum[node] += subtree_sum[child];
		}
	}
}

void create_orders(int node = 0, int parent = 0) {
	for (int child : adj[node]) {
		if (child != parent) { 
			if (subtree_sum[child] >= 0) {
				create_orders(child, node);
			} 
			if (subtree_sum[child] > 0) {
				orders.emplace_back(child, node, subtree_sum[child]);
			}
		}
	}
	for (int child : adj[node]) {
		if (child != parent && subtree_sum[child] < 0) {
			orders.emplace_back(node, child, -subtree_sum[child]);	
			create_orders(child, node);
		}
	}
}

int main() {	
	int N;
	cin >> N;
	h.resize(N), subtree_sum.resize(N);	
	for (ll &t : h) {cin >> t, avg += t;}
	avg /= N;
	adj.resize(N);	
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b, a--, b--;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a); 		
	}
	fill_subtree_sum();
	create_orders();
	cout << size(orders) << "\n";
	for (auto [a, b, c]: orders) {cout << ++a << " " << ++b << " " << c << "\n";}
	return 0;
}
