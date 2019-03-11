#include <bits/stdc++.h>

using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int d1=0, d2=0, n=arr.size();
    for(int i=0; i<n; i++) {
        d1 += arr[i][i];
        d2 += arr[i][n-1-i];
    }
    return abs(d1-d2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
