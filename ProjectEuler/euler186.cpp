#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set> 
#include <climits> 
using namespace std;

struct DisjointSet {
    int parent;
    int count;
};

typedef unsigned long long int ll;
const int MOD = 1000000;
int number, p;

vector<int> Sk (0);
int friendCount = 0;
int successfulCalls = 0;

vector<DisjointSet> sets;

//returns the parents of the set of 'x'
int find(int x) {
    int cur = x;
    int parent;
    while(true) {
        parent = sets[cur].parent;
        if(parent == cur) {
            if(sets[x].parent != parent)
                sets[x].parent = parent;
            return parent;
        }
        cur = parent;
    }
}

//merge two sets
void unionSets(int a, int b) {
    int x = find(a);
    int y = find(b);

    //if already in same set, return
    if(x == y) return;

    if(sets[x].count >= sets[y].count) {
        sets[x].count += sets[y].count;
        sets[y].parent = x;
    }
    else {
        sets[y].count += sets[x].count;
        sets[x].parent = y;
    }
}

int getNextNumber() {
    ll nextNumber;
    if(Sk.size() < 55) {
        int k = Sk.size() + 1;
        nextNumber = 100003ULL - 200003ULL * k + 300007ULL * k * k * k;
    }
    else {
        nextNumber = Sk[Sk.size()-24] + Sk[Sk.size()-55];
        
        //throw away too old Sk values
        const size_t removeOld = 100;
        if(Sk.size() > 55 + removeOld)
            Sk.erase(Sk.begin(), Sk.begin()+removeOld);
    }

    nextNumber %= MOD;
    Sk.push_back((int)nextNumber);

    return (int)nextNumber;
}

int main() { 
    cin >> number >> p;

    //create all numbers as independent sets
    for(int i=0; i<MOD; i++)
        sets.push_back( {i,1} );

    int caller, called;
    while(sets[find(number)].count < MOD * p / 100) {
        caller = getNextNumber();
        called = getNextNumber();

        //if caller == called -> misdial
        if(caller == called) continue;

        successfulCalls++;
        unionSets(caller, called);
    }

    cout << successfulCalls << endl;

    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler186/problem