#include<bits/stdc++.h>
using namespace std;

int MAXD = 2000000;

//returns the amount of irreducible fractions from 0 to n/d ( rank(n,d) )
//http://people.csail.mit.edu/mip/papers/farey/talk.pdf
//describes the algorithm used here
unsigned int farey_rank(unsigned int n, unsigned int d) {
    vector<unsigned int> T (MAXD+1);
    
    //initialize the array T[q] = q * n/d
    for(unsigned int i=0; i<T.size(); i++) 
        T[i] = i * n/d;
    
    //for each q, consider its multiples m*q and subtract T[q] from T[m*q]     
    for(int i=1; i<T.size(); i++)
        for(int j=2*i; j<T.size(); j+=i)
            T[j] -= T[i];
            
    //rank(n,d) is obtained by summing all values in the array
    unsigned int sum = 0;
    for(auto i : T)
        sum += i;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unsigned int a;
    cin >> a >> MAXD;
    
    //the farey_rank computes the amount of fractions from 0 to n/d
    //so the amount of fractions between 1/(a+1) and 1/a can be computed by
    //  rank(1,a) - rank(1,a+1) - 1 
    cout << (farey_rank(1,a) - farey_rank(1,a+1) - 1) << endl;
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler073/problem