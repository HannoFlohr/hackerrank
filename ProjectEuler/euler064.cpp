#include<bits/stdc++.h>
using namespace std;

//https://en.wikipedia.org/wiki/Continued_fraction
//https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Continued_fraction_expansion
int findPeriodLength(int i) {
    int root = sqrt(i);
    
    //perfect square -> no period
    if(root*root==i)
        return 0;
        
    //integer part of sqrt(x)
    int a = root;
    int numerator = 0;
    int denominator = 1;
    int period = 0;
    
    //https://en.wikipedia.org/wiki/Continued_fraction#Other continued fraction expansions
    //loop is found when a == 2*root
    while (a != 2*root) {
        numerator = denominator * a - numerator;
        denominator = (i - numerator * numerator) / denominator;
        a = (root + numerator) / denominator;
        period++;
    }
    
    return period;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, p;
    cin >> n;
       
    int odd = 0; 
    
    for(int i=2; i<=n; i++) {
        p = findPeriodLength(i);
        
        if(p%2==1)
            odd++;
    } 
    
    cout << odd << endl;
    
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler064/problem