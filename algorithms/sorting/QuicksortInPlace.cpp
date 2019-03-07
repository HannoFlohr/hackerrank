#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition(vector<int>& arr, int lo, int hi) {
    int pivot = arr[hi];
    int i = lo;
    int temp;
    for(int j=lo; j<hi; j++) {
        if(arr[j] < pivot) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    temp = arr[i];
    arr[i] = arr[hi];
    arr[hi] = temp;
    for(auto a:arr) cout << a << " ";
    cout << endl;
    return i;
}

void quicksort(vector<int>& arr, int lo, int hi) {
    if(lo < hi) {
        int p = partition(arr, lo, hi);
        quicksort(arr, lo, p-1);
        quicksort(arr, p+1, hi);
    }
}

int main() {
    int n;
    cin >> n;

    int x;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        cin >> x;
        arr.push_back(x);
    }

    quicksort(arr, 0, arr.size()-1);

    return 0;
}
