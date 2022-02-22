#include<bits/stdc++.h>
using namespace std;

const vector<unsigned short> die_sides = {0,1,2,3,4,5,6,7,8,9};
//const vector<unsigned short> new_die =   {0,0,0,0,1,1,1,1,1,1};
//const vector<unsigned short> empty_die = {1};
const string new_die = "0000111111";
const string empty_die = "";

vector<vector<unsigned short>> digits_of_square;

bool testDiceAgainstSquares(const vector<unsigned short>& dice_digits) {
    for(auto square:digits_of_square) 
        for(unsigned short i=0; i<9; i++) {
            if(square[i] == 0) 
                continue;
                
            if(i==6) {
                if(square[i] > (dice_digits[6] + dice_digits[9])) 
                    return false;
            }
            else    
                if(square[i] > dice_digits[i])
                    return false;
        }
    
    return true;
}

bool testDiceAgainstSquares(const string& dice) {
    vector<unsigned short> dice_digits(10);
    for(unsigned short i=0; i<10; i++)
        dice_digits[i] = (int)dice[i] - '0';
        
    //for(auto a:dice_digits)cerr<<a<<" ";cerr<<endl;
    return testDiceAgainstSquares(dice_digits);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unsigned short  n, dice, max_square;
    cin >> n >> dice; 
    
    //compute all squares, taking care of 6=9 and that the order is not important
    //e.g. 7*7=49 -> 46; 9*9=81 -> 18
    //result: 1 4 6 16 25 36 46 18 112 144 166 225 256 268 234 136 448 567 667 267 478 
    //        148 24 68 156 266 366 444 125 168 467 468 116 26 34 14 5 47 246 346 127 666 
    //        66 356 167 236 677 48 124 247 688 56 566 447 126 128 446 466 368 0 12 44 188 
    //        123 445 456 668 146 488 367 678 348 244 336 556 224 458 568 344 245 248 67 45
    vector<unsigned short> squares;
    for(unsigned short i=1; i<=n; i++) {
        auto square = i*i;
        
        if(i==n) max_square = square;
        
        vector<unsigned short> digits; 
        for(unsigned short j=0; j<3; j++) {
            auto digit = square %10;
            square /= 10;
            
            if(digit==9) digit=6;
            digits.push_back(digit);
        }
        
        sort(digits.begin(), digits.end());
        square = digits[0]*100 + digits[1]*10 + digits[2];
        if(find(squares.begin(),squares.end(), square) == squares.end())
            squares.push_back(square);
    }
    sort(squares.begin(),squares.end());  //maybe?
    
    for(auto s:squares) {
        vector<unsigned short> digits (10,0); 
        while(s>0) {
            auto digit = s %10;
            s /= 10;
            
            if(digit==9) digit=6;
            digits[digit]++;
        }
        
        digits_of_square.push_back(digits);
    }
    
    //for(auto s:squares)cerr<<s<<" ";cerr<<endl; 
    //for(auto d:digits_of_square){for(auto x:d)cerr<<x<<"";cerr<<endl;}

    unsigned valid_solutions = 0;
    
    /*string start;
    string end;
    unsigned short base = 2;
    if(dice==1) {
        start = "0000111111";
        end =   "1111110000";
    }
    else if(dice==2) {
        start = "0000222222";
        end =   "2222220000";
        base = 3;
    }
    else { //if(dice==1) {
        start = "0000333333";
        end =   "3333330000";
        base = 4;
    }
    
    if(dice==1) {
        do{
            if( testDiceAgainstSquares(start) )
                valid_solutions++;
        } while(next_permutation(start.begin(),start.end()));
    }
    else {
        
    }*/
    
    vector<unsigned short> die1;
    vector<unsigned short> die2;
    vector<unsigned short> die3;
    string die1permutation = new_die;
    string die2permutation = new_die;
    string die3permutation = new_die;

    do {
        die1.clear();
        for(size_t i=0; i<10; i++)
            if(die1permutation[i] == '1') 
                die1.push_back(die_sides[i]);
        
        vector<unsigned short> dice_digits (10,0);
        for(auto d:die1) dice_digits[d]++;
            
        die2permutation = (dice>=2 ? die1permutation : empty_die);
        do {
            die2.clear();
            if(die2permutation != "") {
                for(size_t i=0; i<die2permutation.size(); i++)
                    if(die2permutation[i] == '1') 
                        die2.push_back(die_sides[i]);
                        
            if(die2permutation != "") 
                for(auto d:die2) dice_digits[d]++;
                
            //if the max square needed is at least 100, we need to have at least 1 '0' at this point         
            if(max_square>=100)
                if(!any_of(die1permutation.begin(),die1permutation.end(), [](const auto& d){return d=='0';} ) &&
                    !any_of(die2permutation.begin(),die2permutation.end(), [](const auto& d){return d=='0';} ))
                    continue;
                
                //if the max square needed is at least 144, we need to have at least 1 '4' at this point  
            if(max_square>=144)
                if(!any_of(die1permutation.begin(),die1permutation.end(), [](const auto& d){return d=='4';} ) &&
                    !any_of(die2permutation.begin(),die2permutation.end(), [](const auto& d){return d=='4';} ))
                    continue;       
            }
            die3permutation = (dice==3 ? die2permutation : empty_die);
            do {
                die3.clear(); 
                if(die3permutation != "") {
                    for(size_t i=0; i<die3permutation.size(); i++)
                        if(die3permutation[i] == '1') 
                            die3.push_back(die_sides[i]);
                }
                
                if(die3permutation != "")
                    for(auto d:die3) dice_digits[d]++; 
                   
                //for(auto z:dice_digits)cerr<<z<<" ";cerr<<endl;
     
                if( testDiceAgainstSquares(dice_digits) )
                    valid_solutions++; 
                    
                if(die3permutation != "")
                    for(auto d:die3) dice_digits[d]--;      
                
            } while(next_permutation(die3permutation.begin(),die3permutation.end()));
            
            if(die2permutation != "")
                for(auto d:die2) dice_digits[d]--;
            
        } while(next_permutation(die2permutation.begin(),die2permutation.end()));    
    } while(next_permutation(die1permutation.begin(),die1permutation.end())); 
    
    cout<< valid_solutions <<endl;
    return 0;
}


//https://www.hackerrank.com/contests/projecteuler/challenges/euler090/problem?isFullScreen=true




//first aproach (12/43 test cases successful, 9 timeouts, rest wrong answer
/*#include<bits/stdc++.h>
using namespace std;

const vector<unsigned short> die_sides = {0,1,2,3,4,5,6,7,8,9};
//const vector<unsigned short> new_die =   {0,0,0,0,1,1,1,1,1,1};
//const vector<unsigned short> empty_die = {1};
const string new_die = "0000111111";
const string empty_die = "1";

bool valid(const vector<unsigned short>& digits, const unsigned short& max_square) {
    if(digits[1] < 1)
        return false;
    if(max_square >= 4 && digits[4] < 1) 
        return false;
    if(max_square >= 25 && (digits[2] < 1 || digits[5] < 1)) 
        return false;
    if(max_square >= 36 && digits[3] < 1) 
        return false;
    if(max_square >= 81 && digits[8] < 1) 
        return false;
    if(max_square >= 100 && digits[0] < 2) 
        return false;
    if(max_square >= 144 && digits[4] < 2) 
        return false;
        
    return true;
}

vector<unsigned short> getSorted(unsigned short a, unsigned short b, unsigned short c) {
    vector<unsigned short> v = {a,b,c};
    if(v[0]>v[1]) swap(v[0],v[1]);
    if(v[1]>v[2]) swap(v[1],v[2]);
    if(v[0]>v[1]) swap(v[0],v[1]);
    return v;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unsigned short  n, dice, max_square;
    cin >> n >> dice; 
    
    //compute all squares, taking care of 6=9 and that the order is not important
    //e.g. 7*7=49 -> 46; 9*9=81 -> 18
    //result: 1 4 6 16 25 36 46 18 112 144 166 225 256 268 234 136 448 567 667 267 478 
    //        148 24 68 156 266 366 444 125 168 467 468 116 26 34 14 5 47 246 346 127 666 
    //        66 356 167 236 677 48 124 247 688 56 566 447 126 128 446 466 368 0 12 44 188 
    //        123 445 456 668 146 488 367 678 348 244 336 556 224 458 568 344 245 248 67 45
    vector<unsigned short> squares;
    for(unsigned short i=1; i<=n; i++) {
        auto square = i*i;
        
        if(i==n) max_square = square;
        
        vector<unsigned> digits; 
        for(unsigned j=0; j<3; j++) {
            auto digit = square %10;
            square /= 10;
            
            if(digit==9) digit=6;
            digits.push_back(digit);
        }
        
        sort(digits.begin(), digits.end());
        square = digits[0]*100 + digits[1]*10 + digits[2];
        if(find(squares.begin(),squares.end(), square) == squares.end())
            squares.push_back(square);
    }
    sort(squares.begin(),squares.end());  //maybe?!
    
    unsigned int valid_solutions = 0;
    
    vector<unsigned short> die1;
    vector<unsigned short> die2;
    vector<unsigned short> die3;
    string die1permutation = new_die;
    string die2permutation = new_die;
    string die3permutation = new_die;
    
    do {
        die1.clear();
        for(size_t i=0; i<10; i++)
            if(die1permutation[i] == '1') 
                die1.push_back(die_sides[i]);
            
        die2permutation = (dice>=2 ? die1permutation : empty_die);
        do {
            die2.clear();
            for(size_t i=0; i<die2permutation.size(); i++)
                if(die2permutation[i] == '1') 
                    die2.push_back(die_sides[i]);
            
            //if the max square needed is at least 100, we need to have at least 1 '0' at this point         
            if(max_square>=100)
                if(!any_of(die1permutation.begin(),die1permutation.end(), [](const auto& d){return d==0;} ) &&
                   !any_of(die2permutation.begin(),die2permutation.end(), [](const auto& d){return d==0;} ))
                   continue;
            
            //if the max square needed is at least 144, we need to have at least 1 '4' at this point  
            if(max_square>=144)
                if(!any_of(die1permutation.begin(),die1permutation.end(), [](const auto& d){return d==4;} ) &&
                   !any_of(die2permutation.begin(),die2permutation.end(), [](const auto& d){return d==4;} ))
                   continue;       
            
            die3permutation = (dice==3 ? die2permutation : empty_die);
            do {
                die3.clear();
                for(size_t i=0; i<die3permutation.size(); i++)
                    if(die3permutation[i] == '1') 
                        die3.push_back(die_sides[i]);
                        
                vector<unsigned short> dice_digits (10,0);
                for(auto d:die1) dice_digits[d]++;
                for(auto d:die2) dice_digits[d]++;
                for(auto d:die3) dice_digits[d]++;
                
                if( !valid(dice_digits, max_square) )
                    continue;
                    
                vector<unsigned short> valid_squares;
                for(auto d1:die1){
                    if(d1==9) d1=6;
                    
                    for(auto d2:die2) {
                        if(d2==9) d2=6;
                        
                        for(auto d3:die3) {
                            if(d3==9) d3=6;
                            
                            vector<unsigned short> d_sorted = getSorted(d1, d2, d3);
                            
                            auto sortedSquare = 100*d_sorted[0] + 10*d_sorted[1] + d_sorted[2];
                            auto findMatch = find(squares.begin(), squares.end(), sortedSquare);
                            if(findMatch != squares.end())
                                valid_squares.push_back(sortedSquare);
                        }
                    }
                }
                
                if(valid_squares.size() < squares.size())
                    continue;
                    
                sort(valid_squares.begin(), valid_squares.end());
                
                valid_squares.erase( unique(valid_squares.begin(), valid_squares.end()), valid_squares.end());
                if(squares == valid_squares) 
                    valid_solutions++;
                    
                /*auto lastItem =  unique(valid_squares.begin(), valid_squares.end());
                auto toDelete = squares;
                for(auto v = valid_squares.begin(); v!=lastItem; v++) {
                    auto findMatch = find(toDelete.begin(),toDelete.end(),*v);
                    toDelete.erase(findMatch);
                }
                
                if(toDelete.empty())
                    valid_solutions++;*/
                
            } while(next_permutation(die3permutation.begin(),die3permutation.end()));
        } while(next_permutation(die2permutation.begin(),die2permutation.end()));    
    } while(next_permutation(die1permutation.begin(),die1permutation.end()));
    
    cout<< valid_solutions <<endl;
    return 0;
}*/