/*
ID: akommul1
LANG: JAVA
PROB: theme
*/

import java.io.*;
import java.util.*;

public class theme {
    public static void main (String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("theme.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("theme.out")));
        
        int N = Integer.parseInt(br.readLine());
        int c = 0, ans = 0;

        int[][] DP = new int[N][N];
        int[] notes = new int[N];

        while (c < N) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for ( ; st.hasMoreTokens() ; c ++) { notes[c] = Integer.parseInt(st.nextToken()); }
        }
        
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j ++) {
                DP[i][j] = 1;
            }
        }

        for (int i = N - 2; i >= 0; i --) {
            for (int j = i - 2; j >= 0; j --) {
                if (notes[i] - notes[j] == notes[i + 1] - notes[j + 1]) {
                    DP[i][j] = Math.max(DP[i + 1][j + 1] + 1, DP[i][j]);
                    ans = Math.max(DP[i][j], ans);
                } 

                else {
                    DP[i][j] = 1;
                }
            }
        }

        if (ans < 5) { out.println(0); }
        else { out.println(ans); }

        out.close();
    }   
}
