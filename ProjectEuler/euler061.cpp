#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const unsigned int LIMIT = 10000; //4digits
unsigned int categoryMask; //bitmask for the categories (triangle,square,etc)
vector<unsigned int> numbers (LIMIT, 0);
set<unsigned int> results;

//mark a number as belonging to a category
void add(const unsigned int& x, const unsigned int& category) {
    if(x<1000 || x>=10000) 
        return;
    unsigned int bit = 1 << category;
    numbers[x] |= bit & categoryMask;
}

void search(vector<unsigned int>& s, unsigned int mask) {
    unsigned int low = 1000;
    unsigned int high = 10000;

    if(!s.empty()) {
        //highest two digits == previous numbers lowest digits
        unsigned int lowDigits = s.back() % 100;
        low = lowDigits * 100;
        high = low + 100;
    }

    for(unsigned int i=low; i<high; i++) {
        unsigned int categories = numbers[i];
        if(categories == 0) continue;
    
        //check if numbers are used multiple times
        bool unique = true;
        for(auto x : s)
            if(x==i) {
                unique = false;
                break;
            }
        if(!unique) continue;

        for(unsigned int j=3; j<=8; j++) {
            unsigned int curCategory = 1 << j;
            
            //does the number belong to the current category?
            if((categories & curCategory) == 0) continue;
            //new category
            if((mask & curCategory) != 0) continue;
        
            //check
            unsigned int nextMask = mask | curCategory;
            if(nextMask == categoryMask) {
                //compare digits against first element
                unsigned int first = s.front();
                unsigned int lowerDigits = i % 100;
                unsigned int upperDigits = first/100;
                if(lowerDigits==upperDigits) {
                    unsigned int sum = i;
                    for(auto x:s) sum += x;
                    results.insert(sum);
                }
            }
            else { //search with nextMask
                s.push_back(i);
                search(s,nextMask);
                s.pop_back();
            }
        }
    }
}

int main() {
    unsigned int t,x;
    cin >> t;
    while(t--) {
        cin >> x;
        categoryMask |= 1 << x;
    }

    //compute all triangle..octagon numbers and
    //set masks for all numbers belonging to each category
    for(unsigned int n=1; n<LIMIT; n++) {
        //triangle
        x = n * (n + 1) / 2;
        if(x>=10000) break;
        add(x,3);
        //square
        x = n * n;
        add(x,4);
        //pentagon
        x = n *(3 * n - 1) / 2;
        add(x,5);
        //hexagon
        x = n * (2 * n - 1);
        add(x,6);
        //heptagon
        x = n * (5 * n - 3) / 2;
        add(x,7);
        //octagon 
        x = n * (3 * n - 2);
        add(x,8);
    }

    //search for valid results
    vector<unsigned int> s;
    search(s,0);

    for(auto r : results)
        cout << r << endl;
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler061/