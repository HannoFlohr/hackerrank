#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, i, sum_a, sum_b, s;
    bool p1turn;
    cin >> t;
    while(t--) {
        cin >> n;
        
        vector<int> a (n);
        vector<int> b (n);
        for(i=0; i<n; i++)
            cin >> a[i];
        for(i=0; i<n; i++)
            cin >> b[i];
            
        vector<pair<int, int>> sum (n, make_pair(-1,-1));
        for(i=0; i<n; i++) {
            s = a[i] + b[i];
            sum[i] = {s, i};
        }
        sort(sum.begin(), sum.end());
        
        sum_a = 0; 
        sum_b = 0;
        p1turn = true;
        for(i=n-1; i>=0; i--) {
            if(p1turn)
                sum_a += a[ sum[i].second ];
            else
                sum_b += b[ sum[i].second ];
                
            p1turn = !p1turn;
        }
          
        if(sum_a > sum_b)
            cout << "First" << endl;
        else if(sum_b > sum_a)
            cout << "Second" << endl;
        else
            cout << "Tie" << endl;        
    }
    return 0;
}
//https://www.hackerrank.com/challenges/fun-game-1/problem