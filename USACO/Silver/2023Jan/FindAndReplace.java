import java.io.*;
import java.util.*;

class FindAndReplace {
	static int T, N;
	static HashMap<Character, Integer> groups;
	static HashMap<Character, Character> to;
	static HashMap<Character, HashSet<Character>> from;
	static int count; 
	static int cycles;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer t = new StringTokenizer(br.readLine());
		T = Integer.parseInt(t.nextToken());
		while (T-- > 0) {
			String a, b;
			t = new StringTokenizer(br.readLine());
			a = t.nextToken();
			t = new StringTokenizer(br.readLine());
			b = t.nextToken();
			N = a.length();
			to = new HashMap<>();
			from = new HashMap<>();
			groups = new HashMap<>();
			boolean bad = false;
			int sum = 0;
			for (int i = 0; i < N; i++) {
				if (to.containsKey(a.charAt(i)) && 
					to.get(a.charAt(i)) != b.charAt(i)) {
					bad = true;
					break;
				}
				if (!to.containsKey(a.charAt(i))) { 
					sum += (a.charAt(i) != b.charAt(i)) ? 1 : 0;
				}
				if (!from.containsKey(b.charAt(i))) {
					from.put(b.charAt(i), new HashSet<>());
				}
				from.get(b.charAt(i)).add(a.charAt(i));
				to.put(a.charAt(i), b.charAt(i));
			}
			count = 0;
			cycles = 0;
			for (int i = 0; i < N; i++) {
				char c = a.charAt(i);
				if (groups.containsKey(c)) continue;
				count++;
				dfs_letters(c);
			}
			if (bad || (from.size() == 52 && sum != 0)) {
				System.out.println(-1);
			} else {
				System.out.println((sum + cycles));
			}
		}
	}

	//finding pure cycles 
	public static void dfs_letters(char c) {
		groups.put(c, count);
		if (to.containsKey(c)) {
			char next = to.get(c);
			if (from.get(next).size() > 1) {
				return;
			}	
			if (groups.containsKey(next)) {
				if (groups.get(next) == count && c != next) {
					cycles++;
				}		
			} else {
				dfs_letters(next);
			}
		}
	}
}
