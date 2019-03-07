#include <bits/stdc++.h>

using namespace std;

string organizingContainers(vector<vector<int>> container) {
    vector<int> sumofballs (container[0].size(),0);
    vector<int> sumofrows (0);
    int row;
    for(auto c:container) {
        row = 0;
        for(int i=0; i<sumofballs.size(); i++) {
            sumofballs[i] += c[i];
            row+=c[i];
        }
        sumofrows.push_back(row);
    }
    sort(sumofballs.begin(),sumofballs.end());
    sort(sumofrows.begin(),sumofrows.end());

    for(int i=0; i<sumofballs.size(); i++) 
        if(sumofballs[i] != sumofrows[i]) return "Impossible";
    return "Possible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
