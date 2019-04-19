import java.io.*;
import java.util.*;

public class Lifeguards {
    public static void main(String args[]) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("lifeguards.in"));
        PrintWriter printer = new PrintWriter(new BufferedWriter(new FileWriter("lifeguards.out")));
        
        int N = Integer.parseInt(reader.readLine());
        
        int[] left = new int[N + 5];
        int[] right = new int[N + 5];
            
        for (int i = 0; i < N; i ++) {
            StringTokenizer st = new StringTokenizer(reader.readLine());
            left[i] = Integer.parseInt(st.nextToken());
            right[i] = Integer.parseInt(st.nextToken());
        }
        
        boolean[] used = new boolean[1005];
        int max = 0;
        
        for (int i = 0; i < N; i ++) { //Choosing which interval to remove
            for (int j = 0; j < N; j ++) { //Going through the rest of the intervals
                if (i == j) {
                    continue;
                }    
                
                for (int k = left[j]; k < right[j]; k ++)
                    used[k] = true;
            }
            
            int counter = 0;
            
            for (int l = 0; l < 1005; l ++) {
                if (used[l] == true)
                    counter ++;
            }
            
            max = Math.max(max, counter);
        
            for (int m = 0; m < 1005; m ++) {
                used[m] = false;
            }
        }
        
        printer.println(max);
        printer.close();
    }
}