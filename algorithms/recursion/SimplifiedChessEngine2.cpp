#include <bits/stdc++.h>
#include <cwctype>
using namespace std;

typedef pair<int,int> position;

struct piece {
    char type, player; // player: 0=white 1=black
    piece() : type(-1), player(-1) {};
    piece(char t, char p) : type(t), player(p) {};
};

//the 4x4 game board
piece board[4][4];
//maximum moves until white player has to win
int max_moves;

//queen move set
const int queen_moves_x[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int queen_moves_y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//knight move set
const int knight_moves_x[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int knight_moves_y[] = {1, -1, 2, -2, -2, 2, -1, 1};
//bishop move set
const int bishop_moves_x[] = {-1, -1, 1, 1};
const int bishop_moves_y[] = {-1, 1, -1, 1};
//rook move set
const int rook_moves_x[] = {1, -1, 0, 0};
const int rook_moves_y[] = {0, 0, 1, -1};
//pawn move set
const int pawn_moves_x[] = {-1, 0, 1};
const int pawn_white_moves_y[] = {1, 1, 1};
const int pawn_black_moves_y[] = {-1, -1, -1};

void print_board() {
    cerr << "current board: " << endl;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(board[i][j].player == 0)
                cerr << char( tolower(board[i][j].type) );
            else if(board[i][j].player == 1)
                cerr << (board[i][j].type);
            else 
                cerr << '.';
        }
        cerr<<endl;
    }
}

//returns true if a move to board[x][y] is a valid move (in bounds and not occupied by a piece of the 'player')
bool isValidMove(const int &x, const int &y, const int &player) {
    return ( x>=0 && x<4 && y>=0 && y<4 && board[x][y].player != player );
}

//returns true if board[x][y] is empty
bool isEmpty(const int &x, const int &y) {
    return ( x>=0 && x<4 && y>=0 && y<4 && board[x][y].player == -1 );
}

//generates the moves for the piece at board[i][j] according to its move set
vector<position> generateMoves(const int &i, const int &j, const int &player) {
    vector<position> moves;
    int x, y;

    if(board[i][j].type == 'Q') {//generate moves for a queen
        for(int direction=0; direction<8; direction++)
            for(int length=1; length<4; length++) {
                x = i + queen_moves_x[direction] * length;
                y = j + queen_moves_y[direction] * length;
                if(isValidMove(x, y, player))
                    moves.push_back(make_pair(x,y));
                if(!isEmpty(x,y))
                    break;
            }
    }
    else if(board[i][j].type == 'N') {//generate moves for a knight
        for(int direction=0; direction<8; direction++) {
            x = i + knight_moves_x[direction];
            y = j + knight_moves_y[direction];
            if(isValidMove(x, y, player))
                moves.push_back(make_pair(x,y));
        }
    }
    else if(board[i][j].type == 'B') {//generate moves for a bishop
        for(int direction=0; direction<4; direction++)
            for(int length=1; length<4; length++) {
                x = i + bishop_moves_x[direction] * length;
                y = j + bishop_moves_y[direction] * length;
                if(isValidMove(x, y, player))
                    moves.push_back(make_pair(x,y));
                if(!isEmpty(x, y))
                    break;
            }
    }
    else if(board[i][j].type == 'R') {//generate moves for a rook
        for(int direction=0; direction<4; direction++)
            for(int length=1; length<4; length++) {
                x = i + rook_moves_x[direction] * length;
                y = j + rook_moves_y[direction] * length;
                if(isValidMove(x, y, player))
                    moves.push_back(make_pair(x,y));
                if(!isEmpty(x, y))
                    break;
            }
    }
    else if(board[i][j].type == 'P') { //generate moves for a pawn
        for(int direction=0; direction<3; direction++) {
            x = i + pawn_moves_x[direction];
            if(board[i][j].player == 0)
                y = j + pawn_white_moves_y[direction];
            else 
                y = j + pawn_black_moves_y[direction];
            if(isValidMove(x, y, player))
                moves.push_back(make_pair(x,y));
        }
    }
    return moves;
}

//returns true if the move to position (x,y) kills the oponnents queen
bool killsQueen(const int &x, const int &y, const int &player) {
    return ( x>=0 && x<4 && y>=0 && y<4 && board[x][y].player == (player ^ 1) && board[x][y].type == 'Q' );
}

//returns true if there is a valid move that can kill the oponnents queen
bool isWinnable(const int &player) {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(board[i][j].player == player) {
                vector<position> moves = generateMoves(i,j,player);

                for(size_t k=0; k<moves.size(); k++) 
                    if(killsQueen(moves[k].first, moves[k].second, player))
                        return true;
            }
        }
    }
    return false;
}

//declaration needed for tryNextMoves(..); see below
bool winnable(const int &cur_player, const int &move);

//loops through possible moves and checks if the game is winnable for all new valid board setups
bool tryNextMoves(const int &player, const int &move) {
    int x, y;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(board[i][j].player == player) {
                vector<position> moves = generateMoves(i, j, player);
                for(size_t k=0; k<moves.size(); k++) {
                    x = moves[k].first;
                    y = moves[k].second;

                    piece board_copy[4][4];
                    memcpy(board_copy, board, sizeof board);
                    assert(board[x][y].player != board[i][j].player);
                    if(board[x][y].type == 'Q')
                        return player ^ 1;
                    board[x][y] = board[i][j];
                    board[i][j] = piece();
                    if(winnable(player^1, move+1) != player)
                        return player ^ 1;
                    memcpy(board, board_copy, sizeof board);
                }
            }
        }
    }
    return player;
}

//checks if white can win with the current board setup
bool winnable(const int &cur_player, const int &move) {
    if(move >= max_moves)
        return false;

    //check if either player can kill the others queen
    if(cur_player == 0) { //white 
        if(isWinnable(cur_player))
            return true;
    }
    else //black
        if(isWinnable(cur_player))
            return false;
    
    //no winning situation, go deeper
    return tryNextMoves(cur_player, move);
}

int main()
{
    int games, white, black;
    char t, x, y;
    cin >> games;
    while(games--) {
        cin >> white >> black >> max_moves; 

        //initialize the board
        for(int i=0; i<4; i++) 
            for(int j=0; j<4; j++) 
                board[i][j] = piece();

        for(int i=0; i<white; i++) {
            cin >> t >> x >> y;
            board[x-'A'][y-'1'] = piece(t,0);
        }
        for(int i=0; i<black; i++) {
            cin >> t >> x >> y;
            board[x-'A'][y-'1'] = piece(t,1);
        }

        cout << (winnable(0,0) ? "YES" : "NO") << endl;    
    }
    return 0;
}
//https://www.hackerrank.com/challenges/simplified-chess-engine-ii/problem