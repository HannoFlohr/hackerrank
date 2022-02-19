#include<bits/stdc++.h>
using namespace std;

unsigned int n, sum;
set<string> results;

void tryFill(unsigned int position, vector<unsigned int> inner_nodes, vector<unsigned int> outer_nodes, unsigned int in_use) {
    //arrived at last node to fill
    if(position == n-1) { 
        //compute last value and check if already in use
        outer_nodes[n-1] = sum - (inner_nodes[0] + inner_nodes[n-1]);
        unsigned int current = 1 << outer_nodes[n-1];

        if((current & in_use) != 0)
            return;

        //"starting form the group of three with the numerically lowest external node"
        //->fist outer node must be the lowest for valid results
        for(auto node:outer_nodes)
            if(node<outer_nodes[0])
                return;

        //create the resulting string
        string result = "";
        for(unsigned int i=0; i<n; i++)
            result += to_string(outer_nodes[i]) + to_string(inner_nodes[i]) + to_string(inner_nodes[(i+1)%n]);
        results.insert(result);
        return;
    }
    
    for(unsigned int i=1; i<=2*n; i++) {
        //make bitmask for number and check if it is used already, skip if used
        unsigned int current = 1 << i;
        if((current & in_use) != 0) 
            continue;
            
        inner_nodes[position+1] = i;
        unsigned int in_use_new = in_use | current;
        
        //compute outer value to get correct sum; check if in use; if not updated used mask
        outer_nodes[position] = sum - (inner_nodes[position] + i); 
        unsigned int currentOuter = 1 << outer_nodes[position];  
        if((in_use_new & currentOuter) != 0)
            continue;
        in_use_new |= currentOuter;
        
        //recursive call to try to fill in next triplet
        tryFill(position+1,inner_nodes,outer_nodes, in_use_new);
    }
}

/*
the n-gon consists of an inner connected structure with n nodes
and n additional outer nodes each connected to one of the inner nodes
all viable triplets consists of two inner and one outer node

start by setting each 1..2*n at first position at inner ring
use recursive function to fill in the rest
- loop through remaining nodes to fill in second inner node
- the two inner values can be used to compute the corresponding outer value to get the sum

use a bitmask to keep track of which elements are already in use
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> sum;
    
    vector<unsigned int> inner_nodes (n);
    vector<unsigned int> outer_nodes (n);
    
    //generate initial bitmask 100...001 (with 2*n 0's)
    //e.g. for n=3, no nodes used: 10000001; node 2 in use -> 10000101 
    unsigned int in_use = 0;
    for(unsigned int i=1; i<=2*n; i++)
        in_use |= 1 << i;
    in_use = ~in_use; 

    //loop throuh all 1..2*n as start nodes and try to fill the rest
    for(unsigned int i=1; i<=2*n; i++) {
        inner_nodes[0] = i;
        tryFill(0, inner_nodes, outer_nodes, in_use | (1<<i));
    }
    
    for(auto result: results)
        cout << result << endl;
    
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler068/problem