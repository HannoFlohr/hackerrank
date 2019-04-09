#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1000000;
bool prime[MAXN+1];

//set prime array using sieve
void sieveOfEratosthenes(int n) {
    memset(prime, true, sizeof(prime));
    for(int p=2; p*p<=n; p++) {
        if(prime[p] == true) {
            for(int i=p*p; i<=n; i+=p) {
                prime[i] = false;
            }
        }
    }
}

//returns a vector with all rotations of a
vector<int> getRotations(const int &a) {
    vector<int> rotations (0);
    rotations.push_back(a);

    string s = to_string(a);
    int rots = s.size()-1;
    for(int i=0; i<rots; i++) {
        rotate(s.begin(), s.begin() + 1, s.end());
        rotations.push_back(stoi(s));
    }

    sort( rotations.begin(), rotations.end() );
    rotations.erase( unique( rotations.begin(), rotations.end() ), rotations.end() );
    return rotations;
}

int main() {
    sieveOfEratosthenes(MAXN);

    int n, sum=0, curSum;
    cin >> n;
    vector<int> rotations;

    bool isCircular;
    string number;
    for(int i=2; i<n; i++) { 
        if(!prime[i])
            continue;

        if(i<10) {
            sum += i;
            continue;
        }

        isCircular = true;
        curSum = 0;
        number = to_string(i);
        sort(number.begin(),number.end());
        
        rotations = getRotations(i);
        for(auto a:rotations) {
            if(!prime[a]) {
                isCircular = false;
                break;
            }
            curSum += a;
            prime[a] = false;
        } 

        if(isCircular) 
            sum += curSum; 
    }

    cout << sum << endl;
    return 0;
}
