#include<bits/stdc++.h>
using namespace std;

/*
resulting number will be (4*k[i] * 10^i) with each k[i] = 1 or 0 (e.g. 44404404)

2*2*k[i] * (2*5)^i

remove all factors 2 and 5 and count them (count2/count5)

occurrences of '0' in final number: b = max of count2 - 2 and count5, two '2's are needed to multiply the k[i] by 4

to count the occurrences of '1' (a) we start with a number=1 (as the final number needs to start with a 4)
we then keep shifting the number left and increment a for each shift until the number is divisible by x without remainder
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, x, number, a, b, count2, count5;
    cin >> t;
    while(t--) {
        cin >> x;
        
        //remove factors 2 and 5 from input number x to get a number coprime with 10
        count2 = count5 = 0;
        while(x%2 == 0) {
            x /= 2;
            count2++;
        }
        while(x%5 == 0) {
            x /= 5;
            count5++;
        }
        
        b = max(count2 - 2, count5);
        
        a = number = 1;
        while(number%x) {
            number = (number*10+1) % x;
            a++;
        }
        cout << (2*a+b) << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/easy-math/problem