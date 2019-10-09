import java.io.*;
import java.util.*;
import java.security.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        in.close();

        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            md.update(s.getBytes());
            byte[] sha = md.digest();

            for(byte b : sha) 
                System.out.printf("%02x", b);

        } catch(Exception e) {
            System.out.println(e);
        }
    }
}

//https://www.hackerrank.com/challenges/sha-256/problem