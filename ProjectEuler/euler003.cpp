#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        
        unsigned long long int result = 0LL;
        while(n%2==0) { n /= 2; }
        if(n==1) result = 2;
        else {
            unsigned long long int i = 3LL;
            for(i; i<=sqrt(n); ) {
                if(n%i==0)
                    n /= i;    
                else 
                    i += 2;
            }
            if(n>2) result = n;
            else result = i;    
        }
        cout << result << endl;
    }
    return 0;
}

//https://www.hackerrank.com/contests/projecteuler/challenges/euler003