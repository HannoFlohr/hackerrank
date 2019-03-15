#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;
const ll MOD = 1000000007;

/*
    Example: n = "3456"
    digit 6 is contained in 4 substrings "6" "56" "456" "3456", contributing 6 to the sum each time as it can only be the last digit of the substring
    digit 5 is contained in 6 substrings, contributing 
                                  5         5
                                 45         5
                                  56        50  
                                 456        50 
                                345         5
                                3456        50
    3 * 5 + 3 * 50 = 3 * 55 = 3 * (10^i+1) * digit
    -> factor = factor * 10 + 1; factor(0) = 1;
    contribution for each digit (starting at end of string): 
    digit * factor * #possibleSubstrings 
*/
ll substrings(string n) {
    ll sum = 0, factor = 1;
    for(int i=n.size()-1; i>=0; i--) {
        sum = (sum + (n[i]-'0') * factor * (i+1)) % MOD;
        factor = (factor*10+1) % MOD;
    }
    return sum;
}

int main()
{
    string n;
    cin >> n;
    cout << substrings(n) << endl;
    return 0;
}
