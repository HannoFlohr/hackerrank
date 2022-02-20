#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000000;

/* https://en.wikipedia.org/wiki/Pythagorean_triple
a^2 + b^2 = c^2
Euclids formula gives:
a = m^2-n^2; b = 2mn; c=m^2+n^2 (m>n>0, (m+n)%2==1 and gcd(m,n)=1)

(1) we can precompute the valid combinations
by first computing the base value pairsa b c
the multiples of these can be optained by multiplying 
a b c by an integer>1 until the limit is reached
(2) extract results with exactly one combination
(3) look up result for each test case
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<unsigned int> valid_combinations (MAXN,0);
    unsigned int a, b, c, sum ;
    for(unsigned int m=2; m<=sqrt(MAXN); m++) 
        for(unsigned int n=1; n<m; n++) {
            if((m+n)%2 != 1 || __gcd(m,n) != 1)
                continue;
                
            a = (m*m) - (n*n);
            b = 2*m*n;
            c = (m*m) + (n*n);
            sum = a + b + c;
            
            //include multiples
            a = 1;
            while(a*sum < MAXN) 
                valid_combinations[a++ * sum]++; 
        }
    
    vector<unsigned int> one_valid_result;
    for(unsigned int i=0; i<valid_combinations.size(); i++)
        if(valid_combinations[i] == 1)
            one_valid_result.push_back(i);

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        auto pos_leq_n = upper_bound(one_valid_result.begin(), one_valid_result.end(), n);
        cout << distance(one_valid_result.begin(), pos_leq_n) << endl;
    }
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler075/problem