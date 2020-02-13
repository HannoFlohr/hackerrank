#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const ull MAX = 1000000000000000000ULL;

//returns the digit length of number n
int digits(ull n) {
    int d = 0;
    while(n!=0) {
        d++;
        n /= 10;
    }
    return d;
}      

int main()
{
    //precompute all strange numbers
    ull strangeNumbers[500];
    ull head = 0, tail = 0, number, candidate;
    set<ull> storage;
    int length;
	//0..9 are strange numbers
    for(int i=0; i<10; i++) {
        strangeNumbers[tail++] = i;
        storage.insert(i);
    }
	/*	X is a strange number
		Candidate(i) = length(X) + i;  i >= 0 (i=0..2 is enough for this case)
		-> candidates for strange numbers for X*candidate(i) for all i 
		if a candidate has the correct length it is a strange number 
	*/
    while(head<tail) {
        number = strangeNumbers[head++];
        length = digits(number);

        for(int i=length; i<=length+2; i++) {
            candidate = number * i;
            if(storage.find(candidate) == storage.end() &&
                digits(candidate)==i && candidate <= MAX) {
                    strangeNumbers[tail++] = candidate;
                    storage.insert(candidate);
                }
        }
    
    }

    ull l,r,count;
    int t;
    cin >> t;
    while(t--) {
        cin >> l >> r;
        count = count_if(strangeNumbers, strangeNumbers+tail, [l,r](ull i){return i >= l && i <= r;} );
        cout << count << endl;
    }
    return 0;
}
https://www.hackerrank.com/challenges/strange-numbers/problem