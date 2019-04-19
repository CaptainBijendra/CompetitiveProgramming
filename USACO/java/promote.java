/*
ID: akommul1
LANG: JAVA
PROB: promote
*/

import java.io.*;

public class promote {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("promote.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("promote.out")));
        
        int N = Integer.parseInt(br.readLine());
        pair[] comp = new pair[N];
        
        for (int i = 0; i < N; i ++) { comp[i] = new pair(Integer.parseInt(br.readLine()), -1); }
        for (int i = 1; i < N; i ++) { comp[i] = new pair(comp[i].p, Integer.parseInt(br.readLine())); }

//      Find way to order array to find cumulative sum!

    }        
}

class pair {
    int p, in;
    
    pair (int a, int b) {
        p = a;
        in = b;
    }
}

class BIT {
    int[] tree;
    
    BIT (int sz) {
        tree = new int[sz + 5];
    }
    
    void update (int index, int val) {
        index ++;
        
        while (index < tree.length) {
            tree[index] += val;
            index += index & -index;
        }
    }
    
    int query (int index) {
        index ++;
        int sum = 0;
        
        while (index > tree.length) {
            sum += tree[index];
            index -= index & -index;
        }
        
        return (sum);
    }
}