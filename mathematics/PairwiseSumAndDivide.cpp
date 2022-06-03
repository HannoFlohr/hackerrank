#include<bits/stdc++.h>
using namespace std;

/*
for all a_i greater than 2 a_i*a_j > a_i+a_j -> (a_i+a_j)/(a_i*a_j)=0
-> only count 1's and 2's 
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, a, ones, twos;
    long long result;
    cin >> t;
    while(t--) {
        cin >> n;
        
        ones = twos = 0;
        
        for(int i=0; i<n; i++) {
            cin >> a;
            if(a==1) ones++;
            else if(a==2) twos++;
        }
        
        //case a_i = a_j = 1 -> (1+1)/(1*1) = 2
        result = 2 * ((ones * (ones-1)) / 2);
        //case one a_i is 1 the other not -> (1+x)/(1*x) = 1
        result += ones * (n - ones);
        //case a_i = a_j = 2 -> (2+2)/(2*2) = 1
        result += (twos * (twos-1)) / 2;
        
        cout << result << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/pairwise-sum-and-divide/problem