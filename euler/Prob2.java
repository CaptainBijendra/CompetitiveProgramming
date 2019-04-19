public class Prob2 {
    public static void main(String args[]) {
        int fib1 = 1;
        int fib2 = 2;
        int sum = 0;
        
        while (fib1 <= 4000000) {
            if (fib1 % 2 == 0)
                sum += fib1;    
    
            int temporary = fib2;
            
            fib2 = fib1 + fib2;
            fib1 = temporary;
        }
        
        System.out.println(sum);
    }
}