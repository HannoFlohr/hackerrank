#include<bits/stdc++.h>
using namespace std;

//const unsigned MAXN = 200000;
vector<unsigned> min_k_values;

//check if a better result with k factors/summands was found
bool validResult(const unsigned& n, const unsigned& k) {
    if(k>=min_k_values.size()) //too many factors -> invalid
        return false;
    
    if(min_k_values[k] > n) {
        min_k_values[k] = n;
        return true;
    }
    return false;
}

unsigned find_k_values(const unsigned& n, unsigned sum, unsigned prod, unsigned k=1, unsigned factorsStart=2) {
    //if the product is already 1, but the sum isn't, we can add additional 1's to the sum to get a result
    //check if that is a valid/better result
    if(prod==1)
        return validResult(n, k+sum-1) ? 1 : 0;
    
    unsigned found_k_values = 0;
    if(k>1){
        if(sum == prod)
            return validResult(n,k) ? 1 : 0;
        
        if(validResult(n, k+sum-prod))
            found_k_values++;
    }
    
    //check remaining factors
    for(unsigned i=factorsStart; i*i<=prod; i++)
        if(prod%i == 0)
            found_k_values += find_k_values(n, sum-i, prod/i, k+1, i);
    
    return found_k_values;
}

/* https://oeis.org/A104173
    1, 4, 6, 8, 8, 12, 12, 12, 15, 16, 16, 16, 18, 20, 24, 24, 24, 24, 24, ...

recursive approach starting with number=4 :
- for all numbers up to MAXN try all divisors of the number
- remove these from sum and product (initial sum=number product=number)
- recursive call with reduced sum and product
- when we get to a proper result candidate: check if this is a new or better result for k

all results for k are saved in a vector
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unsigned n;
    cin >> n;
    
    min_k_values = vector<unsigned>(n+1, numeric_limits<unsigned>::max());
    min_k_values[0] = 0; min_k_values[1] = 1;
    
    //initial value for k(2) = 4 -> use as start value, then increment and search for results
    unsigned current_n = 4;
    unsigned result, sum = 0, k_not_found = n-1;
    while(k_not_found) {
        //check if new result are found for current k
        result = find_k_values(current_n, current_n, current_n);
        if(result > 0) {
            k_not_found -= result;
            sum += current_n;
        }
            
        current_n++;
    }

    cout << sum << endl;
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler088/problem