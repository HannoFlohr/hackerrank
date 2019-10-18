#include <bits/stdc++.h>
using namespace std;

const unsigned long int MAXN = 1e10;
vector<unsigned long int> fibos;

//computes the fibonacci numbers up to 'MAXN'
void makeFibos() {
    fibos.push_back(0UL);
    fibos.push_back(1UL);
    unsigned long int current = 1UL;
    unsigned int counter = 2;
    while(current <= MAXN) { 
        current = fibos[counter-2] + fibos[counter-1];
        fibos.push_back(current);
        counter++;
    }
}

int main()
{
    makeFibos();

    unsigned long int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if(find(fibos.begin(),fibos.end(),n) != fibos.end() ) 
            cout << "IsFibo" << endl;
        else 
            cout << "IsNotFibo" << endl;
    }

    return 0;
}
//https://www.hackerrank.com/challenges/is-fibo/problem