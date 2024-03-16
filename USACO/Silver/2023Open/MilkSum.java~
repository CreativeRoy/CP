import java.io.*;
import java.util.*;

public class MilkSum {
	static int N, Q;
	static int[] cows;
	static int[] sortCows;
	static long[] sums;
	static TreeMap<Long, Integer> map; //key is val entry is index 
	static long defSum;	

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer t = new StringTokenizer(br.readLine());
		N = Integer.parseInt(t.nextToken());
		map = new TreeMap<>();
		cows = new int[N];
		sortCows = new int[N];
		sums = new long[N+1];
		t = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			cows[i] = Integer.parseInt(t.nextToken());
			sortCows[i] = cows[i];			
		}
		Arrays.sort(sortCows);
		map.put(Long.MIN_VALUE,0);
		for (int i = 0; i < N; i++) {
			map.put(Long.valueOf(sortCows[i]), i+1);
			defSum += (long)(sortCows[i])*(i+1);
			sums[i+1] = sums[i]+sortCows[i];
		}		
		t = new StringTokenizer(br.readLine());
		Q = Integer.parseInt(t.nextToken());
		for (int i = 0; i < Q; i++) {
			t = new StringTokenizer(br.readLine());
			int ind = Integer.parseInt(t.nextToken())-1;

			long newVal = Integer.parseInt(t.nextToken());	
			long prevVal = cows[ind];

			int prevInd = map.get(prevVal);		
			int newInd = map.lowerEntry(newVal).getValue()+1;

			long maxSum = defSum;
			
			if (newVal > prevVal) {
				maxSum += (long)(newInd-1)*newVal;
				maxSum -= (long)prevInd*prevVal;
				maxSum -= sums[newInd-1] - sums[prevInd];	
			} else if (newVal < prevVal) {
			   	maxSum -= (long)prevInd*prevVal;
				maxSum += (long)newInd*newVal;
				maxSum += sums[prevInd-1] - sums[newInd-1];
			}
			System.out.println(maxSum);
		}	
	}
}
