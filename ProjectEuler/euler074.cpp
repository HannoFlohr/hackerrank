#include<bits/stdc++.h>
using namespace std;

const int MAXLOOPS = 60;

//to precompute the factorials for digits 0..9
vector<int> factorials (10);
void initFactorials() {
    factorials[0] = 1;
    for(int i=1; i<=9; i++)
        factorials[i] = factorials[i-1] * i;
}

/*
counts the digits of the given number n and returns a number resembling that count
e.g.    0   -> 1
        2   -> 100
        9   -> 1000000000
        771 -> 20000010
numbers with the same count of digits are permutations of each other
*/
unsigned countDigits(unsigned int n) {
    unsigned digits = 0, digit, position;
    while(n>0) {
        digit = n%10;
        n /= 10;
        
        //as the digits are used to determine the factorials and 0!=1!
        //handle 0 and 1 the same way 
        if(digit == 1) 
            digit = 0;
        
        position = 1;
        for(unsigned int i=0; i<digit; i++)
            position *= 10;
            
        digits += position;
    }
    return digits;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    initFactorials();

    //memory for known loop sizes, initialized with 4 given examples
    map<unsigned, unsigned> known_loop_sizes;
    known_loop_sizes[countDigits(145)] = 2;
    known_loop_sizes[countDigits(169)] = 4;
    known_loop_sizes[countDigits(871)] = 3;
    known_loop_sizes[countDigits(872)] = 3;
    
    unsigned int t, n, l, currentDigits, current_number, factorials_sum, result_counter;
    vector<int> loop;
    cin >> t;
    while(t--) {
        cin >> n >> l;
        result_counter = 0;
        
        //look for loops from 0..n
        for(int i=0; i<=n; i++) {
            //get the digit count for the current number
            currentDigits = countDigits(i);
            //if unknown digit count, determine loop length
            if(known_loop_sizes.count(currentDigits) == 0) {
                loop.clear();
                current_number = i;
                
                //compute factorial sum for the current number to get next element in loop
                //if that element is already in loop -> break
                //if the loop is already longer than the given max loop size -> break
                while( find(loop.begin(),loop.end(),current_number) == loop.end() && loop.size() <= MAXLOOPS) {
                    loop.push_back(current_number);
                    
                    //compute sum of factorials of the current number
                    factorials_sum = 0;
                    do {
                        factorials_sum += factorials[current_number % 10];
                        current_number /= 10;
                    } while(current_number>0); 
                    
                    current_number = factorials_sum;
                }
                
                //add the loop length for the current digit count to the memory
                known_loop_sizes[currentDigits] = loop.size();
            }
            
            //check if the current number has the desired loop length
            bool has_correct_loop_size = (known_loop_sizes[currentDigits] == l);
            //to avoid false negatives/positives the numbers that link back to themselves need special check
            if(i==145) has_correct_loop_size = (l==1);
            if(i==169||i==1454||i==363601) has_correct_loop_size = (l==3);
            if(i==871||i==872||i==45361||i==45362) has_correct_loop_size = (l==2);
            
            if(has_correct_loop_size) {
                result_counter++;
                cout << i << " ";
            }
        }//end for
        
        if(result_counter == 0)
            cout << -1;
        cout << endl;
    }//end while
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler074/problem