public class Prob1 {
    public static void main(String args[]) {
        int multiples3 = 0;
        int multiples5 = 0;
        int multiples15 = 0;
        
        for (int i = 1; i < 1000; i ++) {
            if (i % 3 == 0)
                multiples3 += i;
            if (i % 5 == 0)
                multiples5 += i;
            if (i % 15 == 0)
                multiples15 += i;
        }
        
        System.out.println(multiples3 + multiples5 - multiples15);
    }
}