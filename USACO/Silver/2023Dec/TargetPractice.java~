import java.util.*;
import java.io.*;
import java.lang.*;

class TargetPractice {
	static int T, C;
	static boolean[] targets;	
	static char[] cmds; 

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer t = new StringTokenizer(br.readLine());
		T = Integer.parseInt(t.nextToken());
		C = Integer.parseInt(t.nextToken());
		cmds = new char[C];
		targets = new boolean[2*C+5];
		HashMap<Integer, Integer> posHit = new HashMap<>(); // pos time
		HashMap<Integer, Integer> timeHit = new HashMap<>(); //time pos		
		//put in the position
		HashSet[] suffHit = new HashSet[5]; // 0 =-2 | 1 = -1 ... 
		HashSet[] willAdd = new HashSet[5];
		for (int i = 0; i < 5; i++) {
			suffHit[i] = new HashSet<Integer>();
			willAdd[i] = new HashSet<Integer>();
		}
		t = new StringTokenizer(br.readLine());
		for (int i = 0; i < T; i++) {
			int temp = Integer.parseInt(t.nextToken());
			targets[temp+C] = true;
		}
		t = new StringTokenizer(br.readLine());
		cmds = t.nextToken().toCharArray();
		int pos = C;
		for (int i = 0; i < C; i++) {
			char c = cmds[i];
			if (c == 'F') {	
				if (targets[pos] && !posHit.containsKey(pos)) {
					posHit.put(pos, i);
					timeHit.put(i, pos);
				}	
			}
			pos += (c == 'L') ? -1 : 0;
		   	pos += (c == 'R') ? 1 : 0;

		}

		int max = posHit.size();
		for (int i = C-1; i >= 0; i--) {
			char c = cmds[i];		
			//remove the things once they're done with???? 
			if (timeHit.containsKey(i)) {
				posHit.remove(timeHit.get(i));
				timeHit.remove(i);
				for (int j = 0; j < 5; j++) {
					if (willAdd[j].contains(pos)) {
						suffHit[j].add(pos);
						willAdd[j].remove(pos);
					}
				}
			}	
			//move
			pos += (c == 'L') ? 1 : 0;
		   	pos += (c == 'R') ? -1 : 0;
			//calculate max
			switch (c) {
				case 'R':
					max = Math.max(timeHit.size()+suffHit[0].size(), max);
					//make sure not hit from the bACK ALREADY
					int addr = (targets[pos] && !posHit.containsKey(pos) &&
							 !suffHit[1].contains(pos)) ? 1 : 0;
					max = Math.max(timeHit.size()+suffHit[1].size()+addr, max);
					break;
				case 'L':
					max = Math.max(timeHit.size()+suffHit[4].size(), max);
					int addl = (targets[pos] && !posHit.containsKey(pos) &&
							 !suffHit[3].contains(pos)) ? 1 : 0;
					max = Math.max(timeHit.size()+suffHit[3].size()+addl, max);
					break;
				case 'F': 
					//add
					max = Math.max(timeHit.size()+suffHit[1].size(), max);
					max = Math.max(timeHit.size()+suffHit[3].size(), max);
					break;
			}
			if (c == 'F') {
				for (int j = -2; j <= 2; j++) {
					if (pos+j < 0 || pos+j > targets.length) continue; 
					//makes sure that there is a target
					//make sure the target isn't being hit from front 
					if (targets[pos+j]) { 
						if (posHit.containsKey(pos+j)) {
							willAdd[j+2].add(pos+j);
						} else {
							suffHit[j+2].add(pos+j);
						}
					}
				}
			}
		}
	System.out.println(max);		
	}
}
