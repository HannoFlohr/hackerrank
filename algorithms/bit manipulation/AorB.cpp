#include <bits/stdc++.h>
using namespace std;

/*  we have 8 possible triplets for each digit of A, B and C
    0 0 0 0 1 1 1 1     A
    0 0 1 1 0 0 1 1     B
    0 1 0 1 0 1 0 1     C

    x c c x c ? c ?     op: c=change, x=no change, ?=optional change
    0 0 0 0 0 0 0 0     A
    0 1 0 1 0 1 0 1     B
    0 1 0 1 0 1 0 1     C
    0 1 1 0 1 0 2 0     costs for mandatory changes
    0 0 0 0 0 2 0 1     costs for optional changes, if done 
*/
const vector<int> mandatoryChange = {0, 3, 0, 3, 0, 5, 0, 7};
const vector<int> mandatoryCost   = {0, 1, 1, 0, 1, 0, 2, 0};
const vector<int> optionalChange  = {0, 1, 2, 3, 4, 3, 6, 3};
const vector<int> optionalCost    = {0, 0, 0, 0, 0, 2, 0, 1};

//returns the int value for hexadecimal char 'c'
int toInt(const char &c) {
    return (c >= 'A' ? 10+c-'A' : c-'0');
}
//returns the hexadecimal char for int 'i'
char toChar(const int &i) {
    return static_cast<char>(i<10 ? '0'+i : 'A'+(i-10));
}

bool solve(int &k, string &a, string &b, const string &c, const bool mandatory) {
    const int size = a.size();
    for(int i=0; i<size; i++) {
        //get int values for current position
        const int aValue = toInt(a[i]);
        const int bValue = toInt(b[i]);
        const int cValue = toInt(c[i]);

        int aValueNew = 0, bValueNew = 0;

        for(int j=3; j>=0; j--) {
            //compute key for current operation
            int key = 0;
            key |= (1 & (aValue>>j)) << 2;
            key |= (1 & (bValue>>j)) << 1;
            key |= 1 & (cValue>>j);

            //set change and cost for current operation
            int change, cost;
            mandatory ? change = mandatoryChange[key] : change = optionalChange[key];
            mandatory ? cost = mandatoryCost[key] : cost = optionalCost[key];

            if(k < cost) {
                //if cost exceeds the remaining 'k' for a mandatory change
                //there is no solution
                if(mandatory)
                    return false;
                change = key;
            }
            else 
                k -= cost;
            
            //change to new value
            aValueNew |= (1 & (change>>2)) << j;
            bValueNew |= (1 & (change>>1)) << j;
        }

        a[i] = toChar(aValueNew);
        b[i] = toChar(bValueNew);
    }
    return true;
}

//add '0's to left of string if size of string<size
void pad(string &s, const int size) {
    if(s.size() < size)
        s = string(size-s.size(), '0') + s;
}

//remove leading '0's of string
void unpad(string &s) {
    if(s.size() < 2) return;
    while(s[0] == '0' && s.size() > 1) s.erase(0, 1);
}

int main()
{
    int q, k, size;
    string a, b, c;
    cin >> q;
    while(q--) {
        cin >> k >> a >> b >> c;

        //equalize string lengths
        size = max(a.size(),max(b.size(),c.size()));
        pad(a,size);
        pad(b,size);
        pad(c,size);

        if(!solve(k, a, b, c, true)) {
            cout << "-1" << endl;
            continue;
        } 

        solve(k, a, b, c, false);
        unpad(a);
        unpad(b);
        cout << a << endl << b << endl;
    }

    return 0;
}
//https://www.hackerrank.com/challenges/aorb/problem