#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 1e9+7;
ll factorials [100];

ll powMod(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

/*
one team has to get to n=25 points, the other scores m points in that time 
	-> (n+m-1)! combinations
filtering out the identical arrangments between the n and m points we get:
	(n+m-1)! / (n!(m-1)!)  	combinations
	
using the modular inverse to compute the denominator part we get:
	(n+m-1) * pow(denominator, MOD-2)
to compute the possible combinations

in case of a>=24 && b>=24: 
	#(combinations for a=24 b=24) * 2^(min(a,b)-24)
*/
ll playGame(ll a, ll b) {
	//check for invalid results
    if( (a<25 && b<25 ) || abs(a-b)<2 )
        return 0;
        
    if(a>=24 && b>=24) {
		//check for invalid results 
        if(abs(a-b) != 2)
            return 0;
            
        ll lower = min(a,b);
        lower -= 24;
        
        ll base = (factorials[24] * factorials[24]) % MOD;
        ll result = (factorials[24+25-1] * powMod(base, MOD-2)) % MOD;
        result = (result * powMod(2,lower)) % MOD;
        return result;
    } 
    
    ll lower = (a>b) ? b : a;
    ll base = (factorials[lower] * factorials[25-1]) % MOD;
    ll result = (factorials[25+lower-1] * powMod(base,MOD-2)) % MOD;
    return result;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll a, b;
    cin >> a >> b;
    
    factorials[0] = 1;
    for(ll i=1; i<100; i++)
        factorials[i] = (factorials[i-1] * i) % MOD;
        
    cout << playGame(a,b) << endl;
    return 0;
}
//https://www.hackerrank.com/challenges/volleyball-match/problem