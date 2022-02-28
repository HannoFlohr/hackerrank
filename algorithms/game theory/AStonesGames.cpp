#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e9;

vector<unsigned> powers2 (31);

//returns index of the next higher power of 2 of n
unsigned getExponent(const int n) {
    auto ub = upper_bound(powers2.begin(), powers2.end(), n);
    return distance(powers2.begin(), ub);
}

/*
nimbers can be computed by using the maximum excludant 
trying for the first few n one can see that nimbers are:
n		0	1	2	3	4	5	6	7	8	9
nimber	0	1	2	2	3	3	3	3	4	4
-> nimbers = 1 + floor(log2 n)

Sprague-Grundy theorem: cumulative XOR of nimbers can be used to determine if the first person wins
nimber		0	1	2	2	3	3	3	3	4	4	
X(nimber)	0	1 	3 	1 	2 	1 	2 	1 	5 	1 
-> X(2n+1)=1	X(2n)=1^nimber(2n)

Player one needs to choose a pile p and change the nimber of that pile from nimber(p) tp nimber(X XOR nimber(p)) in order to win.
-odd n: Player one can just choose the first pile and remove 1 in order to win
-even n: minimum stones player one has to take corresponds to the minimum positive value of nimber(p) - X(n) XOR nimber(p)
	minimum number that gives that value is		m^(y-1)
	if the new nimber is one less than the old one: player has to remove half of p, otherwise player goes down to the largest
	possible pile with nimber x(n) XOR y 		2^((x XOR y)-1)
*/
unsigned solve(const int n) { 
    // X(2n+1)=1
    if(n%2 == 1) return 1;
    
    int exp;
    frexp(n,&exp); 
    unsigned x = 1^exp; 

    frexp(x,&exp);
    unsigned y = 1<<(exp-1);

    if((x^y)+1 == y)
        return 1<<(y-2);
    else 
        return (1<<(y-1)) - (1<<(x^y)) + 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin >> t;
    
    //compute 2^i 
    powers2[0] = 1;
    for(unsigned i=1; i<powers2.size(); i++)
        powers2[i] = powers2[i-1]<<1;    
    
    //solve for all powers of 2
    vector<unsigned> resultForPower;
    for(auto p:powers2) 
        resultForPower.push_back( solve(p) );
        
    string result = "";
    while(t--) {
        cin >> n;
        
        //for odd n: always 0
        if(n%2==1)
            result += "1\n";
        //for even n: use precomputed result for the next higher power of 2
        //result for all numbers (2^i-1)+1....(2^i) is the same value
        else 
            result += to_string(resultForPower[getExponent(n)-1]) + "\n";
    }
    
    cout << result << endl;
    
    return 0;
}
//https://www.hackerrank.com/challenges/half/problem