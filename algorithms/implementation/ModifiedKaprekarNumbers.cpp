#include <bits/stdc++.h>

using namespace std;

void kaprekarNumbers(int p, int q) {
    string s, sub1, sub2;
    long d, cur, a, b, counter=0;
    for(long i=p; i<=q; i++) {
        d = (to_string(i)).size();

        cur = i*i;
        s = to_string(cur);
        if(s.size()==1) s = "0"+s;
        sub1 = s.substr(0,s.size()-d);
        sub2 = s.substr(s.size()-d,d);

        a = stoi(sub1);
        b = stoi(sub2);
        if(a+b == i) {cout << i << " "; counter++; }
    }
    if(counter==0) cout << "INVALID RANGE";
    cout << endl;
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
