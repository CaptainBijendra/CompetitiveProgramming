public class Prob3 {
    public static void main(String args[]) {
        long N = 600851475143l;
        int ans = 0;
        
        for (int i = 2; i <= Math.sqrt(N); i ++) {
            if (N % i == 0)
                ans = Math.max(ans, i);
            
            while (N % i == 0)
                N /= i;
        }
       
        System.out.println(N);
    }
}