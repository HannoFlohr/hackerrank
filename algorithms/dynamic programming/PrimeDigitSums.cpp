#include<bits/stdc++.h>
using namespace std;

const unsigned MOD = 1e9+7;
const unsigned MAXN = 4*1e5;

//max_sum for 5 digits = 45
//only primes up to relevant -> 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43
// for 3 digit sums only the first 9 primes are relevant
// for 4 digits 11 and for 5 all 14 
const vector<unsigned> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
vector<bool> isPrime (45+1, 0);

int main() {
    //time_t start = clock();
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    //initialize isPrime
    for(auto p:primes)
        isPrime[p] = true;
          
    //used to count how often each number is used to form a prime sum
    vector<vector<unsigned>> count (2, vector<unsigned>(10001));
    //used to store the numbers that form correct prime sum
    vector<vector<unsigned>> valid_numbers (2, vector<unsigned>());
    unsigned step=0;
    //compute which numbers form correct sum for prime for length 3 and 4
    for(short j=1; j<10; j++)
        for(short k=0; k<10; k++) 
            for(short l=0; l<10; l++) 
                for(short m=0; m<10; m++) {
                    if(isPrime[j+k+l+m] && isPrime[j+k+l] && isPrime[k+l+m]) {
                        unsigned n = m + l*10 + k*100 + j*1000;
                        count[step][n]++;
                        valid_numbers[step].push_back(n);
                    }
                }  
    
    //setup dp vector with start values, then compute upto MAXN
    vector<unsigned> dp (MAXN+5);
    dp[1] = 9; 
    dp[2] = 90;
    dp[3] = 303; //3digit numbers having a prime sum
    dp[4] = valid_numbers[step].size(); //280
    
    unsigned digit1,digit2,digit3,digit4,n;
    for(unsigned i=5; i<=MAXN; i++) {
        dp[i] = 0;
        step = !step;
        for(unsigned j=0; j<10; j++){
            for(auto& k:valid_numbers[!step]) {
                digit1 = k%10;
                digit2 = (k/10) % 10;
                digit3 = (k/100) % 10;
                digit4 = (k/1000) % 10;
                if(isPrime[digit1+digit2+j] && isPrime[digit1+digit2+digit3+j] && isPrime[digit1+digit2+digit3+digit4+j]) {
                    n = k%1000 * 10 + j;
                    if(count[step][n] == 0)
                        valid_numbers[step].push_back(n);
                    count[step][n] =  (count[step][n] + count[!step][k]) % MOD;
                    dp[i] = (dp[i] + count[!step][k]) % MOD;
                }
            }
        }
        
        for(auto& i:valid_numbers[!step])
            count[!step][i] = 0;
        
        valid_numbers[!step].clear();
    }
        
    for(int i=1; i<=10; i++)cerr<<dp[i]<<" ";
    cerr<<endl;    
        
        
    unsigned t;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/prime-digit-sums/problem