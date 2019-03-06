#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

typedef long long int ll;

class Action {
public:
    int x;
    int y;
    int m;
    vector<string> a;
    Action() {}
    Action(int x,int y, int m,vector<string> a) : x(x),y(y),m(m),a(a) {}
};

int eI, eJ;

const int moves [][6] = { {-2,-2,0,2,2,0}, {-1,1,2,1,-1,-2} };
const string actionstrings [] = {"UL","UR","R","LR","LL","L"};
vector<vector<bool>> visited;

void outActions(vector<string> a) {
    map<string,int> m;
    for(auto x:a) 
        m[x]++;
    for(int i=0; i<6; i++) 
        while(m[ actionstrings[i] ]--) cout << actionstrings[i] << " ";
    cout << endl;
}

// Complete the printShortestPath function below.
void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    eI = i_end;
    eJ = j_end;
    visited = vector<vector<bool>>(n, vector<bool>(n,false) );
    visited[i_start][j_start] = true;

    queue<Action*> q;
    q.push( new Action(i_start,j_start,0,vector<string>() ) );
    Action* a;
    int moveDist, minDist = abs(i_start - eI) + abs(j_start - eJ);;
    while(!q.empty()) { 
        a = q.front();
        q.pop();
        if(a->x == eI && a->y == eJ) {
            cout << a->m << endl;
            outActions(a->a);
            return;
        }
        
        visited[a->x][a->y] = true;
        for(int i=0; i<6; i++) {
            if(a->x + moves[0][i] < 0 || a->x + moves[0][i] >= n ||
                a->y + moves[1][i] < 0 || a->y + moves[1][i] >= n )
                    continue;
            moveDist = abs(a->x + moves[0][i] - eI) + abs (a->y + moves[1][i] - eJ);
            if(!visited[ a->x + moves[0][i] ][ a->y + moves[1][i] ] &&
                    moveDist<minDist ) { 
                minDist = moveDist;
                vector<string> newA = a->a;
                newA.push_back(actionstrings[i]);
                q.push( new Action(a->x + moves[0][i], a->y + moves[1][i], 
                                    a->m+1, newA) );
            }
        }
        delete a;
    }
    cout << "Impossible" << endl;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string i_startJ_start_temp;
    getline(cin, i_startJ_start_temp);

    vector<string> i_startJ_start = split_string(i_startJ_start_temp);

    int i_start = stoi(i_startJ_start[0]);

    int j_start = stoi(i_startJ_start[1]);

    int i_end = stoi(i_startJ_start[2]);

    int j_end = stoi(i_startJ_start[3]);

    printShortestPath(n, i_start, j_start, i_end, j_end);

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
