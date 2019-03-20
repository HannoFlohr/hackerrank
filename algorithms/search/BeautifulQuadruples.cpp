#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int MAXINPUT = 3000;
const int MAXXOR = 1 << 12; // 2^12 = 4096 > 3000=max input

ll beautifulQuadruples(const vector<int> &input) {
    int a=input[0], b=input[1], c=input[2], d=input[3]; 
    ll result = 0;
    
    vector<int> permutations (MAXINPUT+1, 0);
    for(int i=1; i<=a; i++)
        for(int j=i; j<=b; j++)
            permutations[j]++;
    for(int i=1; i<=MAXINPUT; i++)
        permutations[i] += permutations[i-1];

    vector<vector<int>> count (MAXINPUT+1, vector<int>(MAXXOR+1, 0));
    for(int i=1; i<=a; i++)
        for(int j=i; j<=b; j++)
            count[j][i^j] += 1;
    for(int i=0; i<=MAXXOR; i++)
        for(int j=1; j<=MAXINPUT; j++)
            count[j][i] += count[j-1][i];

    for(int i=1; i<=c; i++)
        for(int j=i; j<=d; j++)
            result += (permutations[i] - count[i][i^j ]);
    
    return result;
}

int main()
{
    vector<int> v (4);
    cin >> v[0] >> v[1] >> v[2] >> v[3];
    sort(v.begin(),v.end());
    cout << beautifulQuadruples(v) << endl;
    return 0;
}
