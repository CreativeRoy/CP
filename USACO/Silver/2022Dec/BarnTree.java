import java.io.*;
import java.lang.*;
import java.util.*;

class BarnTree {
	public static int[] barns;
	public static int[] barnSums;
	public static boolean[] v;
	public static ArrayList<Integer>[] paths;
	public static int ans = 0;
	public static int avg = 0;
	public static void main(String args[]) throws IOException {
		BarnTree bt = new BarnTree();
		bt.work();
	}
	
	public static void work() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer t = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(t.nextToken());
		barns = new int[N];
		barnSums = new int[N];
		paths = new ArrayList[N];
		v = new boolean[N];
		t = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			paths[i] = new ArrayList<Integer>(0);
			barns[i] = Integer.parseInt(t.nextToken());
			avg+=barns[i];
		}
		avg = avg/N;
		for (int i = 0; i < N-1; i++) {
			barns[i]-=avg;
			t = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(t.nextToken());
			int b = Integer.parseInt(t.nextToken());
			paths[a-1].add(b-1);
			paths[b-1].add(a-1);
		}
		barns[N-1]-=avg;
		//sum from top of tree
		sum(0);
		//debug 
		/*
		for (int i = 0; i < N; i++) {
			System.out.println(barns[i] + " " + barnSums[i]);
		}
		*/
		//end of debug
		//System.out.println("---------------");
		for (int i = 0; i < N; i++) v[i] = false; 
		recurse(0, 0);
		System.out.println(ans);
	}
	
	public static int sum(int node) {
		if (v[node]) {
			return 0;
		}
		v[node] = true;
		int tot=0;
		for (int i = 0; i < paths[node].size(); i++) {
			tot+=sum(paths[node].get(i));
		}
		barnSums[node] = tot+barns[node];
		return tot+barns[node];
	}

	public static void recurse(int node, int prevNode) {
		//recurse() +subtree
		//move to parent
		//move to child
		//recurse() -subtree
		if (v[node]) {
			return;
		}
		v[node] = true;
		for (int i = 0; i < paths[node].size(); i++) {
			if (v[paths[node].get(i)]) {
				continue;
			}
			if (barnSums[paths[node].get(i)] > 0) {
				ans++;
				recurse(paths[node].get(i), node);
			} else if (barns[i]==0) {
				recurse(paths[node].get(i), node);
			}
		}
		if (barns[node] > 0) {
			System.out.println((int)(node+1) + " " + (int)(prevNode+1) + " " + barns[node]);
			barns[prevNode] += barns[node];
			barns[node] = 0;
		}
		for (int i = 0; i < paths[node].size(); i++) {
			if (v[paths[node].get(i)]) {
				continue;
			}
			if (barnSums[paths[node].get(i)] < 0) {
				ans++;
				int bs = barnSums[paths[node].get(i)];
				System.out.println((int)(node+1) + " " + (int)(paths[node].get(i)+1) + " " + bs);
				barns[node]-=bs;
				barns[paths[node].get(i)]+=bs;
				recurse(paths[node].get(i), node);
			} 
		} 
	}
}
