import java.math.BigInteger;
import java.util.Scanner;

//https://en.wikipedia.org/wiki/Lucas%27s_theorem
/*
    Given n, k, and prime p, binomial (n,k) is divisible by p if and only if at least one of  the base p digits of k is larger than the corresponding digit of m (also base p digit).

    n = abcdef...
    for each digit in k: 0 <= digit <= n_digit
    first: 0,1,2,...a-1
    second: 0,1,2,...b-1
    third: 0,1,2,...c-1
    and so on..

    so numbers that have all digits less than the corresponding digit in n are:
    (a+1)*(b+1)*(c+1)*... = R

    There are n+1 total numbers to check, therefore result is: n+1 - R
*/
public class Solution {
    static BigInteger solve(BigInteger n, BigInteger p) {
        BigInteger R = BigInteger.ONE;
        for(BigInteger i=n; !i.equals(BigInteger.ZERO); i=i.divide(p))
            R = R.multiply(i.mod(p).add(BigInteger.ONE));

        return n.add(BigInteger.ONE).subtract(R);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int i=0; i<t; i++) {
            BigInteger n = sc.nextBigInteger();
            BigInteger p = sc.nextBigInteger();
            System.out.println(solve(n,p));
        }
    }
}
