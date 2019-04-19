import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class C {
    public static void main(String args[]) throws IOException {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        
        int T = in.nextInt();
        
        for (int i = 0; i < T; i ++) {
            in.nextInt();
            int P = in.nextInt();
            
            in.nextLine();
            
            BigInteger[] ar = new BigInteger[P + 1];
            BigInteger[] nxt = new BigInteger[P + 1];
            BigInteger[] sorted = new BigInteger[P + 1];
            BigInteger[] converted = new BigInteger[P + 1];
            
            StringTokenizer st = new StringTokenizer(in.nextLine());
            
            for (int j = 0; j < P; j ++)
                ar[j] = new BigInteger(st.nextToken());
        
            nxt[1] = ar[0].gcd(ar[1]);
            nxt[0] = ar[0].divide(nxt[1]);
            
            sorted[0] = nxt[0];
            sorted[1] = nxt[1];
            
            for (int j = 2; j < P; j ++) {
                nxt[j] = ar[j - 1].gcd(ar[j]);
                sorted[j] = nxt[j];
            }
            
            nxt[P] = ar[P - 1].divide(nxt[P - 1]);
            sorted[P] = nxt[P];
            
            Arrays.sort(sorted);
            converted[0] = sorted[0];
            
            int cnt = 1;
            
            for (int j = 1; j <= P; j ++) {
                if (sorted[j].equals(sorted[j - 1]))
                    continue;
                
                converted[cnt] = sorted[j];
                cnt ++;
            }
            
            String str = "";
            
            for (int k = 0; k < 26; k ++)
                System.out.println(converted[k].intValue());
            
            for (int j = 0; j <= P; j ++) {
                for (int k = 0; k < 26; k ++)
                    if (converted[k].equals(nxt[j])) {
                        str += (char)('A' + k);
                        break;
                    }
            }
            
            System.out.println("Case #" + (i + 1) + ": " + str);
        }
    }
}