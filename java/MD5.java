import java.io.*;
import java.util.*;
import java.security.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        in.close();

        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            md.update(s.getBytes());
            byte[] md5 = md.digest();

            for(byte m : md5) 
                System.out.printf("%02x", m);

        } catch(Exception e) {
            System.out.println(e);
        }
    }
}

//https://www.hackerrank.com/challenges/java-md5/problem