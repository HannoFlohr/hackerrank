#include <bits/stdc++.h>

using namespace std;

vector<int> board (101);

struct Compare {
    bool operator()(const pair<int,int> &p1, const pair<int,int> &p2) const {
        if(p1.second == p2.second)
            return p1.first < p2.first;
        else 
            return p1.second > p2.second;
    }
};

void outPq(priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> q) {
    while(!q.empty()) {
        cout <<"("<< q.top().first << ","<<q.top().second<<") ";
        q.pop();
    }
    cout << endl;
}

int quickestWayUp() {
    int minSteps = numeric_limits<int>::max();
    pair<int,int> cur = make_pair(1,0);
    vector<bool> visited (101,false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> q;
    q.push(cur);
    while(!q.empty()) {
        cur = q.top();
        q.pop();
        visited[cur.first] = true;

        for(int i=1; i<=6; i++) {
            if(board[cur.first + i] == 100) { 
                minSteps = min(minSteps, cur.second + 1); }
            if(board[cur.first + i] < 100 && !visited[board[cur.first+i]])
                q.push(make_pair(board[cur.first+i],cur.second+1));
            
        }
        //outPq(q);
    }
    return minSteps == numeric_limits<int>::max() ? -1 : minSteps;
}

int main()
{
    int tests, ladders, snakes, a, b;
    cin >> tests;
    while(tests--) {
        for(int i=0; i<board.size(); i++)
            board[i] = i;

        cin >> ladders;
        vector<pair<int,int>> ladder (ladders);
        for(int i=0; i<ladders; i++) {
            cin >> a >> b;
            ladder.push_back(make_pair(a,b));
            board[a] = b;
        }
        cin >> snakes;
        vector<pair<int,int>> snake (snakes);
        for(int i=0; i<snakes; i++) {
            cin >> a >> b;
            snake.push_back(make_pair(a,b));
            board[a] = b;
        }

        cout << quickestWayUp() << endl;
    }
    return 0;
}
