import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();

        BitSet B1 = new BitSet(n);
        BitSet B2 = new BitSet(n);

        String s;
        int x, y;
        while(m-- > 0) {
            s = in.next();
            x = in.nextInt();
            y = in.nextInt();
            
            if(s.equals("AND")) {
                if(x==1) B1.and(B2);
                else B2.and(B1);

            }
            else if(s.equals("OR")) {
                if(x==1) B1.or(B2);
                else B2.or(B1);
            }
            else if(s.equals("XOR")) {
                if(x==1) B1.xor(B2);
                else B2.xor(B1);
            }
            else if(s.equals("FLIP")) {
                if(x==1) B1.flip(y);
                else B2.flip(y);
            }
            else if(s.equals("SET")) {
                if(x==1) B1.set(y);
                else B2.set(y);
            }
            else 
                System.out.println("Error, wrong input: " + s); 

            System.out.println(B1.cardinality() + " " + B2.cardinality());
        }
    }
}

//https://www.hackerrank.com/challenges/java-bitset/problem