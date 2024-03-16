import java.io.*;
import java.util.*;

class PotionFarming {
	static int N;
	static int[] potions;
	static TreeSet<Integer> tree;
	static ArrayList<Integer> leaves;
	static ArrayList<Integer>[] paths;
	static ArrayList<Integer>[] adj;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer t = new StringTokenizer(br.readLine());
		N = Integer.parseInt(t.nextToken());
		potions = new int[N];
		adj = new ArrayList[N];
		paths = new ArrayList[N];
		leaves = new ArrayList<Integer>();
		tree = new TreeSet<Integer>();
		t = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			adj[i] = new ArrayList<Integer>();
			paths[i] = new ArrayList<Integer>();
			potions[i] = Integer.parseInt(t.nextToken())-1;
		}
		int ans = 0;
		for (int i = 0; i < N-1; i++) {
			t = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(t.nextToken())-1;
			int b = Integer.parseInt(t.nextToken())-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		recurse(0, 0);
		for (int i = 0; i < leaves.size(); i++) {
			tree.add(potions[i]);
			//System.out.print((potions[i]+1) + " ");
		}
		//System.out.println();
		for (int i = 0; i < leaves.size(); i++) {
			int node = leaves.get(i);
			//System.out.println("node: " + (node+1));
			for (int j = paths[node].size()-1; j >= 0; j--) {
				int n = paths[node].get(j);
				if (tree.contains(n)) {
					ans++;
					//System.out.println("n: " + (n+1));
					tree.remove(n);
					break;
				}
			}
		}
		System.out.println(ans);
	}

	static void recurse(int node, int par) {
		paths[node] = new ArrayList<Integer>(paths[par]);
		paths[node].add(node);
		for (int n : adj[node]) {
			if (n != par) {
				recurse(n, node);
			}
		}
		if (adj[node].size() == 1) {
			leaves.add(node);
		}
	}	
}
