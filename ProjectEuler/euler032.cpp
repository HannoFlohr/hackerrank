#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    unsigned int n, lengthA, lengthB, lengthC, a, b, c, pos, i;
    cin >> n;
    
    vector<unsigned int> digits;
    for(int i=1; i<=n; i++)
        digits.push_back(i);

    set<unsigned int> validProducts;

    //loop through all permutations
    do {
        for(lengthA = 1; lengthA < n; lengthA++) {
            for(lengthB = 1; lengthB < n - lengthA; lengthB++) {
                lengthC = n - lengthA - lengthB;

                if(lengthC < lengthA || lengthC < lengthB)
                    break;

                pos = 0;
                a = 0;
                for(i=1; i<=lengthA; i++) {
                    a *= 10;
                    a += digits[pos++];
                }
                b = 0;
                for(i=1; i<=lengthB; i++) {
                    b *= 10;
                    b += digits[pos++];
                }
                c = 0;
                for(i=1; i<=lengthC; i++) {
                    c *= 10;
                    c += digits[pos++];
                }

                if(a * b == c)
                    validProducts.insert(c);
            }
        }
    } while(next_permutation(digits.begin(), digits.end()));

    unsigned int sum = 0;
    for(auto v : validProducts)
        sum += v;
    cout << sum << endl;
    return 0;
}
