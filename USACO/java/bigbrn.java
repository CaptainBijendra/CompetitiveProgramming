/*
ID: akommul1
LANG: JAVA
PROB: bigbrn
*/

import java.io.*;
import java.util.*;

public class bigbrn {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("bigbrn.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("bigbrn.out")));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());
        int ans = 0;
        
        boolean[][] graph = new boolean[N][N];
        int[][] DP = new int[N][N];
        
        for (int i = 0; i < T; i ++) {
            st = new StringTokenizer(br.readLine());
            graph[Integer.parseInt(st.nextToken()) - 1][Integer.parseInt(st.nextToken()) - 1] = true;
        }

        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j ++) {
                DP[i][j] = 1;
            } 
        }

        for (int i = N - 1; i >= 0; i --) {
            for (int j = N - 1; j >= 0; j --) {
                if (i == N - 1 || j == N - 1) {
                    continue;    
                }

                else if (!graph[i][j]) {
                    boolean flag = true;
                    int x = 0;
                    int y = 0;

                    for (int k = j; k < j + DP[i + 1][j + 1] + 1; k ++) {
                        if (graph[i][k]) { flag = false; break; }
                        x ++;
                    }

                    for (int l = i; l < i + DP[i + 1][j + 1] + 1; l ++) { 
                        if (graph[l][j]) { flag = false; break; }
                        y ++;
                    }

                    if (flag) { 
                        if (!graph[i + 1][j + 1]) { DP[i][j] = DP[i + 1][j + 1] + 1; } 
                    } 
                    
                    else {
                        DP[i][j] = Math.min(x, y);
                    }
                }
            }
        }

        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j ++) {
                ans = Math.max(ans, DP[i][j]);
            } 
        }

        out.println(ans);
        out.close();
    }
}
