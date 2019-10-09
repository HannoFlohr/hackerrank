import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        BigInteger a = new BigInteger(s);
        s = scan.nextLine();
        scan.close();

        BigInteger b = new BigInteger(s);

        System.out.println(a.add(b));
        System.out.println(a.multiply(b));
    }
}

//https://www.hackerrank.com/challenges/java-biginteger/problem