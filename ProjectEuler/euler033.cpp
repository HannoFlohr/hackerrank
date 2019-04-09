#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

//converts n to string and adds leading zeroes
string toString(unsigned int n, unsigned int digits) {
    unsigned int digit;
    string number = "";
    while(digits--) {
        digit = n % 10;
        number += digit + '0';
        n /= 10;
    }
    reverse(number.begin(),number.end());
    return number;
}

//fill gaps in 'fill' with the numbers of 'digits'
unsigned int fillGaps(const string &fill, const string &digits) {
    string::const_iterator it = fill.begin();
    unsigned int result = 0;
    for(int i=0; i<digits.size(); i++) {
        result *= 10;
        if(digits[i] == '.')
            result += *it++ - '0';
        else
            result += digits[i] - '0';
    }
    return result;
}

int main() {
    unsigned int n, k, num, den, insert, curNum, curDen, value;
    cin >> n >> k;

    const vector<unsigned int> powers = {1,10,100,1000,10000}; // 10^i
    unsigned int sumNum = 0, sumDen = 0;
    const unsigned int remaining = n - k;
    string strNum, strDen, strIns, strInsNum, strInsDen;
    bool ascending;

    //helper to not count fractions twice
    unordered_set<unsigned int> fractions;

    for(den = 1; den < powers[remaining]; den++) {
        for(num = 1; num < den; num++) {
            strNum = toString(num,remaining);
            strDen = toString(den,remaining);

            //looü through all numbers that could be inserted
            for(insert = powers[k-1]; insert < powers[k]; insert++) {
                strIns = toString(insert,k);
                //digits of strIns must be ascending, or all its permutations were already checked
                ascending = true;
                for(int i=1; i<strIns.size(); i++) 
                    if(strIns[i-1] > strIns[i]) {
                        ascending = false;
                        break;
                    }
                if(!ascending) continue;

                strIns.insert(0, remaining, '.');
                strInsNum = strIns;
                strInsDen = strIns;
                
                //loop through all permutations for numerator
                do{
                    curNum = fillGaps(strNum,strInsNum);
                    if(curNum < powers[n-1])
                        continue;

                    //loop through all permutations for denominator
                    do {
                        curDen = fillGaps(strDen,strInsDen);

                        //fractions a/b and c/d are equal if a*d = b*c
                        if(curNum * den == curDen * num) {
                            value = curNum * 100000 + curDen;
                            //check if this fraction pair already occured
                            //if not: add to sums and insert into fractions
                            if(fractions.count(value) == 0) {
                                sumNum += curNum;
                                sumDen += curDen;
                                fractions.insert(value);
                            }
                        }
                    } while(next_permutation(strInsDen.begin(),strInsDen.end()));
                } while(next_permutation(strInsNum.begin(),strInsNum.end()));
            }
        }
    }

    cout << sumNum << " " << sumDen << endl;
    return 0;
}
