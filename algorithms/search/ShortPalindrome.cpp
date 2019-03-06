#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

const ll MOD = 1000000007;
const int LETTERS = 26;

// Complete the shortPalindrome function below.
ll shortPalindrome(string s) {
    ll n=s.size(), result=0;
    //frequency of chars in the string
    int freq [LETTERS]={};
    //counts pairs of (a,b) possible in string
    int pairCount [LETTERS][LETTERS]={};
    //counts the palindromes 
    int count [LETTERS]={};

    int i;
    for(int a=0; a<n; a++) {
        i = (int)(s[a] - 'a'); 

        result += (count[i] % MOD);
        result %= MOD;

        for(int j=0; j<LETTERS; j++) {
            count[j] += (pairCount[j][i] % MOD);
            count[j] %= MOD;
        
            pairCount[j][i] += (freq[j] % MOD);
            pairCount[j][i] %= MOD;
        }

        freq[i]++;
        freq[i] %= MOD;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    ll result = shortPalindrome(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
