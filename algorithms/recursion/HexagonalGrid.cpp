#include <bits/stdc++.h>

using namespace std;

/*
recursively try to fill the grid
possible cases:
- vertical: both current row values == 0
- horizontal: in row 1 or row 2
- diagonal forward from [1][i] to [0][i+1]
*/
bool hexagonalGrid(string s [2], int n) {
    int i, empty = 0;
    for(i=0; i<n; i++) {
        if(s[0][i] == '0')
            empty++;
        if(s[1][i] == '0')
            empty++;
    }
    //for odd amount of empty spaces no solution is possible
    if(empty % 2 != 0)
        return false;
    //if no spaces are empty, its already solved
    if(empty == 0)
        return true;

    bool result = false;
    for(i=0; i<n; i++) {
        //case both rows in current column are empty
        if(s[0][i] == '0' && s[1][i] == '0') {
            s[0][i] = s[1][i] = '1';
            result = hexagonalGrid(s,n);
            s[0][i] = s[1][i] = '0';
        }
        if(result)
            return true;
        
        if(i+1 < n) {
            //case: horizontal, first row
            if(s[0][i] == '0' && s[0][i+1] == '0') {
                s[0][i] = s[0][i+1] = '1';
                result = hexagonalGrid(s,n);
                s[0][i] = s[0][i+1] = '0';
            }
            if(result)
                return true;
            //case: horizontal, second row
            if(s[1][i] == '0' && s[1][i+1] == '0') {
                s[1][i] = s[1][i+1] = '1';
                result = hexagonalGrid(s,n);
                s[1][i] = s[1][i+1] = '0';
            }
            if(result)
                return true;
            //case: diagonal forward
            if(s[1][i] == '0' && s[0][i+1] == '0') {
                s[1][i] = s[0][i+1] = '1';
                result = hexagonalGrid(s,n);
                s[1][i] = s[0][i+1] = '0';
            }
            if(result)
                return true;
        }
    }
    return result;
}

int main()
{
    int t,n;
    string s [2];
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> s[0] >> s[1];
        if( hexagonalGrid(s,n) )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
