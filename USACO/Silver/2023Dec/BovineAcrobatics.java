import java.io.*;
import java.util.*;


class BovineAcrobatics {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer t = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(t.nextToken());
		int M = Integer.parseInt(t.nextToken());
		int K = Integer.parseInt(t.nextToken());
		CowGroup[] cowGroups = new CowGroup[N];
		for (int i = 0; i < N; i++) {
			t = new StringTokenizer(br.readLine());
			int weight = Integer.parseInt(t.nextToken());
			int amt = Integer.parseInt(t.nextToken());
			cowGroups[i] = new CowGroup(weight, amt);
		}
		Arrays.sort(cowGroups, Comparator.comparingInt(group -> group.weight));
		
		TreeSet<CowGroup> towers = new TreeSet<CowGroup>(Comparator.comparingInt(group -> 
							group.weight));
		int numTowers = 0;
		long ans = 0;
		for (CowGroup group : cowGroups) {
			int addAmt = group.amt;
			while (addAmt > 0) {
				CowGroup top = towers.floor(new CowGroup(group.weight - K, 0));
				if (top == null) {
					break;	
				}
				towers.remove(top);
				if (top.amt > addAmt) {
					towers.add(new CowGroup(top.weight, top.amt - addAmt));
					addAmt = 0;
				} else {
					addAmt -= top.amt;					
				}
			}
			numTowers -= group.amt - addAmt;
			int canAdd = Math.min(group.amt, M - numTowers);
			numTowers += canAdd;
			ans += (long)canAdd;
			towers.add(new CowGroup(group.weight, canAdd));					
		}
		System.out.println(ans);
	}

	static class CowGroup {
		final int weight;
		final int amt;

		CowGroup(int weight, int amt) {
			this.weight = weight;
			this.amt = amt;
		}
	}
}
