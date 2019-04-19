/*
ID: akommul1
LANG: JAVA
PROB: hps
*/

import java.io.*;
import java.util.*;

public class hps {
    public static void main(String args[]) {
        BufferedReader br = new BufferedReader(new FileReader("hps.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("hps.out")));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        
        int[][][] DP = new int[N][K][3];
        int[] moves = new int[N];
        
        for (int i = 0; i < N; i ++) { moves[i] = Integer.parseInt(br.readLine()); }
        
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < K; j ++) {
                
            }
        }
    }
}