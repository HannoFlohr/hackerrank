#include <bits/stdc++.h>
using namespace std;

vector<unsigned int> getDivisors(unsigned int n) {
    set<unsigned int> divisors;
    int upto = (int)sqrt(n);
    for(int i=1; i<=upto; i++)
        if(n % i == 0) {
            divisors.insert(i);
            divisors.insert(n/i);
        }
    
    vector<unsigned int> result;
    for(auto d:divisors)
        result.push_back(d);
    sort(result.begin(), result.end());

    return result;
}

int main()
{
    unsigned int n, a, cur, sum=0, subSum, maxGroup=0;
    vector<unsigned int> group;
    cin >> n;
    for(unsigned int i=0; i<n; i++) {
        cin >> a;
        maxGroup = max(maxGroup, a);
        sum += a;
        group.push_back(a);
    }

    //find all divisors for the sum of the groups
    vector<unsigned int> divisors = getDivisors(sum);
    
    //check which divisors form a valid bus size
    set<unsigned int> result;
    bool valid;
    for(auto d:divisors) {
        cur = 0;
        subSum = 0;
        valid = true;
        while(valid && cur<n) {
            subSum += group[cur++];
            if(subSum > d) 
                valid = false;
            if(subSum == d)
                subSum = 0;
        }
        if(valid)
            result.insert(d);
    }

    for(auto r:result)
        cout << r << " ";

    return 0;
}
//https://www.hackerrank.com/challenges/bus-station/problem?isFullScreen=false