#include<bits/stdc++.h>
using namespace std;

const unsigned int MOD = 1e9+7;
const unsigned int MAXN = 60000;

/* https://en.wikipedia.org/wiki/Pentagonal_number_theorem

result(i) = partitions[+1] + partitions[-1]
            - partitions[+2] - partitions[-2] 
            + partitions[+3] + partitions[-3]
            - partitions[+4] - partitions[-4]
            ...
precompute for all n<=MAXN
(1) compute alternating incrementing number 1,-1,2,-2,3,...
(2) compute the offset g_i = (3i^2 - i) / 2 = i * (3i-1)            
(3) sum up the results for [n-offset] as described above
(4) save result for current partition

test cases: look up results
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    vector<unsigned long long> partitions;
    partitions.push_back(1);
    int number, index;
    for(unsigned int n=1; n<=MAXN; n++) {
        long long result = 0;
        for(unsigned int i=0; i<n; i++) {
            number = 1 + (i/2);
            if(i%2==1) number = -number;
            
            index = number * (3 * number - 1) / 2; 
            if(index > n) //check for bounds
                break;
                
            //alternate between adding and subtracting two terms
            if(i%4 < 2)
                result += partitions[n - index];
            else
                result -= partitions[n - index];
                
            result %= MOD;
        }
        
        if(result < 0)
            result += MOD;
            
        partitions.push_back(result);
    }
    
    unsigned int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << partitions[n] << endl;
    }
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler078/problem