#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int who_wins(const unsigned int &x, const unsigned int &y, const vector<vector<unsigned int>> &teams, unsigned int sum_x, unsigned int sum_y) {
    const vector<unsigned int> &team1 = teams[x];
    const vector<unsigned int> &team2 = teams[y];
    int team1_fighter = team1.size() - 1;
    int team2_fighter = team2.size() - 1;
    bool team1turn = true;

    while(true) {
        if(team1turn) {
            if(sum_x >= sum_y)
                return x;
            team2_fighter -= team1[team1_fighter];
            if(team2_fighter<0)
                return x;
            for(int i=team2_fighter+1; i<=team2_fighter+team1[team1_fighter]; i++)
                sum_y -= team2[i]; 
        }
        else {
            if(sum_y >= sum_x)
                return y;
            team1_fighter -= team2[team2_fighter];
            if(team1_fighter<0)
                return y;
            for(int i=team1_fighter+1; i<=team1_fighter+team2[team2_fighter]; i++) 
                sum_x -= team1[i];
        }
        
        team1turn = !team1turn;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unsigned int n, k, q, s, t, x, y;
    string results = "";
    cin >> n >> k >> q;
    
    //Setup teams
    vector<vector<unsigned int>> teams (k+1);
    vector<unsigned> sums (k+1,0);
    for(int i=0; i<n; i++) {
        cin >> s >> t;
        teams[t].push_back(s);
        sums[t] += s;
    }
    for(auto &team : teams) 
        sort(team.begin(),team.end());
    
    while(q--) {
        cin >> t >> x >> y;
        if(t==1) { 
            teams[y].push_back(x);
            sums[y] += x;
        }
        else// if(t==2) 
            results += to_string( who_wins(x, y, teams, sums[x], sums[y]) ) + "\n";
    }
    
    cout << results << endl;
    
    return 0;
}
//https://www.hackerrank.com/challenges/fighting-pits/problem