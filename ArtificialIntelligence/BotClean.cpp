#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Point{
public:
    int r;
    int c;
    int dist;
    Point(int r, int c, int d) {
       this->r = r;
        this->c = c;
        this->dist = d;
    }
};

bool initialized = false;
vector<Point> dirt;

bool compareDist(Point p1, Point p2) {
    return p1.dist < p2.dist;
}

void updateDistances(int posr, int posc) {
    dirt.erase(dirt.begin());
    if(dirt.empty()) return;
    int d;
    for(int i=0; i<dirt.size(); i++) {
        d = abs( posr-dirt[i].r ) + abs(posc-dirt[i].c);
        dirt[i].dist = d;
    }
    sort(dirt.begin(), dirt.end(), compareDist);
}

void next_move(int posr, int posc, vector <string> board) {
    if(!initialized) {
        string s;
        int dist;
        for(int j=0; j<5; j++) {
            s = board[j];
            for(int i=0; i<5; i++) {
                if(s[i]=='d') {
                    dist = i + j;
                    Point p (j,i,dist);
                    dirt.push_back(p);
                }
            }
        }
        sort(dirt.begin(), dirt.end(), compareDist );
        initialized = true;
    }
    
    Point p = dirt[0];
    if(posc == p.c && posr == p.r) {
        cout << "CLEAN" << endl;
        updateDistances(posr, posc);
    }
    else if(posc < p.c) cout << "RIGHT" << endl;
    else if(posc > p.c) cout << "LEFT" << endl;
    else if(posr < p.r) cout << "DOWN" << endl;
    else if(posr > p.r) cout << "UP" << endl;
}

int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}