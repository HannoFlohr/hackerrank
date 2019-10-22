#include <bits/stdc++.h>
using namespace std;

//returns the ascii value of char 'c'
int value(const char &c) {
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    return (int)c - 'A' + 10;
}

//converts the input number from given base 'b' to a decimal number
int toDecimal(std::string number, const int &base) {
    int result = 0, power = 1;
    for (int i = number.length() - 1; i >= 0; i--) {
        if (value(number[i]) >= base) {
            std::cerr << "Invalid number for base " << base << ": " << value(number[i]) << std::endl;
            return -1;
        }
        result += value(number[i]) * power;
        power *= base;
    }
    return result;
}

int main()
{
    int n, m, d;
    map<int,long> events;
    cin >> n;
    while(n--) {
        cin >> m >> d;    

        //convert to decimal if necessary
        if(m != 10) 
            d = toDecimal(to_string(d), m);
        
        //check for invalid results
        if(d == -1) continue;

        events[d]++;
    }

    long long int result = 0LL;
    for(auto e:events) 
        result += e.second * (e.second-1) / 2;

    cout << result << endl;
    return 0;
}
//https://www.hackerrank.com/challenges/jim-and-the-jokes/problem