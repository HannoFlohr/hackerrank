import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int d, q, x, y, n = scan.nextInt();
        
        //set array list
        ArrayList[] a = new ArrayList[n];
        for(int i=0; i<n; i++) {
            d = scan.nextInt();
            a[i] = new ArrayList();
            for(int j=0; j<d; j++) 
                a[i].add(scan.nextInt());
        }

        //check all queries
        q = scan.nextInt();
        for(int i=0; i<q; i++) {
            x = scan.nextInt();
            y = scan.nextInt();
            try {
                System.out.println(a[x-1].get(y-1));
            } catch(Exception e) {
                System.out.println("ERROR!");
            }
        }
        scan.close();
    }
}

//https://www.hackerrank.com/challenges/java-arraylist/problem