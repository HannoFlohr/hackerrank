#include <bits/stdc++.h>

using namespace std;

int palindromeIndex(string s) {  
    int first=0, last=s.size()-1, next, previous;
    bool palindrome;
    while(first < last) { 
        if(s[first] != s[last]) {
            next = first+1; previous=last;
            palindrome = true;
            while(next < previous) {
                if(s[next] != s[previous]) {
                    palindrome = false;
                    break;
                }
                next++;
                previous--;
            }
            if(palindrome) return first;

            palindrome = true;
            next=first; previous=last-1;
            while(next < previous) {
                if(s[next] != s[previous]) {
                    palindrome = false;
                    break;
                }
                next++;
                previous--;
            }
            if(palindrome) return last;
            else return -1;
        }
        first++;
        last--;
    }
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
