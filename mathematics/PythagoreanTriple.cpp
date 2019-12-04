#include <bits/stdc++.h>
using namespace std;

//https://www.friesian.com/pythag.htm
/*
    Every odd number is the a side of a Pythagorean triplet. 
    The b side of a Pythagorean triplet is simply b = (a^2 - 1) / 2.                     
    The c side is b + 1. 

    Every even number is the a side of a Pythagorean triplet.
    The b side of such a Pythagorean triplet is simply (a/2)^2 - 1.
    The c side is b + 2. 
*/
int main()
{
    unsigned long long a,b,c;
    cin >> a;
    if(a % 2 == 0){
        b = (a/2) * (a/2) - 1;
        c = b + 2;
    }
    else {
        b = (a*a-1)/2;
        c = b + 1;
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}
//https://www.hackerrank.com/challenges/pythagorean-triple/problem