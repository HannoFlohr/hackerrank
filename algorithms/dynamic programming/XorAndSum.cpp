#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;
const ll MOD = 1000000007;
const int MAXNUMBER = 500000;

//stores the bits of input a and b
int a[MAXNUMBER], b[MAXNUMBER];
//counts the number of bits that are 0 and 1 upto index i
int cnt[MAXNUMBER][2];

ll xorAndSum(string aIn, string bIn) {
    int i, sa = aIn.size(), sb = bIn.size();

    //set numbers a and b; lsb at index 0
    for(i=0; i<sa; i++)
        a[sa - i - 1] = aIn[i] - '0';
    for(i=0; i<sb; i++)
        b[sb - i - 1] = bIn[i] - '0';

    //count the amount of 1 and 0 bits in b
    cnt[0][0] = (b[0] == 0);
    cnt[0][1] = (b[0] == 1);
    for(i=1; i<sb + 314159; i++) {
        cnt[i][0] = cnt[i-1][0] + (b[i] == 0);
        cnt[i][1] = cnt[i-1][1] + (b[i] == 1);
    }

    ll result = 0, cur = 0, sum0, sum1, sum, helper;
    int count0, count1;
    for(int i=0; i<sb + 314159; i++) {
        //get count for current bit i
        if(i < 314159) {
            count0 = cnt[i][0] + 314159 - i;
            count1 = cnt[i][1];
        }
        else {
            count0 = 314159 + cnt[sb-1][0] - cnt[i - 314159 - 1][0];
            count1 = cnt[sb-1][1] - cnt[i - 314159 - 1][1];
        }

        //compute the sum for current i
        sum0 = a[i] * count0;
        sum1 = (a[i]^1) * count1;
        sum = sum0 + sum1;

        //add sum to overall result
        if(i==0) cur = 1;
        else cur = (cur*2) % MOD;
        // result = 2^i * sum
        helper = (cur * sum) % MOD;
        result = (result + helper) % MOD;
    }

    return result;
}

int main()
{
    string aIn, bIn;
    cin >> aIn >> bIn;
    cout << xorAndSum(aIn,bIn) << endl;
    return 0;
}
