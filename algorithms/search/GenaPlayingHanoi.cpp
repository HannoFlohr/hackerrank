#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> setVector(int x) {
    vector<int> v (n);
    for(int i=n-1; i>=0; i--) {
        v[i] = x % 4;
        x /= 4;
    }
    return v;
}

int indexFor(const vector<int>& v) {
    int index = 0;
    for(auto x:v) index = 4 * index + x;
    return index;
}

int main()
{
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> states (pow(4,n),-1);
    queue<int> q;
    q.push(0);
    states[0] = 0;
    while(!q.empty()) {
        int x = q.front(); 
        q.pop();
        vector<int> state = setVector(x); 
        bool used [4] = {false};
        for(int i=0; i<n; i++) 
            if(!used[state[i]]) {
                int y = state[i];
                used[state[i]] = true;
                for(int j=0; j<4; j++) 
                    if(!used[j]) {
                        state[i] = j;
                        int z = indexFor(state);
                        if(states[z] == -1) {
                            states[z] = states[x] + 1;
                            q.push(z);
                        }
                    }
                state[i] = y;
            }
    }
    
    cout << states[ indexFor(a) ] << endl;

    return 0;
}
