import java.io.*;
import java.util.*;
import java.lang.*;

class CowLibi {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer t = new StringTokenizer(br.readLine());
		int G, N;
		G = Integer.parseInt(t.nextToken());
		N = Integer.parseInt(t.nextToken());		
		TreeMap<Integer, Coord> grazes = new TreeMap<Integer, Coord>();
		for (int i = 0; i < G; i++) {
			t = new StringTokenizer(br.readLine());
			long x = Integer.parseInt(t.nextToken());
			long y = Integer.parseInt(t.nextToken());
			int t2 = Integer.parseInt(t.nextToken());
			grazes.put(t2, new Coord(x, y));
		}
		int ans = 0;
		while (N-- > 0) {
			t = new StringTokenizer(br.readLine());
			long X = Long.parseLong(t.nextToken());
			long Y = Long.parseLong(t.nextToken());
			int T = Integer.parseInt(t.nextToken());
			if (grazes.floorKey(T) != null) {
				int tc = grazes.floorKey(T);
				//System.out.println("Less T, tc: " + T + " " + tc + ": " + Math.abs(T-tc));
				Coord C = grazes.get(tc);
				if (!reachable(T, X, Y, tc, C.x, C.y)) {
					//unreachable 
					//System.out.println("X, C.x: " + X + " " + C.x + ": " + Math.abs(X-C.x));
					//System.out.println("Y, C.y: " + Y + " " + C.y + ": " + Math.abs(Y-C.y));
					//innocent
					ans++;
					continue;
				}	
			}
			if (grazes.higherKey(T) != null) {
				int tc = grazes.higherKey(T);

				//System.out.println("More T, tc: " + T + " " + tc);
				Coord C = grazes.get(tc);
				if (!reachable(tc, C.x, C.y, T, X, Y)) {
					//System.out.println("X, C.x: " + X + " " + C.x + ": " + Math.abs(X-C.x));
					//System.out.println("Y, C.y: " + Y + " " + C.y + ": " + Math.abs(Y-C.y));
					//innocent
					ans++;
					continue;
				}	
			}
			//System.out.println("t: " + T);
			//System.out.println("X, Y: " + X + " " + Y);
		}
		System.out.println(ans);
	}
	
	static boolean reachable(long t1, long x1, long y1, long t2, long x2, long y2) {
    	long xDiff = x1 - x2;
    	long yDiff = y1 - y2;

    	long squaredDistance = xDiff * xDiff + yDiff * yDiff;

    	if (t1 == t2) {
        	// Check for identical coordinates when times are the same
        	return (xDiff == 0 && yDiff == 0);
    	}

    	long squaredTimeDiff = (long)(t1 - t2) * (long)(t1 - t2);
    
		return (squaredDistance <= squaredTimeDiff); 	 	
	}

	static class Coord {
		public long x, y;

		public Coord(long x, long y) {
			this.x = x;
			this.y = y;
		}
	}	
}	

