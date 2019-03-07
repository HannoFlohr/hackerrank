#include <bits/stdc++.h>

using namespace std;

class Point {
public:
    int x;
    int y;
    int d;
    Point() {}
    Point(int x,int y, int d) {this->x=x; this->y=y; this->d = d;}
};

int N;

bool validPoint(Point p) {
    if(p.x >= 0 && p.x < N && p.y >= 0 && p.y < N) return true;
    else return false;
}

int move(Point start, int a, int b) { 
    queue<Point> q;
    q.push(start);

    bool visited [N][N];
    memset(visited, false, sizeof visited);

    Point cur, p;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        if(cur.x == N-1 && cur.y == N-1) 
            return cur.d;

        visited[cur.x][cur.y] = true;

        p = Point(cur.x+a, cur.y+b, cur.d+1);
        if(!visited[p.x][p.y] && validPoint(p)) q.push(p);
        p = Point(cur.x+a, cur.y-b, cur.d+1);
        if(!visited[p.x][p.y] && validPoint(p)) q.push(p);
        p = Point(cur.x-a, cur.y+b, cur.d+1);
        if(!visited[p.x][p.y] && validPoint(p)) q.push(p);
        p = Point(cur.x-a, cur.y-b, cur.d+1);
        if(!visited[p.x][p.y] && validPoint(p)) q.push(p);

        if(a!=b) {
            p = Point(cur.x+b, cur.y+a, cur.d+1);
            if(!visited[p.x][p.y] && validPoint(p)) q.push(p);
            p = Point(cur.x+b, cur.y-a, cur.d+1);
            if(!visited[p.x][p.y] && validPoint(p)) q.push(p);
            p = Point(cur.x-b, cur.y+a, cur.d+1);
            if(!visited[p.x][p.y] && validPoint(p)) q.push(p);
            p = Point(cur.x-b, cur.y-a, cur.d+1);
            if(!visited[p.x][p.y] && validPoint(p)) q.push(p);
        }
    }

    //fail state
    return -1;
}

vector<vector<int>> knightlOnAChessboard(int n) {
    N = n;
    vector<vector<int>> results;
    vector<int> result;
    int a, b, moves;
    Point start (0,0,0);
    for(a=1; a<n; a++) {
        result.clear();
        for(b=1; b<n; b++) {
            if(b<a) { 
                result.push_back( results[b-1][a-1] );
                continue;
            }
            result.push_back( move(start,a,b) );
        }
        results.push_back(result);
    }
    return results;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
