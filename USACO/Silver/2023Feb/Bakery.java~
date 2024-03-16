import java.io.*;
import java.util.*;
import java.lang.*;

class Bakery {
	static long[] a;
	static long[] b;
	static long[] c;
	static int N;
	static int t_c, t_m;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer t = new StringTokenizer(br.readLine());
		PrintWriter pw = new PrintWriter(System.out);
		int T = Integer.parseInt(t.nextToken());
		while (T-- > 0) {
			t = new StringTokenizer(br.readLine());
			t = new StringTokenizer(br.readLine());
			N = Integer.parseInt(t.nextToken());
			t_c = Integer.parseInt(t.nextToken());
			t_m = Integer.parseInt(t.nextToken());
			a = new long[N];
			b = new long[N];
			c = new long[N];
			for (int i = 0 ; i < N; i++) {
				t = new StringTokenizer(br.readLine());
				a[i] = Long.parseLong(t.nextToken());
				b[i] = Long.parseLong(t.nextToken());
				c[i] = Long.parseLong(t.nextToken());
			}
			long hi = t_c+t_m-2;
			long lo = 0;
			long ans = 0;
			while (lo < hi) {
				long mid = (hi+lo)/2;
				if (test(mid)) {
					hi = mid;
				} else {
					lo = mid+1;
				}	
			}
			pw.println(lo);
		}	
		pw.flush();
	}

	static boolean test(long m) {
		//System.out.println("m: " + m);

		long min = Math.max(1, t_c-m);
		long max = Math.min(t_c, t_c+t_m-1-m);

		for (int i = 0; i < N; i++) {
			long d = t_c+t_m-m;
			if (a[i] > b[i]) {
				max = Math.min(max, (long)Math.floor((c[i] - d * b[i])/(a[i]-b[i])));
			} else if (a[i] < b[i]) {
				min = Math.max(min, (long)Math.ceil((b[i]*d - c[i] + (b[i]-a[i]-1))/(b[i]-a[i])));	
			} else if (a[i] == b[i]) {
				if (a[i]*(t_c+t_m-m) > c[i]) {
					return false;
				}
			}
		}
		return (min <= max);
	}
}
