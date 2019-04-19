/*
ID: akommul1
LANG: JAVA
PROB: tallbarn
*/

import java.io.*;
import java.util.*;

public class tallbarn {
    static double benefit (double c, double a) { return ((a / c) - (a / (c + 1))); }
    
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("tallbarn.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("tallbarn.out")));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        
        int cLeft = K - N, in = 0;
        double max = 0d, time = 0d;
        
        double[] barn = new double[N];
        double[] cows = new double[N];
        
        for (int i = 0; i < N; i ++) { barn[i] = Double.parseDouble(br.readLine()); cows[i] = 1d; }
        
        while (cLeft != 0) {
            for (int i = 0; i < N; i ++) {
                if (benefit(cows[i], barn[i]) > max) { 
                    max = benefit(cows[i], barn[i]); 
                    in = i;
                }
            }
            
            cows[in] ++;
            cLeft --;
            max = 0d;
        }
        
        for (int i = 0; i < N; i ++) { time += barn[i] / cows[i]; }
        
        out.println((int) Math.round(time));
        out.close();
    }
}