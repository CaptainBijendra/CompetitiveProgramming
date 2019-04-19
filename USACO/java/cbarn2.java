/*
ID: akommul1
LANG: JAVA
PROB: cbarn2
*/

import java.io.*;
import java.util.*;

public class cbarn2 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("cbarn2.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cbarn2.out")));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int infinity = 1000000000, ans = infinity;
        
        int[][] DP = new int[K + 1][N];
        int[] barn = new int[N];
        int[] cp = new int[N];

        for (int i = 0; i < N; i ++) { barn[i] = Integer.parseInt(br.readLine()); }
        
        for (int rotate = 0; rotate < N; rotate ++) {
            for (int i = 0; i <= K; i ++) {
                for (int j = 0; j < N; j ++) { DP[i][j] = infinity; }
            }
            
            DP[0][N - 1] = 0;
            
            for (int k = 1; k <= K; k ++) { 
                for (int i = 0; i < N; i ++) {
                    int sum = 0;
                    
                    for (int j = i + 1; j < N; j ++) {
                        sum += (barn[j - 1]) * (j - i + 1);
                        DP[k][i] = Math.min(DP[k][i], DP[k - 1][j] + sum);
                    }
                }
            }
            
            for (int i = 0; i <= K; i ++) {
                for (int j = 0; j < N; j ++) { System.out.println(i + " " + j + " " + DP[i][j]); }
            }
            
            ans = Math.min(ans, DP[K][0]);
            cp[0] = barn[N - 1];
            
            for (int i = 1; i < N - 1; i ++) { cp[i + 1] = barn[i]; }
            for (int i = 0; i < N; i ++) { barn[i] = cp[i]; }
        }
        
        out.println(ans);
        out.close();
    }
}
