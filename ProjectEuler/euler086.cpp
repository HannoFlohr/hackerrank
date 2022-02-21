#include<bits/stdc++.h>
using namespace std;

const unsigned MAXM = 1000000;

unsigned long long combinations(unsigned long long a, unsigned long long bc) {
    if(2*a < bc) return 0; //ensure a is longest side

    if(a>=bc) 
        return bc/2;
    return a - (bc-1)/2; 
}

//use euclids formula to find basic triplets (compare problem 75)
vector<unsigned long long> findCombinations() {
    vector<unsigned long long> valid_combinations (MAXM+1,0);
    unsigned long long a, b, c;
    for(unsigned int m=1; m<=sqrt(2*MAXM); m++) 
        for(unsigned int n=1; n<m; n++) {
            if((m+n)%2 != 1 || __gcd(m,n) != 1)
                continue;
                
            a = (m*m) - (n*n);
            b = 2*m*n;
            
            //include multiples
            for(unsigned long long k=1; k*a<=MAXM; k++)
                valid_combinations[k*a] += combinations(k*a, k*b);
            for(unsigned long long k=1; k*b<=MAXM; k++)
                valid_combinations[k*b] += combinations(k*b, k*a); 
        }
        
    return valid_combinations;
}

/*
https://oeis.org/A143715
https://en.wikipedia.org/wiki/Pythagorean_triple

Need to find all integer solutions for M = sqrt(a^2+(b+c)^2) , with a>=b>=c;
Use the code for problem 75 for euclids formula to find all basic triplets 
and than check the multiples:
- if a is greater than b+c
    need to find combinations b+c, with b>=c, that produce valid cuboids
    e.g. b+c=5: (4,1)(3,2) -> 2 combinations = (int)5/2
         b+c=6: (5,1)(4,2)(3,3) -> 3 combinations = 6/2
         b+c=7: (6,1)(5,2)(4,3) -> 3 combinations = (int)7/2
         -> (b+c)/2 combinations
- if a is less than b+c: a still needs to be greater or equal than each b and c (and b>=c)
    need to exclude combinations where b would be greater 
    e.g. a=5 b+c=7: (5,5,2)(5,4,3) valid triplets; (5,6,1) not 
    -> a >= b >= (b+c)/2 
    combinations a >= b = c are valid
    -> a - (b+c-1)/2 combinations

*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    vector<unsigned long long> valid_combinations = findCombinations();
    vector<unsigned long long> sum_combinations;
    unsigned long long sum = 0;
    for(auto v:valid_combinations) {
        sum += v;
        sum_combinations.push_back(sum);
    }
    
    int t, m;
    cin >> t;
    while(t--) {
        cin >> m;
        cout << sum_combinations[m] << endl;
    }
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler086/problem