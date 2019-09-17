#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
using namespace std;

const int MAXN = 1000001;

int main() {
    bool prime[MAXN];
    memset(prime, true, sizeof(prime));
    for(int p=2; p*p<=MAXN; p++) 
        if(prime[p] == true) 
            for(int i=p*p; i<=MAXN; i+=p) 
                prime[i] = false; 

    int n, k;
    cin >> n >> k;
    
    string s = "";
    string result = "";
    vector<int> primes;

    for(int i=1000; i<=n; i++) {
        if(!prime[i]) 
            continue;

        s = to_string(i);
        do {
            if(prime[ stoi(s) ]) 
                primes.push_back( stoi(s) );
        }   while(next_permutation(s.begin(),s.end()) );

        //cerr << i << " " << primes.size() << " | ";
        /*if(i==1487) {
            cerr << primes.size() << endl;
            for(auto a:primes) cerr << a << " "; cerr << endl;
        }*/

        if(primes.size() == k) {
            //for(auto a:primes) cerr << a << " "; cerr<<endl; 
            if( (primes[1]-primes[0]) == (primes[2]-primes[1]) ) {
                for(auto p : primes)
                    result += to_string(p);
                cout << result << endl;
                result = "";
            }
        }

        else if(primes.size() > k) {
            map<int, set<int>> differences;

            int dim = primes.size();
            int dist;
            for(int d=0; d<dim; d++) 
                for(int e=d+1; e<dim; e++) {
                    dist = primes[e] - primes[d]; 
                    differences[dist].insert(primes[d]);
                    differences[dist].insert(primes[e]);
                }
            
            for(auto d:differences) {
                if(d.second.size() < k) 
                    continue;
                if(d.second.size() == k) {
                    for(auto p : d.second)
                        result += to_string(p);
                    cout << result << endl;
                }
            }
        }

        primes.clear();
    }

    cerr << "reached end" << endl;

    return 0;
}
