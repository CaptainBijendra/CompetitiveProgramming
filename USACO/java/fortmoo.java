/*
ID: akommul1
PROB: fortmoo
LANG: JAVA
*/

import java.io.*;
import java.util.*;

public class fortmoo {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("fortmoo.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("fortmoo.out")));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[][] DP = new int[N + 1][M + 1];
        
        boolean[][] swmp = new boolean[N + 1][M + 1];

        for (int i = 0; i < N; i ++) {
            String ln = br.readLine();
            for (int j = 0; j < M; j ++) { swmp[i][j] = (ln.charAt(j) == '.' ? false : true); }
        }

        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j ++) {
                DP[i + 1][j + 1] = DP[i + 1][j] + DP[i][j + 1] - DP[i][j];

                if (swmp[i][j]) {
                    DP[i + 1][j + 1] ++;
                }
            }
        }

        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j ++) {
                System.out.println(i + " " + j + " " + DP[i][j]);
            }
        }

        for (int j = 0; j < M; j ++) {
            for (int k = j + 1; k < M; k ++) {
                for (int i = 0; i < N; i ++) {
                    
                }
            }
        }
    }
}