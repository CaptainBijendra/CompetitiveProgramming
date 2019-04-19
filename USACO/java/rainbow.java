import java.io.*;
import java.util.*;

public class rainbow {
	public static void main(String[] args) throws Exception{
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(f.readLine());
		String s = f.readLine();
		
		int ans = 0;
		ArrayList<Character> c = new ArrayList<Character>();
		for(int i = 0; i < s.length(); i ++) {
			if(i != 0 && s.charAt(i) == s.charAt(i-1)) {
				continue;
			}
			c.add(s.charAt(i));
		}
		
		ans = c.size();
		char[] a = new char[c.size()];
		char[] b = new char[c.size()];
		
		for(int i = 0; i < c.size();i++) {
			if(c.get(i) == 'r') {
				a[i] = 'r';
				b[i] = 'r';
				for(int j = i - 1; j >= 0; j --) {
					if(c.get(j) == 'r' || c.get(j) == 'o' || c.get(j) == 'p') {
						a[j] = 'r';
					}
					else   
					    break;
				}
				
				for(int j = i+1; j < c.size(); j ++) {
					if(c.get(j) == 'r' || c.get(j) == 'o' || c.get(j) == 'p') {
						b[j] = 'r';
					}
                    else
                        break;
				}
			}
			else if(c.get(i) == 'y') {
				a[i] = 'y';
				b[i] = 'y';
				for(int j = i - 1; j >= 0; j --) {
					if(c.get(j) == 'y' || c.get(j) == 'o' || c.get(j) == 'g') {
						a[j] = 'y';
					}
					else    
					    break;
				}
				
				for(int j = i+1; j < c.size(); j ++) {
					if(c.get(j) == 'y' || c.get(j) == 'o' || c.get(j) == 'g') {
						b[j] = 'y';
					}
					else   
					    break;
				}
			}
			else if(c.get(i) == 'b') {
				a[i] = 'b';
				b[i] = 'b';
				for(int j = i - 1; j >= 0; j --) {
					if(c.get(j) == 'b' || c.get(j) == 'g' || c.get(j) == 'p') {
						a[j] = 'b';
					}
					else   
					    break;
				}
				
				for(int j = i+1; j < c.size(); j ++) {
					if(c.get(j) == 'b' || c.get(j) == 'g' || c.get(j) == 'p') {
						b[j] = 'b';
					}
					else
					    break;
				}
			}
		}
		
		for(int i = 1; i < c.size() - 1; i ++ ) {
			if(c.get(i) == 'o') {
				if(a[i] == 'r' && b[i] == 'y') ans --;
				if(a[i] == 'y' && b[i] == 'r') ans --;
			}
			
			if(c.get(i) == 'g') {
				if(a[i] == 'b' && b[i] == 'y') ans --;
				if(a[i] == 'y' && b[i] == 'b') ans --;
			}
			
			if(c.get(i) == 'p') {
				if(a[i] == 'r' && b[i] == 'b') ans --;
				if(a[i] == 'b' && b[i] == 'r') ans --;
			}
		}
		
		System.out.println(ans);
	}
}