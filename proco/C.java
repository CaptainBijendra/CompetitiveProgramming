import java.io.*;
import java.util.*;

public class C {
    public static void main(String[] args) throws Exception{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        
        int q = Integer.parseInt(f.readLine());
        
        

        for(int ii = 0; ii < q; ii ++){
            long c = Long.parseLong(f.readLine());
            
            ArrayList<Pair> tm = getPrimeFactorization(c);
            
            for(int i = 0; i < tm.size(); i ++){
                Pair p = tm.get(i);
                int exp = p.count;
                
                int ax = exp;
                int bx = exp;
                
                int min = exp/3;
                ax -= min*2;
                bx -= min * 3;
                
                for(int j = 0; j < ax; j ++){
                    a *= p.x;
                }
                
                for(int j = 0; j < bx; j ++){
                    b *= p.x;
                }
            }
            
            if(a == b){
                System.out.println(a*4 + " " + b*8);
            }
            else{
                System.out.println(a + " " + b);
            }
        }
        
        
    }
    
    static ArrayList<Pair> getPrimeFactorization(long c){
        ArrayList<Pair> tm = new ArrayList<Pair>();
        for(int i = 2; i <= Math.sqrt(c); i ++){
            int count = 0;
            while(c % i == 0){
                count ++;
                c/= i;
            }
            
            tm.add(new Pair(i,count));
        }
        
        if(c != 1){
            tm.add(new Pair(c,1));
        }
        
        return tm;
    }
    
    static class Pair{
        long x;
        int count;
        Pair(long x, int count){
            this.x = x;
            this.count = count;
        }
    }
}