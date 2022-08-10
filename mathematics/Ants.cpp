#include<bits/stdc++.h>
using namespace std;

const int MAXTIME = 1e9+6;
const int LENGTH = 1000;
const int CYCLES = 1e5;

/*
first find the encounters for the first 10^9 seconds: 
LENGTH of the race = 1000, speed of the ants is 0.1 -> time for one cycle = 10^4 
-> total CYCLES for 10^9 seconds = 10^9 / time for one cycle = 10^5 

to maximize the encounters the ants have to divided equally in two groups -> n*(n-n/2)

therefore number of encounters up to 10^9 seconds is: n * (n-n/2) * CYCLES 

for the remaining 6 seconds: 
if the distance between two ants is less than 0.1 * 6 * 2 there will be an encounter 
*/

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v (n);
    for(auto &i : v)
        cin >> i;
    
    sort(v.begin(),v.end());
    
	//encounters up to 10^6 seconds
    int encounters = n * (n-n/2) * CYCLES;
    
	//encounters in last 6 seconds
	int additional_encounters = 0;
    for(int i=0; i<n-1; i++) 
        if(v[i+1] - v[i] == 1) {
            additional_encounters++;
            i++;
        }
        
    if(v[n-1]-v[0]==1)
        additional_encounters++;
        
    cout << (encounters + additional_encounters) * 2 << endl;
    
    return 0;
}
//https://www.hackerrank.com/challenges/ants/problem