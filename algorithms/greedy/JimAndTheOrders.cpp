#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int,int>& p1, const pair<int,int>& p2) {
    if(p1.first==p2.first) return p1.second < p2.second;
    else return p1.first < p2.first;
}

// Complete the jimOrders function below.
vector<int> jimOrders(vector<vector<int>> orders) {
    int n= orders.size();
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++) 
        v.push_back(make_pair(orders[i][0] + orders[i][1], i));
    sort(v.begin(),v.end(),compare);

    vector<int> result (n);
    for(int i=0; i<n; i++)
        result[i] = v[i].second + 1;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> orders(n);
    for (int i = 0; i < n; i++) {
        orders[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> orders[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = jimOrders(orders);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
