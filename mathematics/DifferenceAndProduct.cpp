#include <bits/stdc++.h>
using namespace std;

/*
if (x,y) is solution, (y,x) (-x,-y) (-y,-x) as well
-> search solutions for x>y
->  x-y = D
    x*y = P
->  x^2 - Dx - P = 0
    x = (D +- sqrt(D^2 + 4P)) / 2
*/

int solve(int d, int p) {
    //absolut difference cant be less than zero
    if(d<0) return 0;
    //product zero & abs not zero -> (0,d) (d,0) (0,-d) (-d,0)
    if(p==0 && d!=0) return 4;
    if(p==0 && d==0) return 1;

    int result = 0;
    //loop through potential x beginning at sqrt(P)
    for(int i=(int)sqrt(abs(p)); i>=1; i--) {
        //check if i is divisor of p
        //p=x*i d=x-i -> d=(p/i)-i 
        if(p%i == 0 && abs((p/i) - i) == d) {
            //2 solutions if x=y, 4 otherwise
            result = (abs(p/i)==i ? 2 : 4);
            break;
        } 
    }
    return result;
}

int main()
{
    int t, d, p;
    cin >> t;
    while(t--) {
        cin >> d >> p;
        cout << solve(d,p) << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/difference-and-product/problem