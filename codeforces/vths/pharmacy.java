import java.io.*;
import java.util.*;

public class pharmacy {
	static long N, T, R, S, rtime, stime, done;
	public static void main(String[] args) throws IOException{
		
		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		// input file name goes above
		
		StringTokenizer st = new StringTokenizer(sc.readLine());
		N = Long.parseLong(st.nextToken());
		T = Long.parseLong(st.nextToken());
		
		long[] techs = new long[(int)T];
		
		ArrayList<Request> rem = new ArrayList<Request>();
		ArrayList<Request> store = new ArrayList<Request>();
		
		
		SortStuff Compare = new SortStuff();
		
		for(long req = 0; req < N; req++) {
			st = new StringTokenizer(sc.readLine());
			long inTime = Long.parseLong(st.nextToken());
			String type = st.nextToken();
			long time_needed = Long.parseLong(st.nextToken());
			if(type.equals("R")) {
				R++;
				rem.add(new Request(inTime, time_needed));
			}
			else {
				store.add(new Request(inTime, time_needed));
			}
		}

		rem.add(new Request(Integer.MAX_VALUE, Integer.MAX_VALUE));
		store.add(new Request(Integer.MAX_VALUE, Integer.MAX_VALUE));
		
		Collections.sort(rem, Compare);
		Collections.sort(store, Compare);
		
		name: while(!((rem.size() <= 1 && store.size() <= 1))) {
			long min = min(techs);
			if(store.size() >= 1 && store.get(0).in_time <= min) {
				Request s = store.get(0);
				store.remove(0);
				stime += (min + s.needed) - s.in_time;
				for(long i = 0; i < T; i++) {
					if(techs[(int)i] == min) {
						techs[(int)i] += s.needed;
						continue name;
					}
				}
			}
			else if(rem.size() >= 1 && rem.get(0).in_time <= min){
				Request r = rem.get(0);
				rem.remove(0);
				rtime += (min + r.needed) - r.in_time;
				for(long i = 0; i < T; i++) {
					if(techs[(int)i] == min) {
						techs[(int)i] += r.needed;
						continue name;
					}
				}
			}
			else {
				min = Math.min((store.size() == 0 ? Integer.MAX_VALUE : store.get(0).in_time), (rem.size() == 0 ? Integer.MAX_VALUE : rem.get(0).in_time));
				for(long i = 0; i < T; i++) {
					techs[(int)i] = Math.max(techs[(int)i], min);
				}
				continue name;
			}
			
		}
		
		double rdouble = (double)rtime/R;
		double sdouble = (double)stime/(N-R);
		
		if(N == 0) {
			System.out.println("0 0");
		}
		else if(R == 0) {
			System.out.printf("%.8f 0\n", sdouble);
		}
		else if(R == N) {
			System.out.printf("0 %.8f\n", rdouble);
		}
		else {
			System.out.printf("%.8f %.8f\n", sdouble, rdouble);
		}
		
	}
	
	public static long min(long[] techs) {
		long ans = Integer.MAX_VALUE;
		for(long i = 0; i < techs.length; i++) {
			ans = Math.min(ans, techs[(int)i]);
		}
		return ans;
	}

}

class Request{
	long orig_time;
	long in_time, needed, value;
	public Request() {
		in_time = needed = 0;
	}
	
	public Request(long i1, long i3) {
		in_time = i1;
		needed = i3;
		value = needed;
		orig_time = in_time;
	}
	
	public long value() {
		return value;
	}
	
	public String toString() {
		String ans = "";
		ans += in_time + " ";
		ans += needed;
		return ans;
	}
}

class SortStuff implements Comparator<Request> {
	public int compare(Request a, Request b) {
		if(a.in_time != b.in_time) {
			return (int)a.in_time - (int)b.in_time;
		}
		return ((int)a.needed - (int)b.needed);
	}
}
