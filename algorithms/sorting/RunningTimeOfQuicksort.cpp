#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int res2;

int runningTime(vector<int> arr) {
    int i,j, N=arr.size();
    int value;
    int counter = 0;
    for(i=1;i<N;i++)
    {
        value=arr[i];
        j=i-1;
        while(j>=0 && value<arr[j])
        {
            arr[j+1]=arr[j];
            j=j-1;
            counter++;
        }
        arr[j+1]=value;

    }
    return counter;
}

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
            res2++;
        }
    }
    temp = arr[i];
    arr[i] = arr[hi];
    arr[hi] = temp;
    res2++;
    //for(auto a:arr) cout << a << " ";
    //cout << endl;
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
    int n,x,res1;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        cin >> x;
        arr.push_back(x);
    }

    res1 = runningTime(arr);
    res2 = 0;
    quicksort(arr,0,arr.size()-1);

    cout << res1-res2 << endl;

    return 0;
}
