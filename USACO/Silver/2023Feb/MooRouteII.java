import java.io.*;
import java.util.*;

class MooRouteII {
	static int N, M;
	static int[] a;
	static ArrayList<Flight>[] flights;
	static int[] time;
	static int max = 1000000001;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer t = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(t.nextToken());
		int M = Integer.parseInt(t.nextToken());
		
		a = new int[N+1];
		time = new int[N+1];
		flights = new ArrayList[N+1];
		
		for (int i = 1; i <= N; i++) {
			flights[i] = new ArrayList<Flight>(); 
			time[i] = max;
		}	
		time[1] = 0;

		for (int i = 0; i < M; i++) {
			t = new StringTokenizer(br.readLine());
			int c = Integer.parseInt(t.nextToken());
			int r = Integer.parseInt(t.nextToken());
			int d = Integer.parseInt(t.nextToken());
			int s = Integer.parseInt(t.nextToken());
			flights[c].add(new Flight(c, r, d, s));
		}
			
		t = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++) {
			a[i] = Integer.parseInt(t.nextToken());
			for (int j = 0; j < flights[i].size(); j++) {
				flights[i].get(j).edit(a[i]);
			}
		}
		for (int i = 1; i <= N; i++) Collections.sort(flights[i], Collections.reverseOrder()); 
		Queue<Flight> q = new PriorityQueue<Flight>();
		
		for (Flight f : flights[1]) {
			q.add(f);
		}
		int[] ind = new int[N+1];
		while (!q.isEmpty()) {
			Flight f = q.poll();
			//f.display();
			//System.out.println(ind[f.ap2] + " < " + flights[f.ap2].size());
			//System.out.println(f.t2 + " <= " + flights[f.ap2].get(ind[f.ap2]).t1);
			while (ind[f.ap2] < flights[f.ap2].size() && 
					f.t2 <= flights[f.ap2].get(ind[f.ap2]).t1) {
				q.add(flights[f.ap2].get(ind[f.ap2]));
				ind[f.ap2]++;
			}
			if (f.t2 < time[f.ap2]) time[f.ap2] = f.t2;
		}
		boolean first = true;
		for (int i : time) {
			if (first) {
				first = false;
				continue;
			}
			if (i == max) {
				System.out.println("-1");
				continue;
			}
			System.out.println(i);
		}
	}

	static class Flight implements Comparable<Flight> {
		int ap1, ap2, t1, t2;
			
		public Flight(int ap1, int t1, int ap2, int t2) {
			this.ap1 = ap1;
			this.ap2 = ap2;
			this.t1 = t1;
			this.t2 = t2;
		}

		public int compareTo(Flight other) {
			return t1 - other.t1;
		}	

		public void display() {
			System.out.println(ap1 + " " + t1 + " --> " + ap2 + " " + t2);
		}	

		public void edit(int i) {
			t1-=i;
		}
	}

}
