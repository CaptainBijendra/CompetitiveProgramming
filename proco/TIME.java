class TIME {
    public static void main (String[] args) throws java.lang.Exception {
        int ans = 0;
        for (int input = 10000000; input < 97000000; input ++) {
    	    if (I(input) == 4 && 
                M(input) == 8 && 
                E(input) == 16 && 
                input % 2 == 1 && 
                T(input) == 12) {
                ans = (ans ^ input);
                System.out.println(input);
    	    } else {
        	    //System.out.println("we lost :(");
    	    }
        }
    
        System.out.println("ANS: " + ans);
    }

    public static int T(int num) {
        int x = 0;
        for (long i = 1; i <= Math.sqrt(num); i++) {
            for (long j = 1; j <= Math.sqrt(num); j ++) {
                if (i * i + j * j == num)
                    x ++;
            }
        }
        
        return x;
    }

    public static int I(int num) {
        int x = 0;
        for (; num > 0; num /= 10) {
            if (num % 10 == 0) {
                x++;
            }
        }
        return x;
    }

    public static int M(int num) {
        int x = 0;
        for (; num > 0; num /= 10) {
            x++;
        }
        return x;
    }

    public static int E(int num) {
        int x = 0;
        for (; num > 0; num /= 10) {
            x += num % 10;
        }
        return x;
    }
}