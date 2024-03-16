import java.io.*;
import java.util.*;

class MooRoute {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer t = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(t.nextToken());
		List<String> ans = new ArrayList<String>();
	   	int[] A = new int[N+1];
		t = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			A[i] = Integer.parseInt(t.nextToken());	
		}	
		
		int empty = N;
		int curr = 0;
		int i = 0;
		while (!(curr == 0 && empty == 0)) {
			while (A[curr] != 0) {
				A[curr]--;
				curr++;
				ans.add("R");
			} 
			while (curr > 0) {
				if (A[curr-1] == 1) {
					if (empty != curr) {
						break;
					} 
				}
				A[curr-1]--;
				if (A[curr-1] == 0) empty = curr-1;
			   	curr--;	
				ans.add("L");
			}
		} 
		for (String c : ans) System.out.print(c);
		System.out.println();
	}

}

