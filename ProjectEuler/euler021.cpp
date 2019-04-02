#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 100000;

int main() {
    bool prime [MAX_N+1];
    memset(prime, true, sizeof(prime));
    for(int p=2; p*p<=MAX_N; p++) {
        if(prime[p] == true) {
            for(int i=p*p; i<=MAX_N; i+=p) {
                prime[i] = false;
            }
        }
    }
    prime[0] = false;
    prime[1] = false;

    vector<int> primes (0);
    for(int i=2; i<=MAX_N; i++) 
        if(prime[i])
            primes.push_back(i);

    int amicable [MAX_N+1];
    int number, sum, index, power;
    for(int i=1; i<=MAX_N; i++) {
        if(prime[i]) {
            amicable[i] = 1;
            continue;
        }
        number = i;
        sum = 1;
        index = 0;
        while(number>1) {
            if(prime[number]) {
                sum *= number+1;
                break;
            }
            power = 0;
            while(number % primes[index] == 0) {
                number /= primes[index];
                power++;
            }
            sum *= (pow(primes[index],power+1)-1)/(primes[index]-1);
            index++;
        }
        amicable[i] = sum - i;
    }

    int t,n,i,amicableSum,ami;
    cin >> t; 
    while(t--) {
        cin >> n;
        i = 1;
        amicableSum = 0;
        while(i<n) {
            ami = amicable[i];
            if(ami <= MAX_N) 
                if(i==amicable[ami] && i!=ami)
                    amicableSum += i;
            i++;
        }
        cout << amicableSum << endl;
    } 
    return 0;
}
