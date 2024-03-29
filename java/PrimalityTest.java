import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String n = scanner.nextLine();
        scanner.close();

        BigInteger input = new BigInteger(n);
        if(input.isProbablePrime(1))
            System.out.println("prime");
        else
            System.out.println("not prime");
    }
}

//https://www.hackerrank.com/challenges/java-primality-test/problem