#include <bits/stdc++.h>
using namespace std;

/*
state       steps   comment
d==0        0       
a||b==d     1       1 step with distance a or b
a>d || b>d  2       isosceles triangle; 2 legs of length a or b over base d
a+b>d       2       triangle
r==0        n       n=d/b; r=d%b and straight line if r==0
r!=0        n+1     triangle of 1 side n*b, other side a or b -> n+1 steps
*/
int steps(int a, int b, int d) {
    if(d==0) return 0;
    else if(a==d || b==d) return 1;
    else if((d-b)%b==0) return (d-b)/b+1;
    else return (d-b)/b+2;
}

int main()
{
    int q;
    int a, b, d;
    cin >> q;
    while(q--) {
        cin >> a >> b >> d;
        cout << steps(a,b,d) << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/baby-step-giant-step/problem