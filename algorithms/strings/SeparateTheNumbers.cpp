#include <bits/stdc++.h>

using namespace std;

void separateNumbers(string s) {
    unsigned long long int cur, size, j; 
    string next, check;
    for(int d=1; d<=s.size()/2; d++) { 
        cur = stoull( s.substr(0,d) );
        j = d;
        while(j<s.size()) { 
            next = to_string( ++cur ); 
            size = next.size();
            if(j+size > s.size()) break;
            check = s.substr(j,size);
            if(check != next) break;

            if(check == next && j+size==s.size()) {
                cout<< "YES " << s.substr(0,d) <<endl;
                return;
            }

            j += size;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}
