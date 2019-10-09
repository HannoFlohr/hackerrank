import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        scan.close();
        // Write your code here.

        String token = "";
        List tokens = new ArrayList();
        for(int i=0; i<s.length(); i++) {
            int c = s.charAt(i); 
            if( (c>=65 && c<=90) || (c>=97 && c<=122) )
                token += s.charAt(i);
            else {
                if(token != "")
                    tokens.add(token);
                token = "";
            }
        }
        if(token != "") tokens.add(token);

        System.out.println(tokens.size());
        for(Object t : tokens)
            System.out.println(t);
    }
}

