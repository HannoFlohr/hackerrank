#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int dp[5005][5005]; //dp[i][j] : i = total numbers, j=last element
int sumBefore[5005];
int sumAfter[5005];

//returns the some of the row 'row' in the dp array
int sumOf(const int &row, const int &j_start, const int &j_end) {
    unsigned int sum = 0;
    for(int i=j_start; i<=j_end; i++) 
        sum = (sum + dp[row][i]) % MOD;
    return sum;
}

int main()
{
    int n, k, l, x, sum;
    bool bigger, smaller;
    cin >> n >> k >> l;
    set<int> a;
    set<int> b;
    for(int i=0; i<k; i++) {
        cin >> x;
        a.insert(x);
    }
    for(int i=0; i<l; i++) {
        cin >> x;
        b.insert(x);
    }

    //check if a and b contain s same element; neighbors cant be both bigger and smaller 
    for(auto e:a) 
        if(b.find(e) != b.end()) {
            cout << "0" << endl;
            return 0;
        }

    if(a.size() > (int)(n/2) || b.size() > (int)(n/2) ) {
        cout << "0" << endl;
        return 0;
    }

    //initialize the arrays
    memset(dp,0,sizeof(dp));
    memset(sumBefore,0,sizeof(sumBefore));
    memset(sumAfter,0,sizeof(sumAfter));
    sumBefore[2] = 1;
    sumAfter[1] = 1;

    dp[1][1] = 1; //one element, one permutation
    for(int i=2; i<=n; i++) {
        bigger = smaller = false;
        //if a has element i or b has element i-1 -> include only bigger sets
        if(a.find(i) != a.end() || b.find(i-1) != b.end())
            bigger = true;
        //if b has element i ir a has element i-1 -> include only smaller sets
        else if(b.find(i) != b.end() || a.find(i-1) != a.end())
            smaller = true;

        sum = sumOf(i-1, 1, i-1);
        
        //compute the next dp row
        for(int j=1; j<=i; j++) {
            if(bigger)
                dp[i][j] = sumAfter[j]; //sumOf(i-1, j, i-1);
            else if(smaller)
                dp[i][j] = sumBefore[j]; //sumOf(i-1, 1, j-1); 
            else
                dp[i][j] = sum;
        }

        //update the sums
        for(int j=1; j<=i+1; j++)
            sumBefore[j] = (sumBefore[j-1] + dp[i][j-1]) % MOD;
        for(int j=i; j>=1; j--)
            sumAfter[j] = (sumAfter[j+1] + dp[i][j]) % MOD;
    }
    
    cout << sumOf(n,1,n) << endl;

    return 0;
}
//https://www.hackerrank.com/challenges/extremum-permutations/problem