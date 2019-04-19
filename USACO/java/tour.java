/*
ID: akommul1
LANG: JAVA
PROB: tour
*/

import java.io.*;
import java.util.*;

public class tour {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("tour.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("tour.out")));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int V = Integer.parseInt(st.nextToken());
        int infinity = 100000000;

        int[][] DP = new int[N][N];
        boolean[][] con = new boolean[N][N];
        boolean[] vis = new boolean[N];

        HashMap<String, Integer> city = new HashMap<String, Integer>();

        for (int i = 0; i < N; i ++) { city.put(br.readLine(), i); }
        for (int i = 0; i < V; i ++) {
            st = new StringTokenizer(br.readLine());

            int a = city.get(st.nextToken());
            int b = city.get(st.nextToken());
            
            con[a][b] = con[b][a] = true;
        }
        
        for (int i = 0; i < N; i ++) { 
            for (int j = 0; j < N; j ++) { DP[i][j] = infinity; } 
            con[i][i] = true;
        }

        DP[0][0] = 1;

        for (int k = 0; k < N; k ++) {
            for (int i = 0; i < N; i ++) {
                for (int j = 0; j < N; j ++) {
                    if (con[k][i] && con[i][j] && !vis[j]) {
                        DP[k][j] = Math.min(DP[k][j], DP[k][i] + 1);
                        DP[j][k] = DP[k][j];
                    } 
                }
            }
        }

        for (int i = 0; i < N; i ++) { 
            if (DP[)
        }
    }
}
