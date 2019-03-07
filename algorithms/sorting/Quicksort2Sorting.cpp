#include <bits/stdc++.h>
using namespace std;


void quickSort(vector <int> &arr) {
    if(arr.size() < 2) return;

    int pivot = arr[0];
    vector<int> left,right,equal;
    for(int i=0; i<arr.size(); i++) { 
        if(arr[i]==pivot) equal.push_back(arr[i]);
        else if(arr[i]<pivot) left.push_back(arr[i]);
        else right.push_back(arr[i]);
    }
    quickSort(left);
    quickSort(right);

    arr.clear();

    for(auto a:left) {
        arr.push_back(a);
        cout << a << " ";
    }

    arr.push_back(pivot);
    cout << pivot << " ";

    for(auto a:right) {
        arr.push_back(a);
        cout << a << " ";
    }
    cout << endl;
}


int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}

