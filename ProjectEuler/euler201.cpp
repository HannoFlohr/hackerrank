#include<bits/stdc++.h>
using namespace std;

const int MAXSUM = 100 * 100 + 10;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    //read input
    int n, m, cur;
    cin >> n >> m;
    vector<int> a (n);
    for(auto &i:a)
        cin >> i;
    
    //vectors to check if a sum can be reached using 1..m elements, and if it can be reached multiple times
    vector<vector<bool>> sum_possible (m+1);
    vector<vector<bool>> sum_duplicate (m+1);
    for(int i=0; i<sum_possible.size(); i++) {
        int size = n*n*i+1; cerr<<size<<endl;
        size = min(size, MAXSUM);
        sum_possible[i].resize(size, false);
        sum_duplicate[i].resize(size, false);
    }
    sum_possible[0][0] = true;
    
    //loop through all input values for a
    for(auto x:a) {
        //append to valid sets
        for(int choose=m; choose>0; choose--) {
            //for valid sums
            for(int sum=0; sum<sum_possible[choose-1].size(); sum++) {
                //skip impossible sum
                if(!sum_possible[choose-1][sum])
                    continue;
                    
                cur = x + sum;
                
                //sum reached already -> flag as duplicate
                if(sum_duplicate[choose-1][sum] || sum_possible[choose][cur]) 
                    sum_duplicate[choose][cur] = true;
                
                sum_possible[choose][cur] = true;
            }
        }
    }
    
    int unique_sum = 0;   
    for(int i=0; i<sum_possible[m].size(); i++)
        if(sum_possible[m][i] && !sum_duplicate[m][i])
            unique_sum += i;
    cout << unique_sum << endl;

    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler201/problem