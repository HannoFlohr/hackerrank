#include<bits/stdc++.h>
using namespace std;

//https://en.wikipedia.org/wiki/Addition_chain
typedef vector<int> AdditionChain;

//cache for addition chain values
static map<int, AdditionChain> cache;

//dfs using brauer chain
//https://en.wikipedia.org/wiki/Addition_chain#Brauer_chain
bool dfs_brauer(AdditionChain &ac, int k, int max_d) {
    if(ac.size() > max_d)
        return false;
        
    auto last = ac.back();
    for(int i=0; i<ac.size(); i++) {
        auto sum = ac[ac.size()-1-i] + last;
        if(sum == k)
            return true;
            
        ac.push_back(sum);
        if(dfs_brauer(ac, k, max_d))
            return true;
        
        ac.pop_back();
    }
    
    return false;
}

AdditionChain createChain(int k) {
    //check if value is cached already
    auto check = cache.find(k);
    if(check != cache.end())
        return check->second;
        
    //iterative search
    AdditionChain ac;
    int d = 1;
    while(true) {
        ac = {1};
        
        if(dfs_brauer(ac, k, d))
            break;
        
        d++;
    }
    
    cache[k] = ac;
    return ac;
}

void printChain(const AdditionChain &ac) {
    cout << (ac.size()-1) << endl;
    int a,b,c;
    for(int i=1; i<ac.size(); i++) {
        a = ac[i];
        b = ac[i-1];
        c = a - b;
        cout << "n";
        if(b>1) cout << "^" << b;
        cout << " * n";
        if(c>1) cout << "^" << c;
        cout << " = n^" << a << endl;
    } 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, k;
    cin >> t;
    while(t--) {
        cin >> k;
        
        AdditionChain ac = createChain(k);
        ac.push_back(k);
        printChain(ac);
    }
    
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler122/problem