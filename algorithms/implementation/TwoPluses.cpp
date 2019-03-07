#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

class Plus {
public:
    int x;
    int y;
    int size;
    int area;
    Plus(int x, int y, int size) {
        this->x = x;
        this->y = y;
        this->size = size;
        if(size==0) this->area = 1;
        else this->area = 1 + 4 * size;
    }
};

void checkPlus(vector<string>& g, const int& r, const int& c, vector<Plus*>& pluses) {
    int i=1;
    pluses.push_back(new Plus(c,r,0) );
    while(r-i >= 0 && r+i < g.size() && c-i >=0 && c+i < g[0].size()) {
        if(g[r-i][c] != 'G' || g[r+i][c] != 'G' || 
            g[r][c-i] != 'G' || g[r][c+i] != 'G' ) 
                break;
        pluses.push_back(new Plus(c,r,i) );
        i++;
    }
}

bool checkOverlap(Plus* p, Plus* q, const int& n, const int& m) {
    vector<vector<int>> v = vector<vector<int>>(n, vector<int>(m,0)); 
    v[p->y][p->x] = 1;
    for(int i=1; i<=p->size; i++) {
        v[p->y-i][p->x] = 1;
        v[p->y+i][p->x] = 1;
        v[p->y][p->x-i] = 1;
        v[p->y][p->x+i] = 1;
    } 
    if(v[q->y][q->x] == 1) return false;
    for(int i=1; i<=q->size; i++) {
        if (v[q->y-i][q->x] == 1 ||
            v[q->y+i][q->x] == 1 ||
            v[q->y][q->x-i] == 1 ||
            v[q->y][q->x+i] == 1 
            ) {
                return false;
            }
    }
    return true;
}

bool compare(Plus* p1, Plus* p2) {
    return p1->area < p2->area;
}

int twoPluses(vector<string> grid) {
    int n=grid.size(), m=grid[0].size();
    vector<Plus*> pluses;
    for(int j=1; j<n-1; j++) {
        for(int i=1; i<m-1; i++) {
            if(grid[j][i]=='B') continue;
            checkPlus(grid,j,i,pluses);
        }
    }
    sort(pluses.rbegin(),pluses.rend(),compare);  
    
    int maxProduct = 0;
    for(int i=0; i<pluses.size(); i++) 
        for(int j=i+1; j<pluses.size(); j++) {
            if(pluses[i]->area * pluses[j]->area > maxProduct) {
                if( checkOverlap(pluses[i],pluses[j],n,m) )
                    maxProduct = pluses[i]->area * pluses[j]->area;
            }
        }
    
    return maxProduct;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
