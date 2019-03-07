#include <bits/stdc++.h>

using namespace std;

vector<int> stones(int n, int a, int b) {
    vector<int> res (0);
    if(a==b) { 
        res.push_back( (n-1) * a );
        return res;
    }

    int i=n-1, j=0, cur;
    while(i>=0) {
        cur = i * a + j *b;
        res.push_back(cur);
        i--;
        j++;
    }
    sort(res.begin(),res.end());
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int a;
        cin >> a;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int b;
        cin >> b;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = stones(n, a, b);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}
