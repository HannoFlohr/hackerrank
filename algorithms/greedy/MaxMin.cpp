#include <bits/stdc++.h>

using namespace std;

int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());

    int min, max, fairness, minUnfairness = numeric_limits<int>::max();
    for(int i=0; i<arr.size()-k+1; i++) {
        min = arr[i];
        max = arr[i+k-1];
        fairness = max - min;
        if(fairness < minUnfairness) minUnfairness = fairness;
    }
    
    return minUnfairness;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
