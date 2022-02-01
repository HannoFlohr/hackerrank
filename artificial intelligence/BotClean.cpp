#include<iostream>
#include<vector>
using namespace std;

//move bot toward the closest dirty cell
void next_move(int posr, int posc, vector <string> board) {
    if(board[posr][posc] == 'd') 
        cout << "CLEAN";
    else if(posc != 0 && board[posr][posc-1] == 'd') 
        cout << "LEFT";
    else if(posc != board[posr].size()-1 && board[posr][posc+1] == 'd') 
        cout << "RIGHT";
    else if(posr != 0 && board[posr-1][posc] == 'd')
        cout << "UP";
    else if(posr != board.size()-1 && board[posr+1][posc] == 'd')
        cout << "DOWN";
    else {
        const size_t pos = board[posr].find('d');
        if(pos!=string::npos) {
            if(pos<posc) cout << "LEFT";
            else cout << "RIGHT";
        }
        else {
            const size_t c = board.size() - posr - 1;
            for(size_t i{0}; i<c || i<board.size()-c; ++i) {
                if(posr+i+1 < board.size() && board[posr+i+1].find('d') != string::npos){
                    cout << "DOWN";
                    break;
                }
                else if(posr-i >= 0 && board[posr-i].find('d') != string::npos){
                    cout << "UP";
                    break;
                }
            }
        }
    }
    cout << endl;
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
//https://www.hackerrank.com/challenges/botclean/problem

//old approach, won all games, but with worse score
/*

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
*/ 