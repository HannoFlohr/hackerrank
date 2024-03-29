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
        int[][] a = new int[6][6];
        for (int i = 0; i < 6; i++) {
            String[] arrRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 6; j++) {
                int arrItem = Integer.parseInt(arrRowItems[j]);
                a[i][j] = arrItem;
            }
        }
        scanner.close();

        int sum, maxSum = Integer.MIN_VALUE;
        for(int i=1; i<5; i++) 
            for(int j=1; j<5; j++) {
                sum = a[i-1][j-1] + a[i-1][j] + a[i-1][j+1] + a[i][j] + a[i+1][j-1] + a[i+1][j] + a[i+1][j+1];
                if(sum > maxSum)
                    maxSum = sum;
            }
        
        System.out.println(maxSum);
    }
}
//https://www.hackerrank.com/challenges/java-2d-array/problem