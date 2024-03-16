import java.io.*;
import java.util.*;

class FollowingDirections {
	static int N;
	static char[][] directions;
	static int[][] costs;
	static int[][] values;


	static long calculate() {
		long sum = 0;
		for (int i = 0; i < N; i++) {
			sum += (long)costs[i][N]*values[i][N] + (long)costs[N][i]*values[N][i];
		}
		return sum;
	}

	static void dfs_change_values(int x, int y, int amt) {
		if (x > N || y > N) {
			return;
		}
		values[x][y] += amt;
		if (directions[x][y] == 'R') {
			dfs_change_values(x+1, y, amt);
		} else if (directions[x][y] == 'D') {
			dfs_change_values(x, y+1, amt);
		}
	}

	static void fill_values(int x, int y) {
		if (x == N || y == N) { 	
			return;
		}
		if (directions[x][y] == 'R') {
			values[x+1][y]+=values[x][y]; 
		} else if (directions[x][y] == 'D') {
			values[x][y+1]+=values[x][y];
		}	
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer t = new StringTokenizer(br.readLine());
		N = Integer.parseInt(t.nextToken());
		directions = new char[N+1][N+1];
		costs = new int[N+1][N+1];
		values = new int[N+1][N+1];//x y 
		for (int i = 0; i < N; i++) {
			t = new StringTokenizer(br.readLine());
			String dirs = t.nextToken();
			for (int j = 0; j < N; j++) {
				directions[j][i] = dirs.charAt(j);
			}
			costs[N][i] = Integer.parseInt(t.nextToken());
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				values[j][i] = 1;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				fill_values(j, i);
			}
		}
		t = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			costs[i][N] = Integer.parseInt(t.nextToken());
		}
		t = new StringTokenizer(br.readLine());
		int Q = Integer.parseInt(t.nextToken());
		System.out.println(calculate());	
		
		while (Q-- > 0) {
			t = new StringTokenizer(br.readLine());
			int y = Integer.parseInt(t.nextToken())-1;
			int x = Integer.parseInt(t.nextToken())-1;
			if (directions[x][y] == 'R') {
				dfs_change_values(x+1, y, -1*values[x][y]);
				directions[x][y] = 'D';
				dfs_change_values(x, y+1, values[x][y]);
			} else if (directions[x][y] == 'D'){
				dfs_change_values(x, y+1, -1*values[x][y]);
				directions[x][y] = 'R';
				dfs_change_values(x+1, y, values[x][y]);
			}			
			System.out.println(calculate());
		}
	}
}
