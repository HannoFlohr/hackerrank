#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

class Point {
public:
    int x;
    int y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

//grid is 1<n<=100
int gamefield [101][101];
queue<Point> moves;
int n; //gridsize

void updateGamefield(const int& x, const int& y, const int& value) {
    if(gamefield[x][y] > value+1)
        gamefield[x][y] = value+1;
}

void addPoints(const Point& p) {
    int x=p.x, y=p.y, value=gamefield[x][y];
    for(int i=x+1; i<n&&gamefield[i][y]!=-1; i++) {
        updateGamefield(i,y,value);
        Point q (i,y);
        moves.push(q);
    }
    for(int i=x-1; i>=0&&gamefield[i][y]!=-1; i--) {
        updateGamefield(i,y,value);
        Point q (i,y);
        moves.push(q);
    }
    for(int i=y+1; i<n&&gamefield[x][i]!=-1; i++) {
        updateGamefield(x,i,value);
        Point q (x,i);
        moves.push(q);
    }
    for(int i=y-1; i>=0&&gamefield[x][i]!=-1; i--) {
        updateGamefield(x,i,value);
        Point q (x,i);
        moves.push(q);
    }
}

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    n = grid.size();

    int visited [n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] != 'X') {
                gamefield[i][j] = 101;
                visited[i][j] = 0;
            }
            else {
                gamefield[i][j] = -1;
                visited[i][j] = -1;
            }
        }
    }

    gamefield[startX][startY] = 0;
    Point start (startX,startY);
    moves.push(start);
    while(!moves.empty()) { 
        Point cur = moves.front();
        moves.pop();
        if(visited[cur.x][cur.y] == 0) {
            visited[cur.x][cur.y] = 1;
            addPoints(cur);
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << gamefield[i][j] << " ";
        }
        cout << endl;
    }

    return gamefield[goalX][goalY];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

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
