#include <bits/stdc++.h>

using namespace std;

long candies(int n, vector<int> arr) { 
    vector<int> d (n,1);
    for(int i=1; i<n; i++) {
        if(arr[i]>arr[i-1])
            d[i] = d[i-1]+1;
    }
    for(int i=n-2; i>=0; i--) {
        if(arr[i] > arr[i+1] && d[i] <= d[i+1])
            d[i] = d[i+1]+1;
    }
    return accumulate(d.begin(),d.end(),0L);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
