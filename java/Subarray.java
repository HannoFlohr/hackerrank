import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] a = new int[n];
        for(int i=0; i<n; i++)
            a[i] = scan.nextInt();
        scan.close();

        int curSum, negativeSubarrays = 0;
        for(int i=0; i<n; i++) {
            curSum = a[i];
            if(curSum < 0)
                negativeSubarrays++;

            for(int j=i+1; j<n; j++) {
                curSum += a[j];
                if(curSum < 0)
                    negativeSubarrays++;
            }
        }
        System.out.println(negativeSubarrays);
    }
}

//https://www.hackerrank.com/challenges/java-negative-subarray/problem