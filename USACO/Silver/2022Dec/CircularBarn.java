import java.io.*;
import java.util.*;
import java.lang.*;

class CircularBarn {  

	public static void main(String[] args) throws IOException{
		//first make a list of primes
		int MAX = 5000000;
		boolean[] prime = new boolean[MAX+1];
		for (int i=2;i<=MAX;i++) prime[i] = true;
		for (int i = 1; i <= MAX; i++) {
			if (!prime[i]) {
				continue;
			}
			for (int j = i+i; j <= MAX;j+=i) {
				prime[j] = false;
			}
		}

		//evaluate each winning
		int[] turns = new int[MAX+1];
		turns[0] = 0;
		turns[1] = 1;
		turns[2] = 1;
		turns[3] = 1;
		turns[4] = 1;
		//prev primes with mult__
		int prev1 = 1;
		int prev2 = 2;
		int prev3 = 3;		
		for (int i = 5; i <= MAX; i++) {
			if (i%4 == 0) turns[i] = (i/4);
			if (i%4 == 1) {
				if (prime[i]) prev1 = i; 
				turns[i] = 1 + turns[i-prev1];				
			} else if (i%4 == 2) {
				turns[i] = 1 + turns[i-2];
			} else if (i%4 == 3) {
				if (prime[i]) prev3 = i;
				turns[i] = 1 + turns[i-prev3];		
			}
		}
		for (int i = 1; i <= MAX; i++) {
			if (i%4==0) {
				turns[i]++;
			}
		}

		//I O 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer t = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(t.nextToken());
		for (int i = 0; i < T; i++) {
			t = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(t.nextToken());
			int[] barns = new int[N];
			t = new StringTokenizer(br.readLine());
			for (int k = 0; k < N; k++) {
				int a = Integer.parseInt(t.nextToken());
				barns[k] = a;
			}
			int minW = 5000000;
			int minL = 5000000;
			int iL = 5000000;
			int iW = 5000000;
			for (int k = 0; k < N; k++) {
				if (barns[k]%4==0) {
					if (minL > turns[barns[k]]) {
						minL = turns[barns[k]];
						iL = k;
					}					
				} else {
					if (minW > turns[barns[k]]) {
						minW = turns[barns[k]];
						iW = k;
					}
				}
			}
			if (minL > minW) {
					System.out.println("Farmer John");
			} else if (minL < minW) {
					System.out.println("Farmer Nhoj");
			} else {
				if (iL < iW) {
					System.out.println("Farmer Nhoj");
				} else {
					System.out.println("Farmer John");
				}
			}
		}
	}
}
