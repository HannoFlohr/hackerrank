#include <bits/stdc++.h>

using namespace std;

stack<char> b;

void push_bracket(const char& c) { 
    b.push(c);
}

bool pop_bracket(const char& c) { 
    if(b.empty() ) 
        return false;
    else {
        char reverse;
        if(c==')') reverse = '(';
        else if(c==']') reverse = '[';
        else if(c=='}') reverse = '{'; 

        if(b.top() == reverse) { 
            b.pop();
            return true;
        }
        else   
            return false;
    } 
}

// Complete the isBalanced function below.
string isBalanced(string s) { 
    //even number of brackets needed
    if(s.size() % 2 != 0) return "NO";

    for(int i=0; i<s.size(); i++) {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{') {
            if(i == s.size()-1) 
                return "NO";
            else 
                push_bracket(s[i]); 
        }
        else {
            if(!pop_bracket(s[i])) return "NO";
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
