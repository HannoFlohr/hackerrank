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
        int n;
        cin >> n;
        
        n--;
        unsigned long int sumThrees = n/3, sumFives = n/5, sumFifteens = n/15;
        sumThrees = 3 * sumThrees * (sumThrees + 1) >> 1;
        sumFives = 5 * sumFives * (sumFives + 1) >> 1;
        sumFifteens = 15 * sumFifteens * (sumFifteens + 1) >> 1;
        unsigned long int sum = sumThrees + sumFives - sumFifteens;
        
        cout << sum << endl;
    }
    return 0;
}

//https://www.hackerrank.com/contests/projecteuler/challenges/euler001