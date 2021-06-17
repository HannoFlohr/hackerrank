#include<bits/stdc++.h>
using namespace std;

char login[2001];
set<string> matched;

bool match(const vector<string> &passwords, const char *login, vector<int> &passwordIndices, bool &finished) {
    if(!*login) {
        finished = true;
        return true;
    }
    
    if(matched.find(login) != matched.end())
        return false;
        
    for(int i=0; i<passwords.size() && !finished; i++) {
        if(!strncmp(login, passwords[i].c_str(), passwords[i].size())) {
            passwordIndices.push_back(i);
            if(!match(passwords, login+passwords[i].size(), passwordIndices, finished) ) {
                passwordIndices.pop_back();
                matched.insert(login);
            }
        }
    }
    
    return finished;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, i;
    vector<int> passwordIndices; 
    bool finished;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<string> passwords (n);
        for(i=0; i<n; i++)
            cin >> passwords[i];
            
        cin >> login;
        
        passwordIndices.clear(); 
        finished = false;
    
        match(passwords, login, passwordIndices, finished);
        matched.clear();
        
        if(finished && passwordIndices.size()>0) {
            for(i=0; i<passwordIndices.size(); i++) {
                cout << passwords[passwordIndices[i]];
                if(i<passwordIndices.size()-1) cout << " ";
            }
            cout << endl;
        }
        else
            cout << "WRONG PASSWORD" << endl;
    }
    
    return 0;
}
//https://www.hackerrank.com/challenges/password-cracker/problem?isFullScreen=false