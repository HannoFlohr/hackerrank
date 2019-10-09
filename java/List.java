import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        List a = new ArrayList();
        for(int i=0; i<n; i++) 
            a.add(in.nextInt());

        int x, y, q = in.nextInt();
        for(int query=0; query<q; query++) {
            in.nextLine();
            String s = in.nextLine(); 
            if(s.equals("Insert")) {
                x = in.nextInt();
                y = in.nextInt();
                a.add(x, y);
            }
            else if(s.equals("Delete")) {
                x = in.nextInt();
                if(x < a.size())
                    a.remove(x);
            }
            else 
                System.err.println("Wrong input: " + s);
        }
        in.close();

        for(int i=0; i<a.size(); i++)
            System.out.print(a.get(i) + " ");
    }
}

//https://www.hackerrank.com/challenges/java-list/problem