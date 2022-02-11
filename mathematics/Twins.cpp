#include<bits/stdc++.h>
using namespace std;

vector<bool> segmentedSieveNoPreGen(long long int left, long long int right) {
    vector<bool> isPrime (right-left+1, true);
    long long int limit = sqrt(right);
    for(long long int i=2; i<=limit; i++) 
        for(long long int j=max(i*i, (left+i-1)/i*i); j<=right; j+=i)
            isPrime[j-left] = false;
    if(left==1)
        isPrime[0] = false;
    return isPrime;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m, count=0;
    cin >> n >> m;
    
    vector<bool> isPrime = segmentedSieveNoPreGen(n, m);
    
    if( !(isPrime.size()<2) )
        for(int i=0; i<isPrime.size()-2; i++) 
            if(isPrime[i] && isPrime[i+2])
                count++;
    
    cout << count << endl;
    return 0;
}
//https://www.hackerrank.com/challenges/twins/problem