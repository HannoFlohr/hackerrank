#include <bits/stdc++.h>

using namespace std;

class Space {
public:
    int x, y, length;
    bool dir;
    Space(int x,int y, int len, bool dir):x(x),y(y),length(len),dir(dir) {}
};

array<char,100> finalGrid;

void gridOut(array<char,100> grid) {
    for(int y=0; y<10; y++) {
        for(int x=0; x<10; x++) {
            cout << grid[x+10*y] << " ";
        }
        cout << endl;
    }
}
void spacesOut(deque<Space> spaces) {
    for(auto s:spaces) {
        cout << s.x << " " << s.y << " | " <<s.length << " | "<<s.dir<<endl; 
    }
}

//needed to sort the Spaces by size
struct compare_space {
    bool operator()(const Space& first, const Space& second) {
        return first.length > second.length;
    }
};
//needed to sort the words by length
struct compare {
    bool operator()(const string& first, const string& second) {
        return first.size() > second.size();
    }
};

void findSpacesInCrossword(deque<Space>& spaces, array<char,100> grid) {
    int empty = 0;
    for(int direction=0; direction<2; direction++) {
        for(int i=0; i<10; i++) {
            for(int j=0; j<11; j++) {
                if(j<10 && direction==0 && grid[i+10*j]=='-' )
                    empty++;
                else if(j<10 && direction==1 && grid[j+10*i]=='-' )
                    empty++;
                else {
                    if(empty>1) {
                        if(direction==0)
                            spaces.push_back(Space(i,j-empty,empty,direction));
                        if(direction==1)
                            spaces.push_back(Space(j-empty,i,empty,direction));
                    }
                    empty = 0;
                }
            }
        }
    }
}

vector<string> putWords(string w) {
    vector<string> words;
    while(!w.empty()) {
        int i = w.find_first_of(';');
        words.push_back(w.substr(0,i));
        w.erase(0,i==string::npos ? i : i+1);
    }
    return words;
}

void solveCrossword(deque<Space>& spaces, vector<string>& words, 
                        array<char,100>& grid ) {
    for(int i=0; i<words.size(); i++) { 
        if(words[i].size() != spaces[0].length) continue;
        
        array<char,100> newGrid = grid; 

        int j;
        for(j=0; j<words[i].size(); j++) {
            int n;
            if(spaces[0].dir==1) {
                n = spaces[0].x+j + spaces[0].y*10;
                if(grid[n] != '-' && grid[n] != words[i].at(j) )
                    break;
            }
            else {
                n = spaces[0].x + (spaces[0].y+j)*10;
                if(grid[n] != '-' && grid[n] != words[i].at(j) )
                    break;
            }
            newGrid[n] = words[i].at(j);
        }

        if(j!=words[i].size()) continue; 
        
        if(spaces.size()==1) {
            finalGrid = newGrid;
            return;
        }

        deque<Space> remainingSpaces = spaces;
        remainingSpaces.pop_front();
        vector<string> remainingWords = words;
        remainingWords.erase(remainingWords.begin()+i);
        solveCrossword(remainingSpaces,remainingWords,newGrid);
    }
}

// Complete the crosswordPuzzle function below.
vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    vector<string> w;
    w = putWords(words);
    compare c;
    sort(w.begin(),w.end(),c);

    array<char,100> grid;
    for(int y=0; y<10; y++) {
        for(int x=0; x<10; x++) {
            grid[x+10*y] = crossword[y][x];
        }
    }

    deque<Space> spaces;
    findSpacesInCrossword(spaces,grid);
    compare_space cs;
    sort(spaces.begin(),spaces.end(),cs);
  
    solveCrossword(spaces, w, grid);

    for(int y=0; y<10; y++) {
        for(int x=0; x<10; x++) {
            crossword[y][x] = finalGrid[x+10*y];
        }
    }
    return crossword;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
