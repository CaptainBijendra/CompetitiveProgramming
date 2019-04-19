/*
ID: akommul1
LANG: JAVA
PROB: window
*/

import java.io.*;
import java.util.*;
import java.text.*;

class w {
    int x, y, x2, y2;
    w (int a, int b, int c, int d) { 
        x = a; y = b;
        x2 = c; y2 = d;
    }
}

public class window {
    static ArrayList<w> order;
    static ArrayList<Character> index;
    
    static double calcArea() {
        return (1.9999d);
    }
    
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("window.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("window.out")));
        String tmp = br.readLine();

        int c = 0;

        order = new ArrayList<w>();
        index = new ArrayList<Character>();

//      Order: Bottom at beginning, Top at end

        while (tmp != null) {
            char f = tmp.charAt(0);
            String[] func = tmp.split(",(?=([^\"]|\"[^\"]*\")*$)");

            if (f == 'w') {
                order.add(new w(Integer.parseInt(func[1]), Integer.parseInt(func[2]), Integer.parseInt(func[3]), Integer.parseInt(func[4].substring(0, func[4].length() - 1))));
                index.add(tmp.charAt(2));
            }

            else {
                if (f == 'd') { 
                    order.remove(index.indexOf(tmp.charAt(2)));
                    index.remove(index.indexOf(tmp.charAt(2)));
                }
                
                else if (f == 't' || f == 'b') { 
                    w s = order.get(index.indexOf(tmp.charAt(2)));
                    order.remove(index.indexOf(tmp.charAt(2)));
                    index.remove(index.indexOf(tmp.charAt(2)));
                    
                    if (f == 't') {
                        order.add(s);
                        index.add(tmp.charAt(2));
                    }
                    
                    else {
                        order.add(0, s);
                        index.add(0, tmp.charAt(2));
                    }
                }
                
                else {
                    double ar = calcArea();
                    DecimalFormat df = new DecimalFormat("####0.000");
                    out.println(df.format(ar));
                }
            }
/*
            for (w el : order) {
                System.out.println(el.x + " " + el.y + " " + el.x2 + " " + el.y2);
            }

            System.out.println("=================================================================================================");
*/
            tmp = br.readLine();
        }
        
        out.close();
    }
}
