#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int MINVALUE = -1e9;
const int MAXVALUE = 1e9;

int n;
vector<int> input;
set<int> val [20];
int result [1 << 19]; //max input values 2^18
int counter = 0;

//depth first search, starting at node 0
//checking children at 2k+1 and 2k+2
void dfs(int k, int d, int e, int upper) {
    auto it = val[d].upper_bound(upper);
    if(it == val[d].end()) 
        return;

    //if node# is greater than the amount of values -> set as result
    if(k >= n-1) {
        result[k] = *it;
        val[d].erase(it);
        counter++;
        return;
    }

    //dfs on children
    dfs(2*k+1, d, e-1, upper);
    dfs(2*k+2, e-1, e-1, *it);

    result[k] = min(result[2*k+1],result[2*k+2]);
}

bool solve() { 
    //store original input for comparison at end
    vector<int> original_input (input);

    //create a vector containing unique values from the input array
    vector<int> data = input;
    sort(data.begin(), data.end());
    data.erase(unique(data.begin(),data.end()), data.end() );

    //if amount of unique values is not n, the input is not valid
    if(data.size() != n) return false;

    for(int i=0; i<input.size(); i++)
        input[i] = lower_bound(data.begin(),data.end(), input[i]) - data.begin();

    //determine the frequency of each input value
    vector<int> frequency (n);
    for(int i=0; i<input.size(); i++)
        frequency[input[i]]++;
    // if a value has higher frequncy than n, the input is not valid
    for(int i=0; i<n; i++)
        if(frequency[i] >= n+1) return false;

    for(int i=0; i<n; i++)
        val[frequency[i]].insert(i);

    //depth first search beginning at node 0
    dfs(0, (int)log2(n) + 1, (int)log2(n) + 1, MINVALUE);

    //if counter is not n, the dfs has not encountered the right amount of leaf nodes -> input is not valid
    if(counter != n) return false;

    //set result
    for(int i=0; i<n*2-1; i++)
        result[i] = data[result[i]];

    //copy result, sort the check and original input and than compare
    //if not equal -> input not valid
    vector<int> check_input (result, result+n*2-1);
    sort(check_input.begin(), check_input.end());
    sort(original_input.begin(), original_input.end());
    if(check_input != original_input) 
        return false;

    return true;
}

int main() {
    cin >> n;
    input = vector<int>(n*2-1);
    for(int i=0; i<input.size(); i++)
        cin >> input[i];

    if(solve()){
        cout << "YES" << endl;
        for(int i=0; i<2*n-1; i++) cout << result[i] << " ";
        cout << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
